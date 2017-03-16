import java.util.*;
import java.io.*;
import java.math.*;

public class Pancakes {
    final static String PROBLEM_NAME = "pancakes";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int[] A = new int[N];
        int max = 0;
        for (int i=0; i < N; i++) {
            A[i] = sc.nextInt();
            max = Math.max(max, A[i]);
        }

        int ans = max;
        for (int eats = 1; eats <= max; eats++) {
            int tmp = eats;
            for (int i = 0; i < N; i++) {
                tmp += (A[i] - 1) / eats;
            }
            ans = Math.min(ans, tmp);
        }

        pw.println(ans);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Pancakes().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
