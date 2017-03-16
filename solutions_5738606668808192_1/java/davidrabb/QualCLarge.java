package jam2016;

import java.util.*;
import java.io.*;
import java.lang.invoke.MethodHandles;
import java.math.BigInteger;
/**
 *
 * @author David
 */
public class QualCLarge {
  public static void main(String[] args) {
    System.out.println("Case #1:");
    int count = 0;
    //for(int i=0; i<10; i++) {
    //for(long i=0; i<16383; i++) {
    for(long i=0; i<1073741823L; i++) {
      String s = Long.toString(i, 2);
      while(s.length()<30) s = "0"+s;
      s = "1"+s+"1";
      long[] divisors = isJamcoin(s);
      if (divisors!=null) {
        //System.out.print((count)+" ");
        System.out.print(s);
        for(int k=0; k<divisors.length; k++) {
          System.out.print(" "+divisors[k]);
        }
        System.out.println();
        if (count++>498) break;
      }
    }
  }
  
  public static long[] isJamcoin(String c) {
    long[] divisors = new long[9];
    for(int r=2; r<=10; r++) {
      BigInteger b = new BigInteger(c, r);
      long d = divisor(b);
      if (d==-1) return null;
      divisors[r-2] = d;
    }
    return divisors;
  }
  
  public static long divisor(BigInteger d) {
    if (d.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO)) return 2;
    if (d.mod(BigInteger.valueOf(3)).equals(BigInteger.ZERO)) return 3;
    if (d.mod(BigInteger.valueOf(5)).equals(BigInteger.ZERO)) return 5;
    if (d.mod(BigInteger.valueOf(7)).equals(BigInteger.ZERO)) return 7;
    
    BigInteger max = sqrt(d).add(BigInteger.ONE);
    for(long i=3; i<max.longValue(); i+=2) {
      if (i>1000001) {
        return -1;// taking too long
      }
      if (d.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO)) {
        return i;
      }
    }
    return -1;
    
  }
  static BigInteger sqrt(BigInteger n) {
    BigInteger a = BigInteger.ONE;
    BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
    while(b.compareTo(a) >= 0) {
      BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
      if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
      else a = mid.add(BigInteger.ONE);
    }
    return a.subtract(BigInteger.ONE);
  }

}
