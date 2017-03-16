package ru.abishev.qual;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class C {
    public static void run(Scanner input, PrintWriter output) {
        int t = input.nextInt();
        input.nextLine();
        for (int _t = 0; _t < t; _t++) {
            String line = input.nextLine();
            BigInteger a = new BigInteger(line.split(" ")[0]), b = new BigInteger(line.split(" ")[1]);
            // find from a to b square palindromes

            BigInteger sqrtA = sqrt(a);
            if (!sqrtA.multiply(sqrtA).equals(a)) {
                sqrtA = sqrtA.add(BigInteger.ONE);
            }
            BigInteger sqrtB = sqrt(b);

            System.out.println(_t);

            output.println("Case #" + (_t + 1) + ": " + calc(sqrtA, sqrtB));
        }
        output.flush();
    }

    private static BigInteger calc(BigInteger begin, BigInteger end) {
        // find all polindromes between {begin} and {end} sum of digits < 10;
        if (begin.compareTo(end) > 0) {
            return BigInteger.ZERO;
        }

        // who is it?
        int result = 0;
        for (int i = begin.intValue(); i <= end.intValue(); i++) {
            if (isOkSqrt(i)) {
                result++;
            }
        }

        return BigInteger.valueOf(result);
    }

    // result*result <= value
    private static BigInteger sqrt(BigInteger value) {
        BigInteger low = BigInteger.ONE;
        BigInteger high = value.add(BigInteger.ONE);
        // low <= result < high
        // while high - low > 1
        while (high.subtract(low).compareTo(BigInteger.ONE) > 0) {
            BigInteger middle = high.add(low).divide(BigInteger.valueOf(2));
            if (middle.multiply(middle).compareTo(value) <= 0) {
                low = middle;
            } else {
                high = middle;
            }
        }
        if (high.multiply(high).compareTo(value) <= 0) {
            return high;
        } else {
            return low;
        }
    }

    private static boolean isPol(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    private static boolean isOkSqrt(int val) {
        String s = String.valueOf(val);
        if (!isPol(s)) {
            return false;
        }
        int sum = 0;
        for (char c : s.toCharArray()) {
            sum += (c - '0') * (c - '0');
        }
        return sum < 10;
    }

    public static void main(String[] args) throws FileNotFoundException {
//        run(new Scanner(System.in), new PrintWriter(System.out));

//        String fileName = "C-small-attempt0";
//        PrintWriter output = new PrintWriter(new FileOutputStream("./" + fileName + ".out"));
//        run(new Scanner(new FileInputStream("./" + fileName + ".in")), output);
//        output.close();

        String fileName = "C-large-1";
        PrintWriter output = new PrintWriter(new FileOutputStream("./" + fileName + ".out"));
        run(new Scanner(new FileInputStream("./" + fileName + ".in")), output);
        output.close();

//        String fileName = "C-large2";
//        PrintWriter output = new PrintWriter(new FileOutputStream("./" + fileName + ".out"));
//        run(new Scanner(new FileInputStream("./" + fileName + ".in")), output);
//        output.close();
    }
}
