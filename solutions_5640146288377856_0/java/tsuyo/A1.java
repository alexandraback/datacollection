import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class A1 {
  Scanner sc = new Scanner(System.in);

  int R, C, W;

  void input() {
    R = sc.nextInt();
    C = sc.nextInt();
    W = sc.nextInt();
  }

  void solve() {
    if (W == C) {
      System.out.println(W);
      return;
    }
    System.out.println(rec(C, W));
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

  int rec(int c, int w) {
    if (w == c) {
      return w;
    }
    if (w > c) {
      return 0;
    }
    int diff = 2 * w - c;
    if (diff >= 1) {
      return 1 + w;
    }
    return 1 + rec(c - w, W);
  }

  void debug(Object... os) {
    System.err.println(deepToString(os));
  }

  public static void main(String[] args) throws Exception {
    System
        .setIn(new FileInputStream(args.length > 0 ? args[0] : ("sample.in")));
    new A1().start();
  }

}
