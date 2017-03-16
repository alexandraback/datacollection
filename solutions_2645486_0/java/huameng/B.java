import java.util.*;
import java.math.*;

public class B {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int cases = in.nextInt();
    for(int z=1;z<=cases;++z) {
      int fullEnergy = in.nextInt();
      int regain = Math.min(fullEnergy,in.nextInt());
      int activities = in.nextInt();
      int[] values = new int[activities];
      for(int i=0;i<activities;++i) values[i] = in.nextInt();
      int[][] dp = new int[activities+1][fullEnergy+1]; // dp[i][j] stores best value after i activities with j energy left
      dp[0][fullEnergy] = 0;
      for(int i=0;i<activities;++i) {
        for(int j=0;j<=fullEnergy;++j) {
          // from state [i][j], let's use some amount of energy!
          for(int k=0;k<=j;++k) {
            // k energy used
            int newEnergy = Math.min(fullEnergy, j-k+regain);
            dp[i+1][newEnergy] = Math.max(dp[i+1][newEnergy], dp[i][j] + k*values[i]);
          }
        }
      }
      System.out.printf("Case #%d: %d\n", z, dp[activities][regain]);
    }
  }
}