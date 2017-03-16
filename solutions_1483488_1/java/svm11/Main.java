import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("C-large.in"));
        PrintWriter out = new PrintWriter(new FileWriter("RecycledNumbers-Large.out"));

        RecycledNumbers solver = new RecycledNumbers();
        int testCases = in.nextInt();
        for (int i = 1; i <= testCases; ++i) {
            solver.solve(i, in, out);
        }

        in.close();
        out.close();
    }
}

class RecycledNumbers {
    int numberOfRecycledPairs(int A, int B) {
        int res = 0;
        boolean[] seen = new boolean[B + 1];
        for (int i = A; i <= B; ++i) {
            if (seen[i]) continue;
            int pairs = 0;
            char[] S = String.valueOf(i).toCharArray();
            for (int j = 0; j < S.length; ++j) {
                if (S[j] == '0') continue;
                int m = 0;
                for (int k = j; k < S.length; ++k) m = m * 10 + S[k] - '0';
                for (int k = 0; k < j; ++k) m = m * 10 + S[k] - '0';
                if (A <= m && m <= B && !seen[m]) {
                    seen[m] = true;
                    ++pairs;
                }
            }
            res += pairs * (pairs - 1) / 2;
        }
        return res;
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int A = in.nextInt();
        int B = in.nextInt();

        out.println("Case #" + testNumber + ": " + numberOfRecycledPairs(A, B));
    }
}
