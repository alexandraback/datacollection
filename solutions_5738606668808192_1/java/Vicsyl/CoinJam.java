package org.virutor;

import java.io.IOException;
import java.math.BigInteger;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class CoinJam {

    /**
     * - any jamcoin would yeild even number in odd base,
     * i.e. (jc) -> (2)? , (3)2, (4)?, (5)2, (6)?, (7)2, (8)?, (9)2, (10)?
     */

    public static void main(String[] args) {

        try (Stream<String> ln = Files.lines(Paths.get(args[0]))) {

            String[] lines = ln.toArray(String[]::new);

            int cases = Integer.parseInt(lines[0].trim());
            for (int i = 1; i < cases + 1; i++) {
                String[] params = lines[i].split(" ");
                int length = Integer.parseInt(params[0]);
                int number = Integer.parseInt(params[1]);
                solveAndPrint(length, number, i);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    private static void solveAndPrint(int length, int number, int cs) {

        System.out.println("Case #" + cs + ":");

        StringBuffer sb = new StringBuffer("1");
        for (int i = 1; i < length - 1; i++) {
            sb.append("0");
        }
        sb.append("1");
        String xStr = sb.toString();
        BigInteger base2 = new BigInteger(xStr, 2);
        int found = 0;

        while (found < number) {

            if (ones(xStr) % 2 == 0 && base2.mod(BigInteger.valueOf(3)).longValue() == 0) {
                BigInteger base4 = new BigInteger(xStr, 4);
                if (base4.mod(BigInteger.valueOf(3)).longValue() == 0) {
                    System.out.println(xStr + " 3 2 3 2 7 2 3 2 3");
                    found++;
                    check(xStr);
                }
            }

            base2 = base2.add(BigInteger.valueOf(2));
            xStr = base2.toString(2);

        }

    }

    private static int ones(String s) {
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                ret++;
            }
        }
        return ret;
    }

    private static void check(String xStr) {
        int baseDivisors[] = new int[]{0, 0, 3, 2, 3, 2, 7, 2, 3, 2, 3};
        BigInteger[] biDiv = new BigInteger[11];

        for (int i = 0; i < 11; i++) {
            biDiv[i] = BigInteger.valueOf(baseDivisors[i]);
        }

        for (int i = 2; i < 11; i++) {
            BigInteger l = new BigInteger(xStr, i);
            if (l.mod(biDiv[i]).longValue() != 0) {
                throw new RuntimeException(xStr + "_" + i + " = " + l + " not divisible by " + baseDivisors[i] + " with modulo " + (i % baseDivisors[i]));
            }

        }
    }

}
