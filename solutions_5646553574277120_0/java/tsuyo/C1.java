import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class C1 {
  Scanner sc = new Scanner(System.in);

  int C, d, V;
  int[] D;

  void input() {
    C = sc.nextInt();
    d = sc.nextInt();
    V = sc.nextInt();
    D = new int[d];
    for (int i = 0; i < d; i++) {
      D[i] = sc.nextInt();
    }
  }

  void solve() {
    Arrays.sort(D);
    boolean[] dp = new boolean[V + 1];
    dp[0] = true;
    for (int dd = 0; dd < d; dd++) {
      for (int i = V; i >= 0; i--) {
        if (i >= D[dd] && dp[i - D[dd]]) {
          dp[i] = true;
        }
      }
      dp[D[dd]] = true;
    }
    if (check(dp)) {
      System.out.println(0);
      return;
    }
    int ans = 0;
    for (int v = 1; v <= V; v++) {
      if (dp[v]) continue;
      for (int j = 0; j <= v; j++) {
        if (contains(j)) continue;
        int dd = j;
        for (int i = V; i >= 0; i--) {
          if (i >= dd && dp[i - dd]) {
            dp[i] = true;
          }
        }
        dp[dd] = true;
        break;
      }
      ans++;
      if (check(dp)) break;
    }
    System.out.println(ans);
  }
  
  boolean contains(int n) {
    return Arrays.binarySearch(D, n) >= 0;
  }

  void rec(boolean[] dp, int now) {
    for (int v = now; v >= 1; v--) {
      if (dp[v]) continue;
    }
  }
  
  boolean check(boolean[] dp) {
    for (int i = 0; i < dp.length; i++) {
      if (!dp[i]) return false;
    }
    return true;
  }

  void start() {
    int T = sc.nextInt();
    for (int caseNum = 1; caseNum <= T; caseNum++) {
      input();
      System.out.printf("Case #%d: ", caseNum);
      solve();
      System.out.flush();
    }
    sc.close();
  }

  void debug(Object... os) {
    System.err.println(deepToString(os));
  }

  public static void main(String[] args) throws Exception {
    System
        .setIn(new FileInputStream(args.length > 0 ? args[0] : ("sample.in")));
    new C1().start();
  }

}
