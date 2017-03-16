import java.util.*;

public class A {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int t = in.nextInt();
    for (int testnum = 1; testnum <= t; ++testnum) {
      String[] frac = (in.next()).split("/");
      long p = Long.parseLong(frac[0]);
      long q = Long.parseLong(frac[1]);
      long gcd = gcd(p, q);
      p /= gcd;
      q /= gcd;
      long maxpow = 1L << 40;
      while (q < maxpow) {
        p <<= 1;
        q <<= 1;
      }
      boolean possible = (q == maxpow && p != 0);
      int count = 0;
      while (p > 0) {
        p >>= 1;
        ++count;
      }
      System.out.printf("Case #%d: ", testnum);
      if (!possible) {
        System.out.printf("%s\n", "impossible");
      } else {
        System.out.printf("%d\n", 40 - count + 1);
      }
    }
  }
  
  public static long gcd(long a, long b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }
}