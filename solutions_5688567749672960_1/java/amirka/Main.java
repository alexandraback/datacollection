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

    public long get(long x) {
        if (x < 19) {
            return x;
        }
        long ans = 0;
        int len = 0;
        long st10 = 1;
        long last = 0;
        long xx = x;
        while (xx != 0) {
            last = xx % 10;
            len++;
            xx /= 10;
            st10 *= 10;
        }
        int len2 = (len + 1) / 2;
        long st2 = 1;
        for (int i = 0; i < len2; i++) {
            st2 *= 10;
        }
        st10 /= 10;
        if (last != 1) {
            long t = (x / st2) * st2 + 1;
            long tt = reverse(t);
            ans = get(tt) + (x - t) + 1;
        } else {
            long nine = 0;
            for (int i = 0; i < len - 1; i++) {
                nine *= 10;
                nine += 9;
            }
            ans = get(nine) + (x - nine);
        }
        return ans;
    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            long n = in.nextLong();
            //int m = (int) n;
            /*int[] dp = new int[m + 1];
            dp[1] = 1;
            for (int i = 2; i <= m; i++) {
                dp[i] = dp[i - 1];
                if (i > reverse(i) && i % 10 != 0) {
                    if (dp[i] > dp[(int) reverse(i)]) {
                        dp[i] = dp[(int) reverse(i)];
                        //out.println(i + " JUMP");
                    }
                }
                dp[i]++;
            }*/
            //for (int i = 0; i <= n; i++) {
            //    out.println(i + " " + dp[i] + " --- " + pr[i]);
            //}
            //out.println();
            out.print("Case #" + (test + 1) + ": ");
            out.println(get(n));
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