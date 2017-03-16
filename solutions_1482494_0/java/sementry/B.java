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
        for (int test = 0; test < tests; test++) {
            out.println("Case #" + (test + 1) + ": " + solve());
        }

        out.close();
    }

    public String solve() throws Exception {
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            b[i] = in.nextInt();
        }
        
        int[] x = new int[2 * n];
        int[] p = new int[2 * n];
        boolean[] t = new boolean[2 * n];
        for (int i = 0; i < n; i++) {
            x[2 * i] = a[i];
            p[2 * i] = i;
            x[2 * i + 1] = b[i];
            p[2 * i + 1] = i;
            t[2 * i + 1] = true;
        }
        
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = i + 1; j < 2 * n; j++) {
                if (x[i] > x[j]) {
                    int tx = x[i];
                    x[i] = x[j];
                    x[j] = tx;
                    boolean tt = t[i];
                    t[i] = t[j];
                    t[j] = tt;
                    tx = p[i];
                    p[i] = p[j];
                    p[j] = tx;
                }
            }
        }
        
        int turns = 0;
        int completed = 0;
        int stars = 0;
        boolean[] take = new boolean[2 * n];
        while (completed < n) {
            int i = 0;
            while ((i < 2 * n) && !(!take[i] && t[i])) {
                i++;
            }
            if ((i < 2 * n) && (stars >= x[i])) {
                take[i] = true;
                completed++;
                turns++;
                boolean fl = false;
                for (int j = 0; j < 2 * n; j++) {
                    if (p[j] == p[i] && (j != i)) {
                        take[j] = true;
                        fl = true;
                    }
                }
                stars += (fl) ? 1 : 2;                
            } else {
                i = 0;
                while ((i < 2 * n) && !(!take[i])) {
                    i++;
                }
                if ((i < 2 * n) && (stars >= x[i])) {
                    take[i] = true;
                    turns++;
                    stars += 1;
                } else {
                    break;
                }
            }
        }
        
        if (completed < n) {
            return "Too Bad";
        } else {
            return String.valueOf(turns);
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
