import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class ProblemC {

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.UK);
        new ProblemC();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "C-small-2-attempt0";
//    private String fileName = "#Console";

    public ProblemC() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    private void solve() throws Exception {
        int T = nextInt();
        for (int ii = 1; ii <= T; ii++) {
            out.print("Case #" + ii + ": ");
            int n = nextInt();
            long[] d = new long[11];
            long[] m = new long[11];
            int j = 0;
            for (int i = 0; i < n; i++) {
                d[j] = nextInt();
                int h = nextInt();
                m[j] = nextInt();
                for (int k = 0; k < h; k++) {
                    d[j + k] = d[j];
                    m[j + k] = m[j] + k;
                }
                j += h;
            }
            n = j;
            if (n == 1) {
                out.println(0);
                continue;
            }
            long[] t = new long[n];
            for (int i = 0; i < n; i++) {
                t[i] = m[i] * (360 - d[i]);
            }
            int best = n;
            for (int i = 0; i < n; i++) {
                int cur = 0;
                for (int k = 0; k < n; k++) {
                    if (k == i) {
                        continue;
                    }
                    if (t[i] < t[k] || t[k] + m[k] * 360 <= t[i]) {
                        cur++;
                    }
                }
                best = Math.min(best, cur);
            }
            out.println(best);
        }
    }


    private void init() throws FileNotFoundException {
        if (fileName.equals("#Console")) {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        } else if (fileName.equals("#IOtxt")) {
            in = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");
        } else {
            in = new BufferedReader(new FileReader(fileName + ".in"));
            out = new PrintWriter(fileName + ".out");
        }
    }


    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }


    private String nextToken() throws IOException {
        while (!tok.hasMoreTokens()) {
            String s = in.readLine();
            if (s == null) {
                return null;
            }
            tok = new StringTokenizer(s);
        }
        return tok.nextToken();
    }

}
            