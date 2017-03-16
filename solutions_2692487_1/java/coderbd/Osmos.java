import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Osmos {
  public BufferedReader br;
  public int n, t, ans;
  public long a;
  public long[] motes;
  public long[][] dp;
  public void go() throws Throwable {
    br = new BufferedReader(new InputStreamReader(System.in));
    t = Integer.parseInt(br.readLine());
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      String[] ss = br.readLine().split(" +");
      a = Long.parseLong(ss[0]);
      n = Integer.parseInt(ss[1]);
      motes = new long[n];
      ss = br.readLine().split(" +");
      for (int i = 0; i < n; i++)
        motes[i] = Long.parseLong(ss[i]);
      Arrays.sort(motes);
      dp = new long[n+1][n+1];
      dp[0][0] = a;
      for (int j = 1; j <= n; j++)
        dp[0][j] = 2 * dp[0][j-1] - 1;
      for (int i = 1; i <= n; i++) {
        if (dp[i-1][0] > motes[i-1])
          dp[i][0] = max(dp[i][0], dp[i-1][0] + motes[i-1]);
        for (int j = 1; j <= n; j++) {
          dp[i][j] = 2 * dp[i][j-1] - 1;
          if (dp[i-1][j] > motes[i-1])
            dp[i][j] = max(dp[i][j], dp[i-1][j] + motes[i-1]);
          dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
        }
      }
      ans = 0;
      for (int i = 0; i <= n; i++)
        if (dp[n][i] != 0) {
          ans = i;
          break;
        }
      System.out.println("Case #" + caseNo + ": " + ans);
    }
  }
  public static void main(String[] args) throws Throwable {
    new Osmos().go();
  }
}
