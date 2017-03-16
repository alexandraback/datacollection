package com.cristizmf.googlecodejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;

/**
 * Created by crist on 4/9/2016.
 * <p/>
 * https://code.google.com/codejam/contest/6254486/dashboard
 */
public class CountingSheep {

    private static void markDigits(BigInteger n, HashSet<Character> digits) {
        String nStr = n.toString();
        for (int i = 0; i < nStr.length(); i++) {
            digits.remove(nStr.charAt(i));
        }
    }

    private static BigInteger getSleep(int n) {
        HashSet<BigInteger> visitedNumbers = new HashSet<BigInteger>();
        HashSet<Character> digitsLeft = new HashSet<Character>();
        digitsLeft.add('0');
        digitsLeft.add('1');
        digitsLeft.add('2');
        digitsLeft.add('3');
        digitsLeft.add('4');
        digitsLeft.add('5');
        digitsLeft.add('6');
        digitsLeft.add('7');
        digitsLeft.add('8');
        digitsLeft.add('9');

        BigInteger numberN = new BigInteger(String.valueOf(n));
        int i = 0;
        while (!digitsLeft.isEmpty()) {
            i++;
            BigInteger nTest = numberN.multiply(new BigInteger(String.valueOf(i)));
            if (visitedNumbers.contains(nTest)) {
                return BigInteger.ZERO;
            }
            markDigits(nTest, digitsLeft);
            if (digitsLeft.isEmpty()) {
                return nTest;
            }
            visitedNumbers.add(nTest);

        }
        return BigInteger.ZERO;
    }

    public static void main(String[] args) throws FileNotFoundException {
        final int INPUT_FILE_NUMBER = 3;
        Scanner scanner = new Scanner(new File("C:\\dev\\Projects\\algorithms\\TestCases\\CountingSheep\\input" + INPUT_FILE_NUMBER + ".txt"));
        PrintWriter printWriter = new PrintWriter(new File("C:\\dev\\Projects\\algorithms\\TestCases\\CountingSheep\\output" + INPUT_FILE_NUMBER + ".txt"));
        int tc = scanner.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = scanner.nextInt();
            BigInteger result = getSleep(n);
            if (result == BigInteger.ZERO) {
                printWriter.println("Case #" + (t + 1) + ": INSOMNIA");
            } else {
                printWriter.println("Case #" + (t + 1) + ": " + result.toString());
            }
        }
        printWriter.flush();
        printWriter.close();
    }
}
