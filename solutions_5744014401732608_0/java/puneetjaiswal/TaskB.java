package pkj;

import java.util.Scanner;
import java.io.PrintWriter;

public class TaskB {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        String POSSIBLE = "POSSIBLE";
        String IMPOSSIBLE = "IMPOSSIBLE";
        out.print("Case #" + testNumber + ": ");
        int B = in.nextInt();
        long M = in.nextLong();

        long totalPossible = 1L << (B - 2);
        if (M > totalPossible) {
            out.println(IMPOSSIBLE);
            return;
        }

        int[][] boolArr = new int[B][B];
        for (int i = 0; i < B - 1; ++i) {
            for (int j = i + 1; j < B; ++j) {
                boolArr[i][j] = 1;
            }
        }

        long len = totalPossible - M;
        for (int i = 0; i < B; ++i) {
            if (((len >> i) & 1) == 1) {
                boolArr[i + 1][B - 1] = 0;
            }
        }

        out.println(POSSIBLE);
        for (int i = 0; i < B; ++i) {
            String result = "";
            for (int j = 0; j < B; ++j) {
                result += boolArr[i][j];
            }
            out.println(result);
        }
    }
}
