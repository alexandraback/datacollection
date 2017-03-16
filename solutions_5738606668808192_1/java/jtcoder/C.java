package com.google2016.qual;

import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class C {

    static final String FILENAME = "c:\\Users\\Admin\\Downloads\\C-large";
    static final String IN = FILENAME + ".in";

    Scanner sc;
    static final String OUT = FILENAME + ".out";
    PrintStream out = System.out;

    private BigInteger findDivisor(String number, int n) {
        BigInteger numberInBase = new BigInteger(number, n);
        int limit = 100000;
        if (!numberInBase.isProbablePrime(1)) {
            BigInteger incrementer = BigInteger.valueOf(1);
            if (numberInBase.mod(BigInteger.valueOf(2)) != BigInteger.ZERO) {
                incrementer = BigInteger.valueOf(2);
            }

            int count = 0;
            for (BigInteger i = new BigInteger("3"); numberInBase.divide(BigInteger.valueOf(2)).compareTo(i) >= 0; i = i.add(incrementer)) {
                if (numberInBase.mod(i).equals(BigInteger.ZERO)) {
                    return i;
                }
                count++;
                if (limit < count)
                    return null;

            }
        }
        return null;
    }

    private Map<String, List<BigInteger>> solve(int n, int j) {
        Map<String, List<BigInteger>> jamCoins = new HashMap<>();

        do {
            String number = generateJamCoinCandidate(n);
            List<BigInteger> divisors = new ArrayList<>();
            for (int i = 2; i <= 10; i++) {
                BigInteger div = findDivisor(number, i);
                if (div != null) {
                    divisors.add(div);
                    //System.out.println("Found " + number + "[" + new BigInteger(number, i) + "]" + " base " + i + " divisor " + div);
                } else {
                    continue;
                }
                if (divisors.size() == 9) {
                    jamCoins.put(number, divisors);
                }
            }
        } while (jamCoins.size() != j);
        return jamCoins;
    }

    private String generateJamCoinCandidate(int n) {
        String jamcoinCandidate = "1";
        for (int i = 1; i < n - 1; i++) {
            Random random = new Random();
            if (random.nextBoolean()) {
                jamcoinCandidate = jamcoinCandidate + "1";
            } else {
                jamcoinCandidate = jamcoinCandidate + "0";
            }
        }
        return jamcoinCandidate + "1";

    }

    private void run() throws Exception {
        sc = new Scanner(new File(IN));
        out = new PrintStream(new FileOutputStream(OUT));
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            int n = sc.nextInt();
            int j = sc.nextInt();
            Map<String, List<BigInteger>> jamCoins = solve(n, j);
            out.println("Case #" + i + ":");
            for (String jamCoin : jamCoins.keySet()) {
                out.print(jamCoin);
                for (BigInteger divisor : jamCoins.get(jamCoin)) {
                    out.print(" " + divisor);
                }
                out.println();
            }
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new C().run();
    }

}

