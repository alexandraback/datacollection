import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;


/**
 * User: Igor Kirov
 * Date: 10.05.2015
 */
public class A implements Runnable {
    private void solve() throws IOException {
        int r = nextInt();
        int c = nextInt();
        int w = nextInt();

        int res = 0;
        while (w * 2 <= c) {
            res += r;
            c -= w;
        }
        res += (r - 1);
        res += (w == c) ? w : (w + 1);

        writer.println(res);
    }

    public static void main(String[] args) {
        new Thread(null, new A(), "", 64 * 1024 * 1024).start();
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

            reader = new BufferedReader(new FileReader("A.in"));
            writer = new PrintWriter(new FileWriter("A.out"));
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