import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Problem B.
 */
public class ProblemB {

    private static int n, e, r;
    private static long tt[][], v[];

    public static void main(String[] args) throws Exception {
        new ProblemB().run();
    }

    private static long t(int ee, int step) {
        if (step == n)
            return 0;
        if (tt[ee][step] == -1) {
            tt[ee][step] = 0;
            for (int i = 0; i <= ee; i++) {
                long val = t(Math.min(ee - i + r, e), step + 1);
                if (tt[ee][step] < val + i * v[step]) {
                    tt[ee][step] = val + i * v[step];
                }
            }
        }
        return tt[ee][step];
    }

    private void run() throws Exception {
        Scanner scanner = new Scanner(new BufferedReader(new FileReader("B-small-attempt1.in")));
        PrintWriter writer = new PrintWriter("B_output.txt");
        int t = scanner.nextInt();
        for (int test = 1; test <= t; test++) {
            e = scanner.nextInt();
            r = scanner.nextInt();
            n = scanner.nextInt();
            v = new long[n];
            for (int i = 0; i < n; i++) {
                v[i] = scanner.nextInt();
            }

            tt = new long[e + 1][n + 1];
            for (int i = 0; i < e + 1; i++) {
                for (int j = 0; j < n + 1; j++) {
                    tt[i][j] = -1;
                }
            }

            writer.print("Case #" + test + ": " + t(e, 0));
            if (test < t) {
                writer.println();
            }
        }

        scanner.close();
        writer.close();
    }
}