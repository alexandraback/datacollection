import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

public class GCJ2012Round1B_A {
    public void run() throws IOException {
        int T = nextInt();
        for (int i = 1; i <= T; ++i) {
            out.print("Case #" + i + ":");
            solve();
            out.println();
        }
    }

    private void solve() throws IOException {
        int N = nextInt();
        int[] J = new int[N];
        int X = 0;
        for (int i = 0; i < N; ++i) {
            J[i] = nextInt();
            X += J[i];
        }
        for (int i = 0; i < N; ++i) {
            double lo = 0;
            double hi = 1;
            for (int j = 0; j < 100; ++j) {
                double mid = (lo + hi) / 2;
                double t = J[i] + X * mid;
                double Y = mid;
                for (int k = 0; k < N; ++k) {
                    if (k != i) {
                        Y += Math.max(0, (t - J[k]) / X);
                    }
                }
                if (Y >= 1) {
                    hi = mid;
                }
                else {
                    lo = mid;
                }
            }
            out.printf(" %f", lo * 100);
        }
    }

    public static BufferedReader in;
    public static PrintStream out;

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);

        String className = GCJ2012Round1B_A.class.getSimpleName();
        char lastChar = className.charAt(className.length() - 1);
        System.setIn(new FileInputStream(lastChar + ".in"));
        System.setOut(new PrintStream(lastChar + ".out"));

        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintStream(new BufferedOutputStream(System.out));

        new GCJ2012Round1B_A().run();

        out.close();
    }

    public static StringTokenizer tokenizer;

    public static String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(in.readLine());
        }
        return tokenizer.nextToken();
    }

    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }
}
