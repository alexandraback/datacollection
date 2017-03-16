import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Osmos {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int testcases = in.nextInt();
        for (int testcase = 1; testcase <= testcases; testcase++) {
            long st = in.nextInt();
            int n = in.nextInt();
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);

            int res = n;
            int curr = 0;
            for (int i = 0; st > 1 && i < n; i++) {
                while (a[i] >= st) {
                    st = st * 2 - 1;
                    curr++;
                }
                st += a[i];
                res = Math.min(res, curr + (n - i - 1));
            }
            out.println("Case #" + testcase + ": " + res);
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("A-small-attempt0.in"));
            out = new PrintWriter(new File("A-small.out"));

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
        new Osmos().run();
    }
}