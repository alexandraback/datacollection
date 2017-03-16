package com.company;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class ProblemA {

    public static String PROBLEM_LETTER = "A";

    public static String IN_DIR = "inputs/" + PROBLEM_LETTER + "/";
    public static String OUT_DIR = "outputs/" + PROBLEM_LETTER + "/";

//    public static String IN_FILE = IN_DIR + "sample.in";
//    public static String IN_FILE = IN_DIR + "A-small-attempt0.in";
    public static String IN_FILE = IN_DIR + "A-large.in";

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



    private static void addNewDigs(int nk, Set<Integer> digsSeen) {
        String nkstr = Integer.toString(nk);
        for (int i = 0; i < nkstr.length(); i++) {
            char ch = nkstr.charAt(i);
            int dig = ch - '0';
            digsSeen.add(dig);
        }
    }



    public static void handleCase(int caseNum, PrintWriter wr, int N) {
        wr.print("Case #" + caseNum + ": ");
        if (N == 0) {
            wr.println("INSOMNIA");
            return;
        }


        Set<Integer> digsSeen = new HashSet<Integer>(10);
        int NK = 0;
        while(digsSeen.size() < 10) {
            NK += N;
            addNewDigs(NK, digsSeen);
        }

        wr.println(NK);
    }



    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File(IN_FILE));
            PrintWriter wr = new PrintWriter(OUT_FILE);

            int T = sc.nextInt();
            for (int i = 0; i < T; i++) {
                int next = sc.nextInt();
                handleCase(i+1, wr, next);
            }

            wr.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
