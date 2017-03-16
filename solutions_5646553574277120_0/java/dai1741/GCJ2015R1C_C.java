import java.util.Scanner;


public class GCJ2015R1C_C {

    private static final int INF = 10000000;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: %d%n", i, new GCJ2015R1C_C().solve(sc));
        }
    }

    private int solve(Scanner sc) throws Exception {
        int c = sc.nextInt();
        int d = sc.nextInt();
        int v = sc.nextInt();
        int[] ds = new int[d];
        int mask = 0;
        for (int i = 0; i < d; i++) {
            ds[i] = sc.nextInt(); // in asc order
            mask |= 1 << ds[i];
        }
        // SMALL CASE
//        if (c > 1 || v > 30) throw new IllegalArgumentException();
        final int maxDenom = 16;
        mask &= (1 << maxDenom) - 1;
        // dp[st][i]: 追加単位セットがstで、金額iを作れるか？
        boolean[][] dp = new boolean[1 << maxDenom][v + 1];
        // Arrays.fill(dp, INF);
        dp[mask][0] = true;
        for (int dd : ds) {
            for (int i = v; i >= 0; i--) {
                if (dp[mask][i] && i + dd <= v) {
                    dp[mask][i + dd] = dp[mask][i];
                }
            }
        }
        for (int st = mask; st < 1 << maxDenom; st++) {
            if ((st & mask) != mask) continue;
            for (int newD = 1; newD < maxDenom; newD++) {
                if ((st & (1 << newD)) != 0) continue;
                int newSt = st | (1 << newD);
                for (int i = v; i >= 0; i--) {
                    if (!dp[st][i]) continue;
                    dp[newSt][i] = true;
                    if (i + newD <= v) dp[newSt][i + newD] = true;
                }
            }
        }
        int ans = INF;
        for (int st = 0; st < 1 << maxDenom; st++) {
            boolean good = true;
            for (int i = 1; i <= v && good; i++) {
                if (!dp[st][i]) good = false;
            }
            if (good) {
                ans = Math.min(ans, Integer.bitCount(st));
            }
        }

        return ans - Integer.bitCount(mask);
    }
}
