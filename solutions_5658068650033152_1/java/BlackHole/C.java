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
        } else if (N >= 4) {
            int p = 0, q = 0, r = K + 4;
            if (r > N * N) {
                p = N;
                q = r / N;
            } else {
                q = (int) Math.sqrt(r);
                if (r >= q * (q + 1)) {
                    p = q + 1;
                } else {
                    p = q;
                }
            }
            int extra = r - p * q;
            int currentStone = 2 * (p + q - 4);
            int stone = currentStone;
            if (extra == 0) {
                stone += 0;
            } else if (extra <= p - 2) {
                stone += 1;
            } else if (extra <= p) {
                stone += 2;
            } else {
                throw new Error("Edge case!");
            }
            pw.println(stone);
        }

    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileInputStream("C-large.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("C-large.out"));
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