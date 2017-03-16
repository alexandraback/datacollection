import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class B {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int cases = in.nextInt();
        for (int testcase = 1; testcase <= cases; testcase++) {
            out.print("Case #" + testcase + ": ");
            int a = in.nextInt();
            int b = in.nextInt();
            int k = in.nextInt();

            int pairs = 0;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    if ((i & j) < k) {
                        pairs++;
                    }
                }
            }
            out.println(pairs);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new FileInputStream("b-small-attempt0.in"));
            out = new PrintWriter(new FileOutputStream("b-small.out"));

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