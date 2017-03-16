package jam2016;

import java.util.*;
import java.io.*;
import java.lang.invoke.MethodHandles;
/**
 *
 * @author David
 */
public class QualC {
  public static void main(String[] args) {
    System.out.println("Case #1:");
    int count = 0;
    //for(int i=0; i<10; i++) {
    for(long i=0; i<16383; i++) {
      String s = Long.toString(i, 2);
      while(s.length()<14) s = "0"+s;
      s = "1"+s+"1";
      long[] divisors = isJamcoin(s);
      if (divisors!=null) {
        //System.out.print((count)+" ");
        System.out.print(s);
        for(int k=0; k<divisors.length; k++) {
          System.out.print(" "+divisors[k]);
        }
        System.out.println();
        if (count++>48) break;
      }
    }
  }
  
  public static long[] isJamcoin(String c) {
    long[] divisors = new long[9];
    for(int r=2; r<=10; r++) {
      long i = Long.parseLong(c, r);
      //System.out.println(i+" "+isPrime(i));
      //System.out.println(i);
      long d = divisor(i);
      if (d==-1) return null;
      divisors[r-2] = d;
    }
    return divisors;
  }
  
  public static long divisor(long d) {
    if (d%2==0) return 2;
    if (d%3==0) return 3;
    if (d%5==0) return 5;
    if (d%7==0) return 7;
    
    double max = Math.ceil( Math.pow(d, 0.5));
    for(long i=3; i<max; i+=2) {
      if (d%i==0) {
        return i;
      }
    }
    return -1;
    
  }
  
}
