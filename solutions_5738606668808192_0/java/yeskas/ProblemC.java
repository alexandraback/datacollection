package com.company;

import java.io.File;
import java.io.PrintWriter;
import java.math.*;
import java.util.*;

public class ProblemC {

    public static String PROBLEM_LETTER = "C";

    public static String IN_DIR = "inputs/" + PROBLEM_LETTER + "/";
    public static String OUT_DIR = "outputs/" + PROBLEM_LETTER + "/";

//    public static String IN_FILE = IN_DIR + "sample.in";
    public static String IN_FILE = IN_DIR + "C-small-attempt0.in";
//    public static String IN_FILE = IN_DIR + "B-large.in";

//    public static String OUT_FILE = OUT_DIR + "sample.out";
    public static String OUT_FILE = OUT_DIR + "small.out";
//    public static String OUT_FILE = OUT_DIR + "large.out";



    public static void pr(int num) {
        System.out.print(Integer.toString(num));
    }
    public static void pr(String str) {
        System.out.print(str);
    }

    public static void prln(int num) {
        System.out.println(Integer.toString(num));
    }
    public static void prln(String str) {
        System.out.println(str);
    }



    public static void handleCase(int caseNum, PrintWriter wr, int N, int J) {
        wr.println("Case #" + caseNum + ":");
        int halfLen = N/2;

        int div = (1 << halfLen) + 1;
        String binDiv = Integer.toBinaryString(div);
        String[] allDivs = new String[9];
        for (int r = 0; r < 9; r++) {
            int radix = r + 2;
            BigInteger bi = new BigInteger(binDiv, radix);
            allDivs[r] = bi.toString();
        }

        int base = (1 << (halfLen-1)) + 1;
        for (int i = 0; i < J; i++) {
            int half = base + (i << 1);
            String binHalf = Integer.toBinaryString(half);
            wr.print(binHalf + binHalf);
            for (int r = 0; r < 9; r++) {
                wr.print(" " + allDivs[r]);
            }
            wr.println();
        }
    }



    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File(IN_FILE));
            PrintWriter wr = new PrintWriter(OUT_FILE);

            int T = sc.nextInt();
            int N = sc.nextInt();
            int J = sc.nextInt();

            for (int i = 0; i < T; i++) {
                handleCase(i+1, wr, N, J);
            }

            wr.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
