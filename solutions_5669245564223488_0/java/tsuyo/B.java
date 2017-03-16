import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B {
  Scanner sc = new Scanner(System.in);

  int N;
  String[] cars;
  int MOD = 1000000007;
  int cnt;

  void input() {
    N = sc.nextInt();
    sc.nextLine();
    cars = sc.nextLine().split(" ");
    cnt = 0;
  }

  void solve() {
    rec(0,0,"");
    System.out.println(cnt);
  }

  void rec(int D, int used, String str) {
    if (D == N) {
      if (check(str)) cnt = (cnt + 1) % MOD;
    }
    for (int i = 0; i < N; i++) {
      if (((used >> i) & 1) == 1) continue;
      rec(D + 1, used | (1 << i), str + cars[i]);
    }
  }

  boolean check(String str) {
    boolean[] used = new boolean[26];
    char[] chs = str.toCharArray();
    char prev = '.';
    for (int i = 0; i < chs.length; i++) {
      if (prev != chs[i] && used[chs[i]-'a'])
        return false;
      prev = chs[i];
      used[chs[i]-'a'] = true;
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
    new B().start();
  }

}
