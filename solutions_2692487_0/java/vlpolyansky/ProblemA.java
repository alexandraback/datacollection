import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ProblemA {

    public static void main(String[] args) throws Exception {
        new ProblemA();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "A-small-attempt1";

    public ProblemA() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    private void solve() throws Exception {
        int T = nextInt();
        for (int ii = 1; ii <= T; ++ii) {
            out.print("Case #" + ii + ": ");
            long size = nextInt();
            int n = nextInt();
            long[] a = new long[n];
            for (int i = 0; i < n; ++i) {
                a[i] = nextInt();
            }
            if (size == 1) {
                out.println(n);
                continue;
            }
            Arrays.sort(a);
            int ans = 0;
            int best = n;
            for (int i = 0; i < n; ++i) {
                if (size > a[i]) {
                    size += a[i];
                } else {
                    best = Math.min(best, ans + (n - i));
                    while (size <= a[i]) {
                        ++ans;
                        size = size * 2 - 1;
                    }
                    size += a[i];
                }
            }
            best = Math.min(best, ans);
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
            