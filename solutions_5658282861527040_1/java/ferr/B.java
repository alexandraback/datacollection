import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.time.Duration;
import java.time.LocalTime;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

/**
 * @author Roman Nefyodov
 */
public class B {

    int[] a, b, k;

    Set<Integer> gen(int val, boolean upper) {
        Set<Integer> as = new HashSet<Integer>();
            if (upper)
                for (int i = 0; i <= val; ++i)
                    as.add(i);
            else
                for (int i = 0; i <= 1; ++i)
                    as.add(i);
        return as;
    }

    long[][][][] dp;

    long go(int pos, int a_upper, int b_upper, int k_upper) {
        if (pos < 0) {
            int res = a_upper != 0 || b_upper != 0 || k_upper != 0 ? 0 : 1;
            return res;
        }
        if (dp[pos][a_upper][b_upper][k_upper] != -1)
            return dp[pos][a_upper][b_upper][k_upper];
        Set<Integer> as = gen(a[pos], a_upper != 0);
        Set<Integer> bs = gen(b[pos], b_upper != 0);
        long ans = 0;
        for (int ai : as) {
            for (int bi : bs) {
                int ab = ai & bi;
                if (k_upper != 0 && ab <= k[pos] || k_upper == 0) {
                    ans += go(pos - 1,
                            a_upper != 0 && (ai == a[pos]) ? 1 : 0,
                            b_upper != 0 && (bi == b[pos]) ? 1 : 0,
                            k_upper != 0 && (ab == k[pos]) ? 1 : 0
                    );
                }
            }
        }
        dp[pos][a_upper][b_upper][k_upper] = ans;
        return ans;
    }

    public void solveCase() {
        int A = nextInt(), B = nextInt(), K = nextInt();
//        int ans1 = 0;
//        for (int i = 0; i < A; ++i)
//            for (int j = 0; j < B; ++j) {
//                if ((i & j) < K)
//                    ans1++;
//            }
        a = new int[32];
        b = new int[32];
        k = new int[32];
        int mval = 0;
        for (int i = 31; i >= 0; --i) {
            a[i] = (A >> i) & 1;
            b[i] = (B >> i) & 1;
            k[i] = (K >> i) & 1;
            if (a[i] != 0 || b[i] != 0 || k[i] != 0)
                mval = Math.max(mval, i);
        }
        dp = new long[mval + 1][2][2][2];
        for (int i = 0; i <= mval; ++i)
            for (int i1 = 0; i1 < 2; ++i1)
                for (int i2 = 0; i2 < 2; ++i2)
                    for (int i3 = 0; i3 < 2; ++i3)
                        dp[i][i1][i2][i3] = -1;
        long ans2 = go(mval, 1, 1, 1);
        pw.print(ans2);
//        pw.printf("%d %d %s", ans1, ans2, ans1 != ans2 ? "!!!!!!!!!" : "");
    }

    public void solve() {
        int T = nextInt();
        for (int i = 0; i < T; ++i) {
            pw.printf("Case #%d: ", i + 1);
            LocalTime start = LocalTime.now();
            pwerr.printf("Case %d started..\n", i + 1);
            pwerr.flush();
            solveCase();
            Duration duration = Duration.between(start, LocalTime.now());
            pwerr.printf("Case %d finished (%ds)..\n", i + 1, duration.getSeconds());
            pwerr.flush();
            pw.print('\n');
            pw.flush();
        }
    }

    public static void main(String[] args) {
        new B().run(args);
    }

    public void run(String[] args) {
        try {
            if (args.length == 1) {
                String filename = args[0];
                in = new BufferedReader(new FileReader(filename + ".in.txt"));
                pw = new PrintWriter(filename + ".out.txt");
            } else {
                in = new BufferedReader(new InputStreamReader(System.in));
                pw = new PrintWriter(System.out);
            }
            pwerr = new PrintWriter(System.err);
            st = new StringTokenizer("");
            solve();
            pw.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    private StringTokenizer st;
    private BufferedReader in;
    private PrintWriter pw;
    private PrintWriter pwerr;

    int curCase;

    boolean hasNext() {
        try {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null)
                    return false;
                st = new StringTokenizer(line);
            }
            return st.hasMoreTokens();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    String next() {
        return hasNext() ? st.nextToken() : null;
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }
}

