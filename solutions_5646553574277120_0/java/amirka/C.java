import java.util.*;
import java.io.*;

public class C {
    FastScanner in;
    PrintWriter out;
    boolean systemIO = false;

    public void solve() throws IOException {
        int tests = in.nextInt();
        for (int test = 0; test < tests; test++) {
            int c = in.nextInt();
            int d = in.nextInt();
            int v = in.nextInt();
            int[] a = new int[d];
            int[] p = new int[v + 100000];
            p[0] = 1;
            for (int i = 0; i < d; i++) {
                a[i] = in.nextInt();
                for (int j = v; j >= 0; j--) {
                    if (p[j] == 1 && j + a[i] <= v) {
                        p[j + a[i]] = 1;
                    }
                }
            }
            int ans = 0;
            for (int i = 0; i <= v; i++) {
                if (p[i] == 0) {
                    p[i] = 0;
                    ans++;
                    for (int j = v; j >= 0; j--) {
                        if (p[j] == 1 && j + i <= v) {
                            p[j + i] = 1;
                        }
                    }
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