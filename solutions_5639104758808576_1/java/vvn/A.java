import java.io.*;
import java.util.StringTokenizer;

public class A {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int t = in.nextInt();
        for (int testcase = 1; testcase <= t; testcase++) {
            solveCase(testcase);
        }
    }

    private void solveCase(int testcase) {
        int n = in.nextInt();
        String x = in.next();

        int[] cnt = new int[n + 1];
        for (int i = 0; i < n; i++) {
            cnt[i] = x.charAt(i) - '0';
        }

        int add = 0;
        int standing = 0;
        for (int i = 0; i <= n; i++) {
            if (standing < i) {
                add += (i - standing);
                standing = i;
            }
            standing += cnt[i];
        }
        out.printf("Case #%d: %d\n", testcase, add);
    }

    public void run() {
        try {
            in = new FastScanner(new FileInputStream("a-large.in"));
            out = new PrintWriter(new FileOutputStream("a-large.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
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
        new A().run();
    }
}