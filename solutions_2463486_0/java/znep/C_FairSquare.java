package contests.Qualification2013;

import contests.Util;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class C_FairSquare extends Util {
    private static boolean isPalindrome(String s) {
        int len = s.length();
        for (int i = 0; i < len / 2; i++) {
            if (s.charAt(i) != s.charAt(len - i - 1)) return false;
        }
        return true;

    }

    public static void main(String args[]) throws IOException {
        List<Integer> perfectPalindromes = new ArrayList<Integer>();

        for (int i = 0; i <= Math.sqrt(10E14); i++) {
            String si = Integer.toString(i);
            if (isPalindrome(si)) {
                int ii = i*i;
                String sii = Integer.toString(ii);
                if (isPalindrome(sii)) {
                    debug("perfect palindrome " + ii);
                    perfectPalindromes.add(ii);
                }
            }
        }
//
//        for (BigInteger i = BigInteger.ZERO; i.compareTo(new BigInteger("0")) >= 0; i = i.add(BigInteger.ONE)) {
//            String si = i.toString();
//            if (isPalindrome(si)) {
//                BigInteger ii = i.multiply(i);
//                String sii = ii.toString();
//                if (isPalindrome(sii)) {
//                    System.out.println("perfect palindrome " + sii);
//                }
//            }
//        }

        String inputFileName = "src/contests/Qualification2013/C-sample.in";
        if (args.length == 1) inputFileName = args[0];

        BufferedReader in = new BufferedReader(new FileReader(inputFileName));

        int numTestCases = Integer.parseInt(in.readLine());
        debug("Processing " + numTestCases + " test cases");
        for (int testCase = 1; testCase <= numTestCases; testCase = testCase + 1) {
            debug("Starting case " + testCase);
            Integer[] bounds = readIntArrayLine(in);
            int lower = bounds[0];
            int higher = bounds[1];

            int count = 0;
            // laaaazy
            for (int i : perfectPalindromes) {
                if (i >= lower && i <= higher) count++;
            }

            System.out.println("Case #" + testCase + ": " + count);
        }

    }


}
