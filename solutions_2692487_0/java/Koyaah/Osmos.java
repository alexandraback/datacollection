import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

/**
 * User: Igor Kirov
 * Date: 04.05.13
 */
public class Osmos implements Runnable {
    private void solve() throws IOException {
        int a = nextInt();
        int n = nextInt();
        int[] sizes = new int[n];
        for (int i = 0; i < n; i++) {
            sizes[i] = nextInt();
        }
        Arrays.sort(sizes);

        int min = Integer.MAX_VALUE;
        for (int i = 0; i <= n; i++) {
            int cur = a;
            int remain = i;
            int res = 0;
            for (int j = 0; j < n; j++) {
                while (cur <= sizes[j] && remain > 0) {
                    cur = cur * 2 - 1;
                    remain--;
                    res++;
                }
                if (cur <= sizes[j]) {
                    res += (n - j);
                    break;
                }
                cur += sizes[j];
            }
            min = Math.min(min, res);
        }

        writer.println(min);
    }

    public static void main(String[] args) {
        new Thread(null, new Osmos(), "", 64 * 1024 * 1024).start();
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

            reader = new BufferedReader(new FileReader("Osmos.in"));
            writer = new PrintWriter(new FileWriter("Osmos.out"));
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