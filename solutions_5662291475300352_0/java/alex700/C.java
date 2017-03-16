import java.util.*;
import java.io.*;

public class C {
    FastScanner in;
    PrintWriter out;

    public void solveTest() throws IOException {
        int n = in.nextInt();
        long[] d = new long[n];
        long[] h = new long[n];
        long[] m = new long[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            d[i] = in.nextInt();
            h[i] = in.nextInt();
            m[i] = in.nextInt();
            sum += h[i];
        }
        assert sum <= 2;
        if (sum == 1) {
            out.println(0);
        } else {
            if (n == 1) {
                long t01 = ((360 - d[0])) * m[0];
                long t02 = ((720 - d[0])) * m[0];
                long t11 = ((360 - d[0])) * (m[0] + 1);
                long t12 = ((720 - d[0])) * (m[0] + 1);
                if (t12 <= t01 || t02 <= t11) {
                    out.println(1);
                } else {
                    out.println(0);
                }
            } else {
                long t01 = ((360 - d[0])) * m[0];
                long t02 = ((720 - d[0])) * m[0];
                long t11 = ((360 - d[1])) * m[1];
                long t12 = ((720 - d[1])) * m[1];
                if (t12 <= t01 || t02 <= t11) {
                    out.println(1);
                } else {
                    out.println(0);
                }
            }
        }

    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            out.print("Case #" + (test + 1) + ": ");
            System.out.println("test " + (test + 1));
            solveTest();
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("C-small-1-attempt1.in"));
            out = new PrintWriter(new File("C-small-1-attempt1.out"));
            Locale.setDefault(Locale.US);

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
    }

    public static void main(String[] arg) {
        new C().run();
    }
}