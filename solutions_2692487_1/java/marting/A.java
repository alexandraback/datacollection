import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
    static String _tn = "A";
    static Scanner in = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File(_tn+".in"));
        out = new PrintWriter(new File(_tn+".out"));
        int T = in.nextInt();
        for (int I = 0; I < T; I++) {
            out.printf("Case #%d: %s\n", I + 1, solve());
            out.flush();
        }
        out.close();
    }
    static String solve() {
        long A = in.nextLong();
        int n = in.nextInt();
        long dp[][] = new long[n+1][n+1];
        dp[0][0] = A;
        int B[] = new int[n];
        for (int i = 0; i < n; i++)
            B[i] = in.nextInt();
        Arrays.sort(B);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j]<=0) continue;
                long a = dp[i][j];
                dp[i][j+1] = Math.max(dp[i][j+1], a + a-1);
                dp[i+1][j+1] = Math.max(dp[i+1][j+1], a);
                if (a > B[i])
                    dp[i+1][j] = Math.max(dp[i+1][j], a+B[i]);
            }
        }
        for (int j = 0; j <= n; j++)
            if (dp[n][j]>0) return ""+j;
        System.exit(1);
        return "fail";
    }
}
