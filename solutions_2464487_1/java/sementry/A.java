import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
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

        solve();

        out.close();
    }

    public void solve() throws Exception {
        int tests = in.nextInt();
        for (int test = 1; test <= tests; test++) {
            long r = in.nextLong();
            long t = in.nextLong();
            BigInteger R = BigInteger.valueOf(r);
            BigInteger T = BigInteger.valueOf(t);
            BigInteger b2 = BigInteger.valueOf(2);
            
            long left = -1;
            long right = (long) 2e+18; 
            while (left < right - 1) {
                long n = (left + right) / 2;
                BigInteger N = BigInteger.valueOf(n);
                if (N.multiply(R.multiply(b2).add(N.multiply(b2).subtract(BigInteger.ONE))).compareTo(T) <= 0) {
                    left = n;
                } else {
                    right = n;
                }
            }
            out.println("Case #" + test + ": " + left);
            
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
