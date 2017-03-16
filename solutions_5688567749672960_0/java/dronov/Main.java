import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;
    long[] dp = new long[1000001];

    public void solve() throws IOException {

        dp[1] = 1;
        for (int i = 2; i <= 1000000; i++)
            dp[i] = Long.MAX_VALUE;
        for (int i = 1; i < 1000000; i++) {
                dp[i + 1] = Math.min(dp[i + 1], dp[i] + 1);
                int q = reverse(i);
                dp[q] = Math.min(dp[q], dp[i] + 1);
        }

        int test = in.nextInt();
        for (int t = 1; t <= test; t++) {
            int n = in.nextInt();
            out.println("Case #" + t + ": " + dp[n]);
        }
    }

    private int reverse(int i) {
        String str = String.valueOf(i);
        String reverse = new StringBuilder(str).reverse().toString();
        int q = Integer.parseInt(reverse);
        return q;
    }

    public void run() {
        try {
            in = new FastScanner(new File("input.txt"));
            out = new PrintWriter(new File("output.txt"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] arg) {
        new Main().run();
    }
}