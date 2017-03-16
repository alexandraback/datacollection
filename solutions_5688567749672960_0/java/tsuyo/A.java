import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class A {
  Scanner sc = new Scanner(System.in);

  long N;

  void input() {
    N = sc.nextLong();
  }

  void solve() {
    long cur = 1;
    long ans = 0;
    while (cur < N) {
      long cand = next(cur);
      if (cand > N) {
        cur = cur + 1;
      } else {
        cur = cand;
      }
      ans++;
    }
    System.out.println(ans+1);
  }

  long next(long n) {
    long cand1 = n + 1;
    StringBuilder sb = new StringBuilder(n + "");
    long cand2 = Long.parseLong(sb.reverse().toString());
    return Math.max(cand1, cand2);
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
    new A().start();
  }

}
