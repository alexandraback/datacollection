import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        String input = "Input.in";
        String smallAttempt0 = "A-small-attempt0.in";
        String smallAttempt1 = "A-small-attempt1.in";
        String smallAttempt2 = "A-small-attempt2.in";
        String largeAttempt = "A-large.in";

        String output = "Output.out";

        Scanner in = new Scanner(new FileReader(smallAttempt2));
        PrintWriter out = new PrintWriter(new FileWriter(output));

        Task solver = new Task();
        int testCases = in.nextInt();
        for (int i = 1; i <= testCases; ++i)
            solver.solve(i, in, out);

        in.close();
        out.close();
    }
}

class Task {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        double[] s = new double[n];
        double x = 0.0;
        for (int i = 0; i < n; ++i) {
            s[i] = in.nextDouble();
            x = x + s[i];
        }

        double[] res = new double[n];
        for (int i = 0; i < n; ++i) {
            double lo = 0.0, hi = 1.0, mid, eps = 1e-8;
            while (lo + eps < hi) {
                mid = (lo + hi) / 2.0;

                double left = 1 - mid;
                boolean ok = true;
                for (int j = 0; j < n; ++j) {
                    if (i == j) continue;
                    double assign = mid + (s[i] - s[j]) / x;
                    if (assign < 0) continue;
                    if (left + eps < assign) {
                        ok = false;
                        break;
                    }
                    left -= assign;
                }

                if (ok) lo = mid;
                else hi = mid;
            }
            res[i] = 100.0 * lo;
        }

        out.print("Case #" + testNumber + ":");
        for (int i = 0; i < n; ++i)
            out.printf(" %.6f", res[i]);
        out.println();
    }
}
