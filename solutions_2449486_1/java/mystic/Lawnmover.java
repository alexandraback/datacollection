package contest;

import java.util.*;
import java.io.*;

public class Lawnmover {
    final static String PROBLEM_NAME = "lawn";
    final static String WORK_DIR = "D:\\Gcj\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt(), M = sc.nextInt();
        int[][] A = new int[N][M];
        int[] maxRow = new int[N];
        int[] maxCol = new int[M];
        for (int i=0; i<N; i++) for (int j=0; j<M; j++) {
            A[i][j] = sc.nextInt();
            maxRow[i] = Math.max(maxRow[i], A[i][j]);
            maxCol[j] = Math.max(maxCol[j], A[i][j]);
        }
        boolean ok = true;
        for (int i=0; i<N; i++) for (int j=0; j<M; j++) ok &= A[i][j] == Math.min(maxRow[i], maxCol[j]);
        pw.println(ok ? "YES" : "NO");
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Lawnmover().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
