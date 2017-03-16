import java.math.*;
import java.util.*;

class A {
  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    BigInteger two = BigInteger.valueOf(2);
    for (int tc = 1, tcc = Integer.parseInt(sc.nextLine()); tc <= tcc; ++tc) {
      String[] parts = sc.nextLine().split("\\/");
      BigInteger p = new BigInteger(parts[0]);
      BigInteger q = new BigInteger(parts[1]);
      BigInteger g = p.gcd(q);
      p = p.divide(g);
      q = q.divide(g);
      String rep = q.toString(2);
      String ans = "impossible";
      if (rep.matches("10*")) {
        int a = rep.length() - 1;
        while (!p.equals(BigInteger.ONE)) {
          --a;
          p = p.divide(two);
          q = q.divide(two);
        }
        ans = "" + a;
      }
      System.out.printf("Case #%d: %s%n", tc, ans);
    }
  }
}
