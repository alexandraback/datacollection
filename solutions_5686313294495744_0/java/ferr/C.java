import java.io.PrintWriter;
import java.util.*;
import java.util.stream.Collectors;


public class C {
    static PrintWriter pw;
    static Scanner sc;

    public static void main(String[] args) {
        pw = new PrintWriter(System.out);
        sc = new Scanner(System.in);

        new C().run();
        pw.flush();
    }

    private void run() {
        int T = sc.nextInt();
        for (int t = 0; t < T; ++t) {
            System.err.printf("Case %d of %d\n", t + 1, T);
            pw.printf("Case #%d: %s\n", t + 1, nextCase(t));
        }
    }

    String[] A;
    String[] B;

    int[] ac;
    int[] bc;

    int n;
    int[] dp;

    int go(int mask) {
        if (dp[mask] != -1) {
            return dp[mask];
        }
        int best = 0;
        for (int i = 0; i < n; ++i) {
            if (((1 << i) & mask) != 0) {
                boolean asame = false, bsame = false;
                for (int j = 0; j < n; ++j) {
                    if (((1 << j) & mask) == 0) {
                        asame |= ac[j] == ac[i];
                        bsame |= bc[j] == bc[i];
                    }
                }
                best = Math.max(best, go(mask ^ (1 << i)) + (asame && bsame ? 1 : 0));
            }
        }
        return dp[mask] = best;
    }

    private String nextCase(int caseNum) {
        n = sc.nextInt();
        A = new String[n];
        B = new String[n];
        ac = new int[n];
        bc = new int[n];

        Map<String, Integer> acomp = new HashMap<>();
        Map<String, Integer> bcomp = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            A[i] = sc.next();
            B[i] = sc.next();
            if (!acomp.containsKey(A[i])) {
                acomp.put(A[i], acomp.size());
            }
            ac[i] = acomp.get(A[i]);
            if (!bcomp.containsKey(B[i])) {
                bcomp.put(B[i], bcomp.size());
            }
            bc[i] = bcomp.get(B[i]);
        }
        dp = new int[1 << n];
        Arrays.fill(dp, -1);
        return "" + go((1 << n) - 1);
    }
}