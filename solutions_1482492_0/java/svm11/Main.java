import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        String input = "Input.in";
        String smallAttempt0 = "B-small-attempt0.in";
        String smallAttempt1 = "B-small-attempt1.in";
        String smallAttempt2 = "B-small-attempt2.in";
        String smallAttempt3 = "B-small-attempt3.in";
        String largeAttempt = "B-large.in";

        String output = "Output.out";

        Scanner in = new Scanner(new FileReader(smallAttempt0));
        PrintWriter out = new PrintWriter(new FileWriter(output));

        Task solver = new Task();
        int testCases = in.nextInt();
        for (int i = 1; i <= testCases; ++i) {
            solver.readInput(in);
            solver.solve();
            solver.printOutput(i, out);
        }

        in.close();
        out.close();
    }
}

class Task {
    double d;
    int n;
    int m;
    double[] t;
    double[] x;
    double[] a;
    double[] res;

    public Task() {

    }

    public void readInput(Scanner in) {
        d = in.nextDouble();
        n = in.nextInt();
        m = in.nextInt();
        t = new double[n];
        x = new double[n];
        for (int i = 0; i < n; ++i) {
            t[i] = in.nextDouble();
            x[i] = in.nextDouble();
        }
        a = new double[m];
        for (int i = 0; i < m; ++i) {
            a[i] = in.nextDouble();
        }
        res = new double[m];
    }

    public void solve() {
        for (int i = 0; i < m; ++i) {
            if (n == 1) {
                res[i] = Math.sqrt(2 * d / a[i]);
            }
            else {
                if (x[0] > d) {
                    res[i] = Math.sqrt(2 * d / a[i]);
                }
                else {
                    double v = (x[1] - x[0]) / (t[1] - t[0]);
                    res[i] = Math.max((d - x[0]) / v, Math.sqrt(2 * d / a[i]));
                }
            }
        }
    }

    public void printOutput(int testNumber, PrintWriter out) {
        out.println("Case #" + testNumber + ":");
        for (int i = 0; i < m; ++i) {
            out.printf("%.8f\n", res[i]);
        }
    }
}
