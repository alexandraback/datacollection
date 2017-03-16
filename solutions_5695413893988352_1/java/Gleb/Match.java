import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class Match implements Runnable {
  private static final String NAME = "match";

  private String[] solve(String c, String j) {
    int k = 1;
    for (int i = 0; i < c.length(); i++) {
      if (c.charAt(i) == '?') k*=10;
    }
    for (int i = 0; i < j.length(); i++) {
      if (j.charAt(i) == '?') k*=10;
    }
    int res = Integer.MAX_VALUE / 2;
    int rc = -1;
    int rj = -1;
    for (int m = 0; m < k; m++) {
      int cc = 0;
      int jj = 0;
      int curM = m;
      for (int i = 0; i < c.length(); i++) {
        if (c.charAt(i) == '?') {
          cc = cc * 10 + (curM % 10);
          curM /= 10;
        } else {
          cc = cc * 10 + (c.charAt(i) - '0');
        }
      }
      for (int i = 0; i < j.length(); i++) {
        if (j.charAt(i) == '?') {
          jj = jj * 10 + (curM % 10);
          curM /= 10;
        } else {
          jj = jj * 10 + (j.charAt(i) - '0');
        }
      }
      int curRes = Math.abs(cc - jj);
      if (curRes < res) {
        res = curRes;
        rc = cc;
        rj = jj;
      } else {
        if (curRes == res) {
          if (cc < rc || (cc == rc && jj < rj)) {
            res = curRes;
            rc = cc;
            rj = jj;
          }
        }
      }
    }
    if (rc == -1) {
      throw new IllegalStateException();
    }
    String resC = Integer.toString(rc);
    String resJ = Integer.toString(rj);
    while (resC.length() != c.length()) {
      resC = "0" + resC;
    }
    while (resJ.length() != j.length()) {
      resJ = "0" + resJ;
    }
    return new String[] { resC, resJ };
  }

  private BigInteger res = null;
  private String rc = "";
  private String rj = "";

  void init() {
    res = null;
    rc = "";
    rj = "";
  }

  void test(String c, String j) {
    BigInteger cc = new BigInteger(c);
    BigInteger jj = new BigInteger(j);
    BigInteger rr = cc.subtract(jj).abs();
    if (res == null || res.compareTo(rr) > 0) {
      res = rr;
      rc = c;
      rj = j;
    } else if (res.compareTo(rr) == 0) {
      int compC = rc.compareTo(c);
      if (compC > 0 || (compC == 0 && rj.compareTo(j) > 0)) {
        res = rr;
        rc = c;
        rj = j;
      }
    }
  }

  private boolean test(String c, String j, int index, String pc, String pj, char cc, char jj) {
    String tc = pc + cc;
    String tj = pj + jj;
    if (cc > jj) {
      for (int i = index + 1; i < c.length(); i++) {
        if (c.charAt(i) == '?') {
          tc += '0';
        } else {
          tc += c.charAt(i);
        }
        if (j.charAt(i) == '?') {
          tj += '9';
        } else {
          tj += j.charAt(i);
        }
      }
      test(tc, tj);
    } else {
      for (int i = index + 1; i < c.length(); i++) {
        if (c.charAt(i) == '?') {
          tc += '9';
        } else {
          tc += c.charAt(i);
        }
        if (j.charAt(i) == '?') {
          tj += '0';
        } else {
          tj += j.charAt(i);
        }
      }
      test(tc, tj);
    }

    return cc == jj;
  }

  private void doSolve(String c, String j, int index, String pc, String pj) {
    if (index >= c.length()) {
      test(pc, pj);
      return;
    }

    char cc = c.charAt(index);
    char jj = j.charAt(index);

    if (cc == '?') {
      if (jj == '?') {
        test(c, j, index, pc, pj, '0', '1');
        test(c, j, index, pc, pj, '1', '0');
        doSolve(c, j, index + 1, pc + '0', pj + '0');
      } else {
        if (jj != '0') {
          test(c, j, index, pc, pj, (char)(jj - 1), jj);
        }
        if (jj != '9') {
          test(c, j, index, pc, pj, (char)(jj + 1), jj);
        }
        doSolve(c, j, index + 1, pc + jj, pj + jj);
      }
    } else {
      if (jj == '?') {
        if (cc != '0') {
          test(c, j, index, pc, pj, cc, (char)(cc - 1));
        }
        if (cc != '9') {
          test(c, j, index, pc, pj, cc, (char)(cc + 1));
        }
        doSolve(c, j, index + 1, pc + cc, pj + cc);
      } else {
        if (cc != jj) {
          test(c, j, index, pc, pj, cc, jj);
        } else {
          doSolve(c, j, index + 1, pc + cc, pj + jj);
        }
      }
    }
  }

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File(NAME + ".in"));

      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      for (int test = 1; test <= tests; test++) {
        //put solution here
        init();
        String c = in.next();
        String j = in.next();
        //String[] res = solve(c, j);
        doSolve(c, j, 0, "", "");
//        if (!(rc.equals(res[0]) && rj.equals(res[1]))) {
//          System.out.println("fail");
//          System.out.println("test: " + c + " " + j);
//          System.out.println("dump res " + res[0] + " " + res[1]);
//          System.out.println("hard res " + rc + " " + rj);
//        }
        out.println("Case #" + test + ": " + rc + " " + rj);
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Match()).start();
  }
}
