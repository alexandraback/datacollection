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
    private String fileName = "A-large";

    public ProblemA() throws Exception {
        init();
        solve();
        in.close();
        out.close();
    }

    long reverse(long k) {
        long rev = 0;
        while (k > 0) {
            rev = rev * 10 + k % 10;
            k /= 10;
        }
        return rev;
    }

    int length(long k) {
        int ans = 0;
        while (k > 0) {
            ans++;
            k /= 10;
        }
        return ans;
    }

    int[] d = new int[10000 + 1];

    private int solve1(int n) {
//        System.out.println(Arrays.toString(d));
        return d[n];
    }

    private long solve2(long n) {
        long ans = 0;
        while (n >= 1) {
            if (n < 1000) {
                return ans + d[(int)n];
            }
            int len = length(n);
            long half = 1;
            for (int i = 0; i < len / 2; i++) {
                half *= 10;
            }
            long top, b;
            if ((len & 1) == 0) {
                top = n / half;
                b = top * half + 1;
            } else {
                top = n / (half * 10);
                b = top * half * 10 + 1;
            }
            if (n < b) {
                n--;
                ans++;
                continue;
            }
            if (10 * top == half) {
                ans += (n - b) + 2;
                n = b - 2;
                continue;
            }
            ans += (n - b) + 1;
            n = reverse(b);
        }
        return ans;
    }

    private void solve() throws Exception {
        Arrays.fill(d, d.length + 10);
        d[1] = 1;
        for (int i = 1; i < d.length - 1; i++) {
//            if (d[i + 1] < d[i]) {
//                System.out.println(i + 1);
//            }
            d[i + 1] = Math.min(d[i + 1], d[i] + 1);
            int r = (int)reverse(i);
            if (r <= d.length - 1) {
                if (r < i && d[r] > d[i] + 1) {
                    System.err.println("!!! " + i + " !!!");
                }
                d[r] = Math.min(d[r], d[i] + 1);
            }
        }
        int T = nextInt();
        for (int ii = 1; ii <= T; ii++) {
            long n = nextLong();
            out.println("Case #" + ii + ": " + solve2(n));
        }
//        System.out.println(Arrays.toString(d));

//        for (int i = 1; i < d.length; i++) {
//            if (solve2(i) != d[i]) {
//                System.out.println(i);
//                break;
//            }
//        }
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
            