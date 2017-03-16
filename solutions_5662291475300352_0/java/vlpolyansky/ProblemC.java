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
    private String fileName = "C-small-1-attempt3";
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
            long[] d = new long[n + 1];
            long[] h = new long[n + 1];
            long[] m = new long[n + 1];
            for (int i = 0; i < n; i++) {
                d[i] = nextInt();
                h[i] = nextInt();
                m[i] = nextInt();
            }
            if (n == 1 && h[0] == 1) {
                out.println(0);
                continue;
            }
            if (n == 1) {
                d[1] = d[0];
                m[1] = m[0] + 1;
            }
            if (d[0] > d[1]) {
                long t = d[0];
                d[0] = d[1];
                d[1] = t;
                t = m[0];
                m[0] = m[1];
                m[1] = t;
            }
            long t0 = m[0] * (360 - d[0]);
            long t1 = m[1] * (360 - d[1]);
            if (t0 < t1 + m[1] * 360 && t1 < t0 + m[0] * 360) {
                out.println(0);
            } else {
                out.println(1);
            }
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
            