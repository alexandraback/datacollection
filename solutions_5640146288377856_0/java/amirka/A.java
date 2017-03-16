import java.util.*;
import java.io.*;

public class A {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = false;


    boolean check(int[] a, int m, int w) {
        for (int i = 0; i < m - w + 1; i++) {
            boolean ok = true;
            for (int j = 0; j < i; j++) {
                if (a[j] == 2) {
                    ok = false;
                }
            }
            for (int j = i; j < i + w; j++) {
                if (a[j] == 1) {
                    ok = false;
                }
            }
            for (int j = i + w; j < m; j++) {
                if (a[j] == 2) {
                    ok = false;
                }
            }
            if (ok) {
                return true;
            }
        }
        return false;
    }

    int count(int[] a, int m, int w) {
        //for (int i = 0; i < m; i++) {
        //    out.print(a[i] + " ");
        //}
        //out.println();
        int ch = 0;
        for (int i = 0; i < m; i++) {
            if (a[i] == 2) {
                ch++;
            }
        }
        if (ch == w) {
            return 0;
        }

        int ans = 1000;
        for (int i = 0; i < m; i++) {
            if (a[i] == 0) {
                a[i] = 1;
                int t1 = 0;
                if (check(a, m, w)) {
                    t1 = count(a, m, w);
                }

                a[i] = 2;
                int t2 = 0;
                if (check(a, m, w)) {
                    t2 = count(a, m, w);
                }
                ans = Math.min(ans, Math.max(t1, t2));
                a[i] = 0;
            }
        }
        return ans + 1;
    }

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            int n = in.nextInt();
            int m = in.nextInt();
            int w = in.nextInt();
            int ans = (n - 1) * (m / w);
            int[] a = new int[m];
            ans += count(a, m, w);
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
        new A().run();
    }
}