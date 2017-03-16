import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class A {

    final static String PREFIX = "C:\\codejam\\A";
//    final static String FILE_NAME = PREFIX + "-test";
        final static String FILE_NAME = PREFIX + "-small-attempt0";
    //    final static String FILE_NAME = PREFIX + "-large";

    private Scanner in;
    private PrintWriter out;

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        new A().solveAll();
    }

    private void solveAll() throws Exception {
        in = new Scanner(new File(FILE_NAME + ".in"));
        out = new PrintWriter(new File(FILE_NAME + ".out"));
        int tcn = in.nextInt();
        for (int tc = 1; tc <= tcn; tc++) {
            solve(tc);
        }
        out.close();
    }

    private void solve(int tc) {
        long a = in.nextLong();
        int n = in.nextInt();
        long[] t = new long[n];
        for (int i = 0; i < n; i++) {
            t[i] = in.nextLong();
        }
        Arrays.sort(t);
        int res = r(t, 0, a);

        out.format("Case #%d: %s\n", tc, res);
        System.out.format("Case #%d: %s\n", tc, res);
    }

    private int r(long[] t, int i, long a) {
        while (i < t.length && a > t[i]) {
            a += t[i];
            i++;
        }
        int m = 0;
        if (i < t.length) {
            if (a > 1) {
                long ax = a;
                int x = 0;
                while (ax <= t[i]) {
                    x++;
                    ax += ax - 1;
                }
                m = Math.min(1 + r(t, i + 1, a), x + r(t, i + 1, ax + t[i]));
            } else {
                m = 1 + r(t, i + 1, a);
            }
        }
        return m;
    }
}
