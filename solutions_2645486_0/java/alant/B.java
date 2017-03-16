import java.util.Arrays;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1 ; i <= T; ++i) {
            int e = sc.nextInt();
            int r = sc.nextInt();
            int n = sc.nextInt();
            int[] ar = new int[n];
            for (int j = 0; j < n; ++j) {
                ar[j] = sc.nextInt();
            }
            int[][] dp = new int[n + 1][e + 1];
            for (int[] temp : dp) {
                Arrays.fill(temp, -1);
            }
            System.out.println("Case #" + i + ": " + foo(0, e, r, e, ar, dp));
        }
    }
    
    public static int foo(int n, int e, int r, int maxE, int[] ar, int[][] dp) {
        if (n == ar.length) {
            return 0;
        }
        if (dp[n][e] >= 0) {
            return dp[n][e];
        }
        int max = 0;
        for (int i = 0; i <= e; ++i) {
            int cv = i * ar[n];
            int ne = e - i + r;
            if (ne > maxE) {
                ne = maxE;
            }
            cv += foo(n + 1, ne, r, maxE, ar, dp);
            if (max < cv) {
                max = cv;
            }
        }
        return dp[n][e] = max;
    }
}
