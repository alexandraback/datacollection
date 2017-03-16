import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            int E = sc.nextInt();
            int R = sc.nextInt();
            int N = sc.nextInt();
            int[] v = new int[N];

            if (R > E) {
                R = E;
            }

            int[][] dp = new int[N + 1][E + 1];
            for (int i = 1; i <= N; i++) {
                for (int j = 0; j <= E; j++) {
                    dp[i][j] = Integer.MIN_VALUE;
                }
            }

            for (int i = 0; i < N; i++) {
                v[i] = sc.nextInt();
            }

            for (int i = 1; i <= N; i++) {
                for (int k = R; k <= E; k++) {
                    for (int j = k - R; j <= E; j++) {
                        dp[i][k] = Math.max(dp[i][k], dp[i - 1][j] + (j + R - k) * v[i - 1]);
                    }
                }
            }

            System.out.println("Case #" + caseNum + ": " + dp[N][R]);
        }
    }
}
