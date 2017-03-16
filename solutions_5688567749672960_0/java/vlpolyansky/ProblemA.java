import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class ProblemA {

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.UK);
        new ProblemA();
    }

    private BufferedReader in = null;
    private PrintWriter out = null;
    private StringTokenizer tok = new StringTokenizer("");
    private String fileName = "A-small-attempt0";

    public ProblemA() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    int reverse(int k) {
        int rev = 0;
        while (k > 0) {
            rev = rev * 10 + k % 10;
            k /= 10;
        }
        return rev;
    }

    private int solve1(int n) {
        int[] d = new int[n + 1];
        Arrays.fill(d, n + 10);
        d[1] = 1;
        for (int i = 1; i < n; i++) {
            d[i + 1] = Math.min(d[i + 1], d[i] + 1);
            int r = reverse(i);
            if (r <= n) {
                if (r < i && d[r] > d[i] + 1) {
                    System.err.println("!!! " + i + " !!!");
                }
                d[r] = Math.min(d[r], d[i] + 1);
            }
        }
//        System.out.println(Arrays.toString(d));
        return d[n];
    }

    private void solve() throws Exception {
        int T = nextInt();
        for (int ii = 1; ii <= T; ii++) {
            int n = nextInt();
            out.println("Case #" + ii + ": " + solve1(n));
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
            