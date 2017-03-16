import java.util.*;
import java.math.*;

public class A {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int cases = in.nextInt();
    for(int z=1;z<=cases;++z) {
      long startRadius = in.nextLong();
      long mls = in.nextLong();
      long ans = 0;
      long min = 0;
      long max = 999999999;
      while (min <= max) {
        long mid = (min+max)/2;
        BigInteger a = BigInteger.valueOf(mid);
        a = a.multiply(new BigInteger("-3"));
        BigInteger b = BigInteger.valueOf(mid);
        b = b.multiply(BigInteger.valueOf(startRadius));
        b = b.multiply(new BigInteger("2"));
        BigInteger c = BigInteger.valueOf(mid);
        c = c.multiply(BigInteger.valueOf(mid+1));
        c = c.multiply(new BigInteger("2"));
        BigInteger sum = a.add(b).add(c);
        // System.err.println(mid + " " + sum + " " + mls);
        if (!BigInteger.valueOf(sum.longValue()).equals(sum) || sum.longValue() > mls) {
          max = mid-1;
        } else {
          ans = mid;
          min = mid+1;
        }
      }
      System.out.printf("Case #%d: %d\n", z, ans);
    }
  } 
}