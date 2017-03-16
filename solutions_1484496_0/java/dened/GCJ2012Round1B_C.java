import java.io.*;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.StringTokenizer;

public class GCJ2012Round1B_C {
    public void run() throws IOException {
        int T = nextInt();
        for (int i = 1; i <= T; ++i) {
            out.println("Case #" + i + ":");
            solve();
        }
    }

    private void solve() throws IOException {
        int N = nextInt();
        int[] a = new int[N];
        for (int i = 0; i < N; ++i) {
            a[i] = nextInt();
        }
        Map<Integer, Integer> sum = new HashMap<Integer, Integer>();
        for (int i = 0; i < (1 << N); ++i) {
            int s = 0;
            for (int j = 0; j < N; ++j) {
                if ((i & (1 << j)) != 0) {
                    s += a[j];
                }
            }
            Integer k = sum.get(s);
            if (k != null) {
                printSet(a, k);
                printSet(a, i);
                return;
            }
            sum.put(s, i);
        }
        out.println("Impossible");
    }

    private void printSet(int[] a, int k) {
        boolean first = true;
        for (int j = 0; j < a.length; ++j) {
            if ((k & (1 << j)) != 0) {
                if (!first) {
                    out.print(' ');
                }
                out.print(a[j]);
                first = false;
            }
        }
        out.println();
    }

    public static BufferedReader in;
    public static PrintStream out;

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);

        String className = GCJ2012Round1B_C.class.getSimpleName();
        char lastChar = className.charAt(className.length() - 1);
        System.setIn(new FileInputStream(lastChar + ".in"));
        System.setOut(new PrintStream(lastChar + ".out"));

        in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintStream(new BufferedOutputStream(System.out));

        new GCJ2012Round1B_C().run();

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
