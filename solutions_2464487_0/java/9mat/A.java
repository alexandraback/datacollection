import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class A{
  static BigInteger sqrt(BigInteger n) {
    BigInteger a = BigInteger.ONE;
    BigInteger b = n.shiftRight(5).add(new BigInteger("8"));
    while(b.compareTo(a) >= 0) {
      BigInteger mid = a.add(b).shiftRight(1);
      if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
      else a = mid.add(BigInteger.ONE);
    }
    return a.subtract(BigInteger.ONE);
  }
  
  static BigInteger floorsqrt(BigInteger n){
    BigInteger a = sqrt(n);
    if(a.multiply(a).compareTo(n) > 0) a = a.subtract(BigInteger.ONE);
    BigInteger a1 = new BigInteger(a.add(BigInteger.ONE).toString());
    if(a1.multiply(a1).compareTo(n) <= 0) a = a1;
    return a;
  }
  
  static BigInteger ceilsqrt(BigInteger n){
    BigInteger a = sqrt(n);
    if(a.multiply(a).compareTo(n) < 0) a = a.add(BigInteger.ONE);
    BigInteger a1 = a.subtract(BigInteger.ONE);
    if(a1.multiply(a1).compareTo(n) >= 0) a = a1;
    return a;
  }
  
  static boolean isfair(BigInteger n){
    String a = n.toString().trim();
    String b = new StringBuilder(a).reverse().toString();
    return a.equals(b);
  }

  public static void main(String [ ] args){
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    BigInteger r, t, k, two = new BigInteger("2"), eight = new BigInteger("8"), four = new BigInteger("4"), k1, rr;
    for(int casenbr = 1; casenbr <= T; casenbr++){
      r = new BigInteger(sc.next());
      t = new BigInteger(sc.next());
      rr = r.multiply(two).subtract(BigInteger.ONE);
      k = floorsqrt(rr.multiply(rr).add(t.multiply(eight))).subtract(rr).divide(four);
      if(k.multiply(k.multiply(two).add(rr)).compareTo(t) > 0) k = k.subtract(BigInteger.ONE);
      else {
        k1 = k.add(BigInteger.ONE);
        if(k1.multiply(k1.multiply(two).add(rr)).compareTo(t) <= 0) k = k1;
      }
      System.out.println("Case #" + casenbr + ": " + k.toString());
    }    
  }
}
