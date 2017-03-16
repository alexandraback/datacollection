import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * @author damnecki
 */
public class A {

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new File("a/data/A-small-attempt0.in"));
    PrintWriter pw = new PrintWriter("a/data/A-small-attempt0.out");
//    Scanner sc = new Scanner(new File("a/data/A-local.in"));
//    PrintWriter pw = new PrintWriter("a/data/A-local.out");
    int T = sc.nextInt();
    BigInteger P, Q;
    for (int i = 0; i < T; i++) {
      String s = sc.next();
      P = new BigInteger(s.split("/")[0]);
      Q = new BigInteger(s.split("/")[1]);
      String result = "Case #" + (i + 1) + ": " + test(P, Q) + "\n";
      pw.write(result);
      System.out.print(result);
    }
    sc.close();
    pw.close();
  }

  private static String test(BigInteger P, BigInteger Q) {
    int gen = 0;
    int g = 0;
    BigInteger TWO = new BigInteger("2");
    while (gen < 40) {
      if (BigInteger.ZERO.equals(P) || P.equals(Q)) {
        break;
      }
      gen++;
      BigInteger gcd = P.gcd(Q);
      P = P.divide(gcd);
      Q = Q.divide(gcd);
      P = P.multiply(TWO);
      if (P.compareTo(Q) >= 0) {
        P = P.subtract(Q);
        if (g == 0) {
          g = gen;
        }
      }

    }
    if (gen == 40) {
      return "impossible";
    }
    return String.valueOf(g);
  }

  private static class Factor {
    static int a;
    static int b;

    Factor(int a, int b) {
      this.a = a;
      this.b = b;
    }
  }
}
