package com.google.codejam;

import static org.apache.commons.lang.StringUtils.rightPad;

import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

import com.google.common.collect.Lists;
import com.google.common.collect.Maps;

//Libraries used: http://commons.apache.org/lang/, http://commons.apache.org/collections/, https://code.google.com/p/guava-libraries/
public class C {
    private static boolean debugAllowed = true;
    static Map<BigInteger, BigInteger> squares = Maps.newTreeMap();
    static List<String> palsOddClass1 = Lists.newArrayList();
    static List<String> palsOddClass2 = Lists.newArrayList();
    static List<String> palsOddClass3 = Lists.newArrayList();
    static List<String> palsEvenClass1 = Lists.newArrayList();
    static List<String> palsEvenClass2 = Lists.newArrayList();
    static {
        long startTime = System.currentTimeMillis();
        palsOddClass1.add("0");
        palsOddClass1.add("1");
        palsOddClass1.add("2");
        palsOddClass3.add("3");
        palsEvenClass1.add("11");
        palsEvenClass2.add("22");

        int maxLength = 51;
        for (int length = 3; length <= maxLength; length++) {
            if (length % 2 == 0) {
                List<String> newPals;

                newPals = Lists.newArrayList();
                newPals.add("1" + rightPad("0", length - 2, '0') + "1");
                for (String pal : palsEvenClass1) {
                    String newPal = "1" + pad(pal, length - 2) + "1";
                    if (isPal(square(newPal).toString())) {
                        newPals.add(newPal);
                    }
                }
                palsEvenClass1.addAll(newPals);
                newPals = Lists.newArrayList();
                newPals.add("2" + rightPad("0", length - 2, '0') + "2");
                palsEvenClass2.addAll(newPals);
            } else {
                List<String> newPals;

                newPals = Lists.newArrayList();
                for (String pal : palsOddClass1) {
                    String newPal = "1" + pad(pal, length - 2) + "1";
                    if (isPal(square(newPal).toString())) {
                        newPals.add(newPal);
                    }
                }
                palsOddClass1.addAll(newPals);

                newPals = Lists.newArrayList();
                for (int pal = 0; pal <= 1; pal++) {
                    String newPal = "2" + pad(String.valueOf(pal), length - 2) + "2";
                    if (isPal(square(newPal).toString())) {
                        newPals.add(newPal);
                    }
                }
                palsOddClass2.addAll(newPals);
            }
        }

        squares.putAll(fairAndSquaresFor(palsOddClass1));
        squares.putAll(fairAndSquaresFor(palsOddClass2));
        squares.putAll(fairAndSquaresFor(palsOddClass3));
        squares.putAll(fairAndSquaresFor(palsEvenClass1));
        squares.putAll(fairAndSquaresFor(palsEvenClass2));
        //        Collections.sort(squares);
        for (BigInteger pal : squares.keySet()) {
            debug(pal + " -> " + squares.get(pal));
        }
        long time = System.currentTimeMillis() - startTime;
        debug("Time: " + time + " ms (" + time / maxLength + " ms / length)");
    }

    private static String pad(String pal, int length) {
        String paddedPal = pal;
        while (paddedPal.length() != length) {
            paddedPal = "0" + paddedPal + "0";
        }
        return paddedPal;
    }

    private static Map<BigInteger, BigInteger> fairAndSquaresFor(List<String> pals) {
        Map<BigInteger, BigInteger> result = Maps.newTreeMap();
        for (String pal : pals) {
            BigInteger square = square(pal);
            if (isPal(square.toString())) {
                result.put(new BigInteger(pal), square);
            }
        }
        return result;
    }

    private static BigInteger square(String pal) {
        return new BigInteger(pal).multiply(new BigInteger(pal));
    }

    static boolean isPal(String s) {
        return isPal(s, 0, s.length() - 1);
    }

    static boolean isPal(String s, int i, int j) {
        return j - i < 1 || s.charAt(i) == s.charAt(j) && isPal(s, i + 1, j - 1);
    }

    private static String solve(int caseNumber, Scanner scanner) {
        BigInteger A = scanner.nextBigInteger();
        BigInteger B = scanner.nextBigInteger();
        int count = 0;
        for (BigInteger square : squares.values()) {
            if (square.compareTo(A) >= 0 && square.compareTo(B) <= 0) {
                count++;
            }
        }
        return String.valueOf(count);
    }

    public static void main(String[] args) throws Exception {
        if (args.length != 1) {
            throw new IllegalArgumentException("Wrong run parameters: " + Arrays.deepToString(args));
        }
        File inputFile = new File(args[0]);
        String outputFileName = inputFile.getParent() + File.separator + inputFile.getName().replace(".in", ".out");
        PrintStream out = new PrintStream(outputFileName);

        Scanner scanner = new Scanner(inputFile);
        int numberOfCases = Integer.valueOf(scanner.nextLine());
        debug(numberOfCases + " cases");

        long startTime = System.currentTimeMillis();
        for (int caseNumber = 1; caseNumber <= numberOfCases; caseNumber++) {
            // Parsing the file
            debug("Case #" + caseNumber);

            // Now solving

            String result = solve(caseNumber, scanner);
            String resultString = "Case #" + caseNumber + ": " + result;
            out.println(resultString);
            debug("Solution for " + resultString);

            debug("");
        }
        long time = System.currentTimeMillis() - startTime;
        debug("Time: " + time + " ms (" + time / numberOfCases + " ms / case)");

        out.close();
    }

    private static void debug(String text) {
        if (debugAllowed) {
            System.out.println(text);
        }
    }
}
