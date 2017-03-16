package r1a;

import java.math.BigInteger;
import java.util.Scanner;

public class A {
  static long solveSmall(long r , long t){
    long ret = 0;
    while(t > 0){      
      long need = 2 * r + 1;
      if(need > t){
        break;
      }
      ++ret;
      t -= need;
      r += 2;
    }
    return ret;
  }
  
  static BigInteger area(long r , long n){
    BigInteger bn = BigInteger.valueOf(n);
    BigInteger bm = BigInteger.valueOf(2 * r + 2 * n - 1);
    return bn.multiply(bm);
  }
  
  static long solveLarge(long r , long t){
    BigInteger bt = BigInteger.valueOf(t);
    int ret = 0;
    int M = 100000;
    while(true){
      BigInteger a = area(r , ret + M);
//      System.out.println(ret+" "+a+" "+bt);
      if(a.compareTo(bt) >= 0){
        break;
      }
      ret += M;
    }    
    while(true){
      BigInteger a = area(r , ret + 1);      
      if(a.compareTo(bt) >= 0){
        break;
      }
      ret++;
    }
    return ret;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for(int cn = 1 ; cn <= T ; ++cn){
      long r = sc.nextLong();
      long t = sc.nextLong();
//      System.out.printf("Case #%d: %d\n" , cn , solveSmall(r,t));
      System.out.printf("Case #%d: %d\n" , cn , solveLarge(r,t));
    }
  }
}
