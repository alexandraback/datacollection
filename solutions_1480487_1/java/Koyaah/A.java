import java.io.*;
import java.math.BigInteger;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * User: Igor Kirov
 * Date: 05.05.12
 */
public class A implements Runnable {
    private void solve() throws Exception {
        int n = nextInt();
        int sum = 0;
        int[] s = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            s[i] = nextInt();
            sum += s[i];
            max = Math.max(max, s[i]);
        }

        double low = 0;
        double hi = sum * 2;
        for (int i = 0; i < 300; i++) {
            double mid = (low + hi) / 2;
            double[] x = new double[n];
            double sumx = 0;
            for (int j = 0; j < n; j++) {
                x[j] = (mid - s[j]) / sum;
                sumx += x[j];
            }
            if (sumx > 1) {
                hi = mid;
            } else {
                low = mid;
            }
        }

        double mid = (low + hi) / 2;
        double[] x = new double[n];
        double sx = 0;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            x[j] = (mid - s[j]) / sum;
            if (x[j] < 0) {
                sx -= x[j];
                cnt++;
            }
//            writer.printf("%.8f ", x[j] * 100);
        }
        for (int j = 0; j < n; j++) {
            if (x[j] < 0) {
                writer.printf("%.8f ", 0d);
                continue;
            }
            writer.printf("%.8f ", (x[j] - sx / (n-cnt)) * 100);
        }
        writer.println();
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