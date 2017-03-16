import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = false;


    public long reverse(long x) {
        long ans = 0;
        int st = 1;
        while (x != 0) {
            ans = ans * 10 + (x % 10);
            st *= 10;
            x /= 10;
        }
        return ans;
    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            long n = in.nextLong();
            int m = (int) n;
            int[] dp = new int[m + 1];
            dp[1] = 1;
            for (int i = 2; i <= m; i++) {
                dp[i] = dp[i - 1];
                if (i > reverse(i) && i % 10 != 0) {
                    dp[i] = Math.min(dp[i], dp[(int) reverse(i)]);
                }
                dp[i]++;
            }
            out.print("Case #" + (test + 1) + ": ");
            out.println(dp[m]);
        }
    }

    public void run() {
        try {
            if (systemIO) {
                in = new FastScanner(System.in);
                out = new PrintWriter(System.out);
            } else {
                in = new FastScanner(new File("a.in"));
                out = new PrintWriter(new File("a.out"));
            }
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

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
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