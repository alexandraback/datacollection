import java.io.*;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * User: Igor Kirov
 * Date: 05.05.12
 */
public class C implements Runnable {
    private void print(int[] a, int cur) {
        int idx = 0;
        while (cur > 0) {
            if (cur % 2 == 0) {
                cur = cur / 2;
                idx++;
                continue;
            }
            writer.print(a[idx] + " ");
            idx++;
            cur = cur / 2;
        }
        writer.println();
    }

    private void solve() throws Exception {
        int n = nextInt();
        int[] a = new int[n];

        Map<Integer, Integer> subsets = new HashMap<Integer, Integer>();

        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }

        for (int i = 0; i < (1 << n); i++) {
            int cur = i;
            int sum = 0;
            int idx = 0;
            while (cur > 0) {
                if (cur % 2 == 0) {
                    cur = cur / 2;
                    idx++;
                    continue;
                }
                cur = cur / 2;
                sum += a[idx];
                idx++;
            }
            if (subsets.containsKey(sum)) {
                writer.println();
                print(a, subsets.get(sum));
                print(a, i);
                return;
            }
            subsets.put(sum, i);
        }
        writer.println();
        writer.println("Impossible");
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