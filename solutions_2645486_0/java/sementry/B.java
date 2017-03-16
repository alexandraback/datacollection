import java.io.*;
import java.util.*;

public class B {

    MyScanner in;
    PrintWriter out;
    final static String FILENAME = "b";

    public static void main(String[] args) throws Exception {
        new B().run();
    }

    public void run() throws Exception {
        in = new MyScanner(FILENAME + ".in");
        out = new PrintWriter(FILENAME + ".out");

        int tests = in.nextInt();
        for (int test = 1; test <= tests; test++) {
            out.println("Case #" + test + ": " + solve());
        }
        
        out.close();
    }

    int n, e, r;
    int[] v;
    int[] g;
    int ans;
    
    public int solve() throws Exception {
        e = in.nextInt();
        r = in.nextInt();
        n = in.nextInt();
        v = new int[n];
        g = new int[n];
        ans = 0;
        for (int i = 0; i < n; i++) {
            v[i] = in.nextInt();
        }
        count(0, e);
        return ans;
    }

    void count(int depth, int energy) {
        if (depth >= n) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += v[i] * g[i];
            }
            if (ans < sum) {
                ans = sum;
            }
        } else {
            for (int d = 0; d <= energy; d++) {
                g[depth] = d;
                count(depth + 1, Math.min(energy - d + r, e));
            }
        }
    }
    class MyScanner {

        BufferedReader br;
        StringTokenizer st;

        public MyScanner(String file) throws Exception {
            br = new BufferedReader(new FileReader(file));
        }

        String next() throws Exception {
            while ((st == null) || (!st.hasMoreTokens())) {
                String t = br.readLine();
                if (t == null) {
                    return null;
                }
                st = new StringTokenizer(t);
            }
            return st.nextToken();
        }

        int nextInt() throws Exception {
            return Integer.parseInt(next());
        }

        double nextDouble() throws Exception {
            return Double.parseDouble(next());
        }

        boolean nextBoolean() throws Exception {
            return Boolean.parseBoolean(next());
        }

        long nextLong() throws Exception {
            return Long.parseLong(next());
        }
    }
}
