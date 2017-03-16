package com.company;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class ProblemD {

    public static String PROBLEM_LETTER = "D";

    public static String IN_DIR = "inputs/" + PROBLEM_LETTER + "/";
    public static String OUT_DIR = "outputs/" + PROBLEM_LETTER + "/";

//    public static String IN_FILE = IN_DIR + "sample.in";
//    public static String IN_FILE = IN_DIR + "D-small-attempt0.in";
    public static String IN_FILE = IN_DIR + "D-large.in";

//    public static String OUT_FILE = OUT_DIR + "sample.out";
//    public static String OUT_FILE = OUT_DIR + "small.out";
    public static String OUT_FILE = OUT_DIR + "large.out";



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



    public static long mypow(long base, int po) {
        long res = 1L;
        for (int i = 0; i < po; i++) {
            res *= base;
        }
        return res;
    }

    public static long getPointerNum(long K, List<Long> coefs) {
        int len = coefs.size();

        long res = 0L;
        for (int i = 0; i < len; i++) {
            res += coefs.get(i) * mypow(K, i);
        }
        return res;
    }



    public static void handleCase(int caseNum, PrintWriter wr, long K, long C, long S) {
        wr.print("Case #" + caseNum + ":");
        if (S*C < K) {
            wr.println(" IMPOSSIBLE");
            return;
        }

        if (C >= K) {
            List<Long> coefs = new ArrayList<Long>();
            for (long i = 0L; i < K; i++) {
                coefs.add(i);
            }
            long pointerNum = getPointerNum(K, coefs);
            wr.println(" " + (pointerNum+1));
            return;
        }

        long covered = 0L;
        while(covered < K) {
            List<Long> coefs = new ArrayList<Long>();
            for (long i = 0L; i < C; i++) {
                coefs.add(covered);
                covered++;
                if (covered == K) {
                    break;
                }
            }

            long pointerNum = getPointerNum(K, coefs);
            wr.print(" " + (pointerNum+1));
        }
        wr.println();
    }



    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File(IN_FILE));
            PrintWriter wr = new PrintWriter(OUT_FILE);

            int T = sc.nextInt();

            for (int i = 0; i < T; i++) {
                long K = sc.nextLong();
                long C = sc.nextLong();
                long S = sc.nextLong();

                handleCase(i+1, wr, K, C, S);
            }

            wr.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
