package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class GoodLuckSmall {
    final static String PROBLEM_NAME = "GLSmall";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    static int getProb(int prod, int A1, int A2, int A3) {
        int res = 0;
        if (prod==1) res++;
        if (prod==A1) res++;
        if (prod==A2) res++;
        if (prod==A3) res++;
        if (prod==A1*A2) res++;
        if (prod==A1*A3) res++;
        if (prod==A2*A3) res++;
        if (prod==A1*A2*A3) res++;
        return res;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int T = sc.nextInt();
        int R = sc.nextInt(), N = sc.nextInt(), M = sc.nextInt(), K = sc.nextInt();
        pw.println("Case #1:");
        for (int r = 0; r < R; r++) {
            int[] prod = new int[K];
            for (int k=0; k < K; k++) prod[k] = sc.nextInt();
            int maxProb = 0;
            String ans = "222";
            for (int A1=2; A1<=M; A1++) for (int A2=2; A2<=M; A2++) for (int A3=2; A3<=M; A3++) {
                int prob = 1;
                for (int k=0; k < K; k++) prob *= getProb(prod[k], A1, A2, A3);
                if (prob > maxProb) {
                    maxProb = prob;
                    ans = "" + A1 + "" + A2 + "" + A3;
                }
            }
            pw.println(ans);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
