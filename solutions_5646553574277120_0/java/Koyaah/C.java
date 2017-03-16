import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;


/**
 * User: Igor Kirov
 * Date: 10.05.2015
 */
public class C implements Runnable {
    int c;
    int d;
    int v;

    private void mark(boolean[] can, int cur) {
        for (int i = v; i >= 0; i--) {
            if (can[i])
                can[i + cur] = true;
        }
    }

    private void solve() throws IOException {
        c = nextInt();
        d = nextInt();
        v = nextInt();

        int[] a = new int[d];

        for (int i = 0; i < d; i++) {
            a[i] = nextInt();
        }

        boolean[] can = new boolean[10000];
        can[0] = true;
        for (int i = 0; i < d; i++) {
            mark(can, a[i]);
        }

        int res = 0;
        for (int i = 0; i<=v; i++) {
            if (!can[i]) {
                res++;
                mark(can, i);
            }
        }

        writer.println(res);
    }

    public static void main(String[] args) {
        new Thread(null, new C(), "", 64 * 1024 * 1024).start();
    }

    StringTokenizer tokenizer;
    BufferedReader reader;
    PrintWriter writer;

    public void run() {
        try {
            try {
                Locale.setDefault(Locale.US);
            } catch (Exception ignored) {
            }

            reader = new BufferedReader(new FileReader("C.in"));
            writer = new PrintWriter(new FileWriter("C.out"));
            tokenizer = null;

            int tests = nextInt();
            for (int i = 0; i < tests; i++) {
                writer.printf("Case #%d: ", i + 1);
                solve();
                writer.flush();
            }

            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private BigInteger nextBigInteger() throws IOException {
        return new BigInteger(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}