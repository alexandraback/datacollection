package com.company;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class ProblemD {

    public static String PROBLEM_LETTER = "D";

    public static String IN_DIR = "inputs/" + PROBLEM_LETTER + "/";
    public static String OUT_DIR = "outputs/" + PROBLEM_LETTER + "/";

//    public static String IN_FILE = IN_DIR + "sample.in";
    public static String IN_FILE = IN_DIR + "D-small-attempt0.in";
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



    public static void handleCase(int caseNum, PrintWriter wr, int K, int C, int S) {
        wr.print("Case #" + caseNum + ":");
        for (int i = 0; i < K; i++) {
            int pos = i + 1;
            wr.print(" " + pos);
        }
        wr.println();
    }



    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File(IN_FILE));
            PrintWriter wr = new PrintWriter(OUT_FILE);

            int T = sc.nextInt();

            for (int i = 0; i < T; i++) {
                int K = sc.nextInt();
                int C = sc.nextInt();
                int S = sc.nextInt();

                handleCase(i+1, wr, K, C, S);
            }

            wr.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
