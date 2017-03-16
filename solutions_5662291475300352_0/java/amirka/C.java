import java.util.*;
import java.io.*;

public class C {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = false;

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            int n = in.nextInt();
            double a[] = new double[100];
            double b[] = new double[100];
            int k = 0;
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                int num = in.nextInt();
                int t = in.nextInt();
                for (int j = 0; j < num; j++) {
                    a[k] = x;
                    b[k] = t + j;
                    k++;
                }
            }
                int ans = 0;
                if (k < 2) {
                    ans = 0;
                } else {
                    double f = (360 - a[0]) / (360 / b[0]);
                    double s = (360 - a[1]) / (360 / b[1]);
                    double mintime = Math.max((360 - a[0]) / (360 / b[0]), (360 - a[1]) / (360 / b[1]));
                    if (mintime >= Math.min(b[0] + f, b[1] + s)) {
                        ans++;
                    }
                }
                out.print("Case #" + (test + 1) + ": ");
                out.println(ans);
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