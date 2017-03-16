package contest;

import java.util.*;
import java.io.*;
import java.math.*;

public class DeceitfulWar {
    final static String PROBLEM_NAME = "deceitful";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    int solve(double[] A, double[] B) {
        int pos = 0;
        for (double elm : A) {
            if (elm > B[pos]) {
                pos++;
            }
        }
        return pos;
    }

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        double[] naomi = new double[N];
        double[] ken = new double[N];
        for (int i=0; i < N; i++) {
            naomi[i] = Double.parseDouble(sc.next());
        }
        for (int i=0; i < N; i++) {
            ken[i] = Double.parseDouble(sc.next());
        }
        Arrays.sort(naomi);
        Arrays.sort(ken);
        pw.println(solve(naomi, ken) + " " + (N - solve(ken, naomi)));
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new DeceitfulWar().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
