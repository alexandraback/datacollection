import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * User: Igor Kirov
 * Date: 13.04.13
 */
public class B implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[][] a = new int[n][m];
        int[] maxh = new int[m];
        int[] maxw = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = nextInt();
                maxh[j] = Math.max(maxh[j], a[i][j]);
                maxw[i] = Math.max(maxw[i], a[i][j]);
            }
        }

        int[][] b = new int[n][m];
        boolean ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[i][j] = Math.min(maxh[j], maxw[i]);
                if (a[i][j] != b[i][j]) {
                    ok = false;
                }
            }
        }

        writer.println(ok ? "YES" : "NO");
    }

    public static void main(String[] args) {
        new Thread(null, new B(), "", 64 * 1024 * 1024).start();
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

            reader = new BufferedReader(new FileReader("B.in"));
            writer = new PrintWriter(new FileWriter("B.out"));
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