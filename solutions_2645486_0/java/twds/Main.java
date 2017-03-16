import java.util.*;
import java.math.*;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author wd
 */
public class Main {
    
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
            int E = scan.nextInt();
            int R = scan.nextInt();
            int N = scan.nextInt();
            int[][] dp = new int[N + 1][E + 1];
            for (int[] inner : dp) {
                Arrays.fill(inner, -1);
            }
            dp[0][E] = 0;
            for (int i = 1; i <= N; i++) {
                int value = scan.nextInt();
                for (int j = 0; j <= E; j++) {
                    if (dp[i - 1][j] == -1) {
                        continue;
                    }
                    for (int k = 0; k <= j; k++) {
                        int temp = dp[i - 1][j] + k * value;
                        int next = Math.min(E, j - k + R);
                        
                        if (dp[i][next] == -1 || dp[i][next] < temp) {
                            dp[i][next] = temp;
                        }
                    }
                }
            }
            
            int res = 0;
            for (int i = 0; i <= E; i++) {
                res = Math.max(res, dp[N][i]);
            }
            
            System.out.println(String.format("Case #%d: %d", taskIndex, res));
        }
    }
}
