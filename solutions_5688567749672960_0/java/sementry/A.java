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

    public int solve() throws Exception {
        int n = in.nextInt();
        int[] d = new int[n + 1];
        Arrays.fill(d, Integer.MAX_VALUE);
        d[1] = 1;
        for (int i = 2; i <= n; i++) {
            d[i] = Math.min(d[i], d[i - 1] + 1);
            int irev = reverse(i);
            if (irev < i && String.valueOf(irev).length() == String.valueOf(i).length()) {
                d[i] = Math.min(d[i], d[irev] + 1);
            }
        }
        return d[n];
    }

    int reverse(int p) {
        char[] ps = String.valueOf(p).toCharArray();
        for (int i = 0; i < ps.length / 2; i++) {
            char tmp = ps[i];
            ps[i] = ps[ps.length - i - 1];
            ps[ps.length - i - 1] = tmp;
        }
        return Integer.valueOf(String.valueOf(ps));
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
