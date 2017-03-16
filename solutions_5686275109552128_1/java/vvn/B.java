import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int t = in.nextInt();
        for (int testcase = 1; testcase <= t; testcase++) {
            solveCase(testcase);
        }
    }

    private void solveCase(int testcase) {
        int d = in.nextInt();
        int[] p = new int[d];
        for (int i = 0; i < d; i++) {
            p[i] = in.nextInt();
        }

        Arrays.sort(p);
        int max = p[d - 1];

        int result = max;
        for (int i = 1; i <= max; i++) {
            int divisions = 0;
            for (int a : p) {
                divisions += a / i;
                if (a % i == 0) {
                    divisions--;
                }
            }
            result = Math.min(divisions + i, result);
        }

        out.printf("Case #%d: %d\n", testcase, result);
    }

    public void run() {
        try {
            in = new FastScanner(new FileInputStream("b-large.in"));
            out = new PrintWriter(new FileOutputStream("b-large.out"));

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
        new B().run();
    }
}