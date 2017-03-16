import java.util.*;
import java.io.*;

public class C {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = false;

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            long c = in.nextInt();
            int d = in.nextInt();
            long v = in.nextInt();
            long[] a = new long[d + 1];
            for (int i = 0; i < d; i++) {
                a[i] = in.nextInt();
            }
            long t = 1;
            int k = 0;
            int ans2 = 0;
            a[d] = 2000000000;
            while (t <= v) {
                while (k < d && a[k] < t) {
                    t += c * a[k];
                    k++;
                }
                if (t > v) {
                    break;
                }
                if (a[k] != t) {
                    ans2++;
                } else {
                    k++;
                }
                t += c * t;
            }

            out.print("Case #" + (test + 1) + ": ");
            out.println(ans2);

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
        new C().run();
    }
}