import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class bullseye {
  
  static BigInteger two = BigInteger.valueOf(2);
  
  public static void main(String[] args) throws IOException {
    
    Scanner in = new Scanner(new File("bullseye.in"));
    PrintWriter out = new PrintWriter(new File("bullseye.out"));
    int cases = in.nextInt();
    int caseOn = 1;
    
    // while (cases-- != 0) {
    // long r = in.nextLong();
    // long t = in.nextLong();
    //
    // int cnt = 0;
    // while (true) {
    // long paint = 2 * r + 1;
    // if (paint <= t) {
    // t -= paint;
    // cnt++;
    // } else {
    // break;
    // }
    // r += 2;
    // }
    //
    // out.printf("Case #%d: %d\n", caseOn++, cnt);
    // }
    
    while (cases-- > 0) {
      long r = in.nextLong();
      long t = in.nextLong();
      
      BigInteger paint = BigInteger.valueOf(t);
      
      long best = 0;
      long l = 0, h = t / 2;
      while (l <= h) {
        long m = (l + h) / 2;
        BigInteger paintNeeded = paintNeeded(r, m);
        
        if (paintNeeded.compareTo(paint) <= 0) {
          best = m;
          l = m + 1;
        } else {
          h = m - 1;
        }
      }
      
      out.printf("Case #%d: %d\n", caseOn++, best);
    }
    
    out.close();
  }
  
  public static BigInteger paintNeeded(long initR, long numRings) {
    boolean even = initR % 2 == 0;
    BigInteger temp = BigInteger.valueOf(initR).add(
        BigInteger.valueOf((numRings - 1) * 2));
    BigInteger ret = findSumToZero(temp, even);
    ret = ret.subtract(findSumToZero(initR - 2, even));
    ret = ret.multiply(two);
    ret = ret.add(BigInteger.valueOf(numRings));
    return ret;
  }
  
  public static BigInteger findSumToZero(long top, boolean even) {
    return findSumToZero(BigInteger.valueOf(top), even);
  }
  
  public static BigInteger findSumToZero(BigInteger top, boolean even) {
    if (top.compareTo(BigInteger.ZERO) <= 0) return BigInteger.ZERO;
    if (!even) {
      // Sum of all odd numbers is number of odd terms squared:
      BigInteger b = top.add(BigInteger.ONE).divide(two);
      return b.multiply(b);
    }
    // Even is number of even terms = n:
    // ans = N*(N+1)
    BigInteger b = top.divide(two);
    return b.multiply(b.add(BigInteger.ONE));
  }
}
