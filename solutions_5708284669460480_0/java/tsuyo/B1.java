import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class B1 {
  Scanner sc = new Scanner(System.in);

  int K, L, S;
  String SK, SL;
  char[] CK, CL;
  int max, sum, total; // TODO: int?

  void input() {
    K = sc.nextInt();
    L = sc.nextInt();
    S = sc.nextInt();
    SK = sc.next();
    SL = sc.next();
    CK = SK.toCharArray();
    CL = SL.toCharArray();
    max = -1;
    sum = 0;
    total = 0;
    // debug(K,L,S);
  }

  void solve() {
    if (S < L) {
      System.out.println(0);
      return;
    }
    // assert S >= L
    // int[] key = new int[26];
    // Set<Character> set = new TreeSet<Character>();
    // for (int i = 0; i < K; i++) {
    // set.add(CK[i]);
    // key[CK[i]-'A']++;
    // }
    // char[] chs = new char[set.size()];
    // int i = 0;
    // for (char c : set) {
    // chs[i++] = c;
    // }
    build(CK, 0, "");
    //debug(sum,total,max);
    double avg = (double) sum / total;
    System.out.printf("%.6f\n", max - avg);
  }

  void build(char[] chs, int i, String sofar) {
    if (i == S) {
      check(sofar);
      return;
    }
    for (int j = 0; j < chs.length; j++) {
      build(chs, i + 1, chs[j] + sofar);
    }
  }

  void check(String type) {    
    total++;
    int ret = 0;
    for (int i = 0; i < S; i++) {
      if (type.substring(i).startsWith(SL)) {
        ret++;
      }
    }
    // debug(S, SL, type, ret);
    sum += ret;
    max = Math.max(max, ret);
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
    new B1().start();
  }

}
