import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.time.Duration;
import java.time.LocalTime;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.TreeSet;

/**
 * @author Roman Nefyodov
 */
public class D {

    double[] naomi, ken;
    int n;

    int[][] dp;

    int find_min_id(int naomi_used) {
        double min_val = Integer.MAX_VALUE;
        int min_id = -1;
        for (int i = 0; i < n; ++i)
            if (((1 << i) & naomi_used) != 0) {
                if (min_val > naomi[i]) {
                    min_val = naomi[i];
                    min_id = i;
                }
            }
        return min_id;
    }

    int find_min_greater_than(int naomi_used, double than) {
        double min_val = Integer.MAX_VALUE;
        int min_id = -1;
        for (int i = 0; i < n; ++i)
            if (((1 << i) & naomi_used) != 0) {
                if (min_val > naomi[i]) {
                    min_val = naomi[i];
                    min_id = i;
                }
            }
        return min_id;

    }

    int go(int naomi_used, int ken_used) {
        if (naomi_used == 0 && ken_used == 0)
            return 0;
        if (dp[naomi_used][ken_used] != Integer.MAX_VALUE)
            return dp[naomi_used][ken_used];
        int max_result = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i)
            if (((1 << i) & naomi_used) != 0) {
                int min_result = Integer.MAX_VALUE;
                for (int j = 0; j < n; ++j) {
                    if (((1 << j) & ken_used) != 0) {
//                        int res = go(naomi_used ^ (1 << i), ken_used ^ (1 << j)) + (naomi[i] > ken[j] ? 1 : -1);
                        int res = naomi[i] > ken[j]
                                ?  1 + go(naomi_used ^ (1 << i), ken_used ^ (1 << j))
                                : -1 + go(naomi_used ^ (1 << find_min_id(naomi_used)), ken_used ^ (1 << j));
                        min_result = Math.min(min_result, res);
                    }
                }
                max_result = Math.max(max_result, min_result);
            }
        return dp[naomi_used][ken_used] = max_result;
    }

    void trySolve() {
        TreeSet<Double> q1 = new TreeSet<>();
        TreeSet<Double> q2 = new TreeSet<>();
        for (int i = 0; i < n; ++i) {
            q1.add(naomi[i]);
            q2.add(ken[i]);
        }
        int naomiFair = 0;
        for (int i = 0; i < n; ++i) {
            if (q1.last() > q2.last()) {
                naomiFair += 1;
                q1.pollLast();
                q2.pollFirst();
            } else {
                q1.pollLast();
                q2.pollLast();
            }
        }

        for (int i = 0; i < n; ++i) {
            q1.add(naomi[i]);
            q2.add(ken[i]);
        }
        int naomiUnfair = 0;
        for (int i = 0; i < n; ++i) {
            if (q1.last() > q2.last()) {
                naomiUnfair += 1;
                q1.remove(q1.subSet(q2.first(), Double.MAX_VALUE).first());
                q2.pollFirst();
            } else {
                q1.pollFirst();
                q2.pollLast();
            }
        }
        pw.printf("%d %d\n", naomiUnfair, naomiFair);
    }


    public void solveCase() {
        n = nextInt();
//        int N = (1 << n);
//
//        dp = new int[N][N];
//        for (int i = 0; i < N; ++i)
//            Arrays.fill(dp[i], Integer.MAX_VALUE);

        naomi = new double[n];
        ken = new double[n];
        for (int i = 0; i < n; ++i)
            naomi[i] = nextDouble();
        for (int i = 0; i < n; ++i)
            ken[i] = nextDouble();
        Arrays.sort(naomi);
        Arrays.sort(ken);
//        int res = go(N - 1, N - 1);
//        int naomi_res = (n + res) / 2;
//        pw.println(res);
//        pw.println(naomi_res);
        trySolve();
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
            pw.flush();
        }
    }

    public static void main(String[] args) {
        new D().run(args);
    }

    public void run(String[] args) {
        try {
            Locale.setDefault(Locale.US);
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

