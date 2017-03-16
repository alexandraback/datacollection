package gcj2015_Qualification;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class B {

    static Scanner in;
//    static String taskname = "B-small";
//    static String taskname = "B-small-attempt0";
//    static String taskname = "B-small-attempt1";
    static String taskname = "B-large";
//    static String taskname = "B-small-practice";

    public static String solve() {
        int D = in.nextInt();
        int[] P = new int[D];
        int max = 0;
        for (int i = 0; i < D; i++) {
            P[i] = in.nextInt();
            if (max < P[i]) max = P[i];
        }

        // lets left on each plate j or less pancakes
        int best = max;
        for (int j = 1; j < max; j++) {
            int specialMinutes = 0;
            for (int i=0; i<D; i++) {
                specialMinutes += (P[i] - 1)/j;
            }
            int total = specialMinutes + j;
            if ( best > total ) best = total;
        }

        return "" + best;
    }


    public static void main(String[] args) {
        try {
            PrintWriter pW = new PrintWriter(new FileOutputStream("output/"
                    + taskname + ".out"));
            try {
                in = new Scanner(new FileInputStream("input/"
                        + taskname + ".in"));
                int T = in.nextInt();
                for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
                    pW.println("Case #" + caseNumber + ": " + solve());
                }
                in.close();
                pW.close();
            } catch (IOException e) {
                System.out.println("Can not find file " + taskname + ".in");
            }
        } catch (IOException e) {
            System.out.println("Open or create exception with "
                    + taskname + ".out");
        }
    }
}

