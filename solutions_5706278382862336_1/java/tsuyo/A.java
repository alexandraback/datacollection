import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class A {
  Scanner sc = new Scanner(System.in);

  long P, Q;

  void input() {
    String[] PQ = sc.next().split("/");
    P = Long.parseLong(PQ[0]);
    Q = Long.parseLong(PQ[1]);
  }

  void solve() {
    long gcd = gcd(P,Q);
    P /= gcd;
    Q /= gcd;
    if ((1L << 40) % Q != 0) {
      System.out.println("impossible");
      return;
    }

    for (int i = 1; i <= 40; i++) {
      if (P * 2 >= Q) {
        // long val = P * 2 - Q;
        //if ((1 << (40 - i)) % Q == 0) {
          System.out.println(i);
        //} else {
          //System.out.println("impossible");
        //}
        break;
      }
      P *= 2;
    }
  }
  
  long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
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
