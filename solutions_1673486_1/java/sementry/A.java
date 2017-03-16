import java.io.*;
import java.util.*;

public class A {

    MyScanner in;
    PrintWriter out;
    final static String FILENAME = "a";

    public static void main(String[] args) throws Exception {
        new A().run();
    }

    public void run() throws Exception {
        in = new MyScanner(FILENAME + ".in");
        out = new PrintWriter(FILENAME + ".out");

        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            out.println("Case #" + (test + 1) + ": " + solve());
        }

        out.close();
    }

    public double solve() throws Exception {
        int A = in.nextInt();
        int B = in.nextInt();
        double[] p = new double[A];
        for (int i = 0; i < A; i++) {
            p[i] = in.nextDouble();
        }
        for (int i = 1; i < A; i++) {
            p[i] *= p[i - 1];
        }
        
        // press enter now:
        double ans = Math.min(B + 2, A + B + 1);
        for (int i = 0; i < A; i++) {
            ans = Math.min(ans, p[i] * (A - i - 1 + B - i - 1 + 1) + (1 - p[i]) * (A - i - 1 + B - i - 1 + 1 + B + 1));
        }
        return ans;
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
