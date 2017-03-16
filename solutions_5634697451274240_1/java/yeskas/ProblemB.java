package com.company;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class ProblemB {

    public static String PROBLEM_LETTER = "B";

    public static String IN_DIR = "inputs/" + PROBLEM_LETTER + "/";
    public static String OUT_DIR = "outputs/" + PROBLEM_LETTER + "/";

//    public static String IN_FILE = IN_DIR + "sample.in";
//    public static String IN_FILE = IN_DIR + "B-small-attempt0.in";
    public static String IN_FILE = IN_DIR + "B-large.in";

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



    public static void handleCase(int caseNum, PrintWriter wr, String line) {
        wr.print("Case #" + caseNum + ": ");
        int numSegs = 1;
        char curSeg = line.charAt(0);

        for (int i = 1; i < line.length(); i++) {
            char ch = line.charAt(i);
            if (ch == curSeg) {
                // nothing
            } else {
                numSegs++;
                curSeg = ch;
            }
        }

        char lastSeg = line.charAt(line.length() - 1);
        if (lastSeg == '+') {
            wr.println(numSegs - 1);
        } else {
            wr.println(numSegs);
        }
    }



    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File(IN_FILE));
            PrintWriter wr = new PrintWriter(OUT_FILE);

            int T = sc.nextInt();
            String ignoreMe = sc.nextLine();

            for (int i = 0; i < T; i++) {
                String next = sc.nextLine();
                prln("next is ###" + next + "###");
                handleCase(i+1, wr, next);
            }

            wr.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
