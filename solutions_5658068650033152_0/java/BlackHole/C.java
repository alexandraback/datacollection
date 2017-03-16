package Round1C.C;

import java.io.*;
import java.util.*;
import java.util.stream.*;

public class C {
    public void solve(Scanner sc, PrintWriter pw) throws Exception {
        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();
        if (M < N) {
            int t = M;
            M = N;
            N = t;
        }

        if (N <= 2 || K <= 4) {
            pw.println(K);
        } else if (K >= N * M - 4) {
            int extra = K + 4 - N * M;
            int stone = (N - 2 + M - 2) * 2 + extra;
            pw.println(stone);
        } else if (N == 3) {
            int col = (K - 2) / 3;
            int extra = K - (2 + 3 * col);
            int stone = 2 + 2 * col + extra;
            pw.println(stone);
        } else if (N == 4) {
            int[] calc = new int[]{5, 6, 8, 10, 12, 14, 16};
            for (int i = 0; i < calc.length; i++) {
                if (calc[i] >= K) {
                    pw.println(4 + i);
                    return;
                }
            }
        }

    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileInputStream("C-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("C-small-attempt0.out"));
        C solver = new C();
        int T = sc.nextInt();
        for (int caseNum = 1; caseNum <= T; caseNum++) {
            System.out.println("Processing test case " + caseNum);
            pw.print("Case #" + caseNum + ": ");
            solver.solve(sc, pw);
        }
        pw.flush();
        pw.close();
    }
}