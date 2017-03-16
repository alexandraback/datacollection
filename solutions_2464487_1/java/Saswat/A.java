import java.io.*;
import java.util.*;
import java.math.*;

public class A {
  public static void main (String[] args) throws java.lang.Exception
  {
  	 PrintWriter output = new PrintWriter(System.out, true);
     Scanner sc = new Scanner(System.in);
	 Integer T = sc.nextInt();

	 BigInteger TWO = new BigInteger("2");
	 BigInteger FOUR = new BigInteger("4");
	 BigInteger EIGHT = new BigInteger("8");
	 
    for(int i = 1; i <= T; i++) {
    		BigInteger r = sc.nextBigInteger();
    		BigInteger t = sc.nextBigInteger();
    		
    		BigInteger k = (sqrt(r.multiply(r).multiply(FOUR).add(BigInteger.ONE).subtract(r.multiply(FOUR)).add(t.multiply(EIGHT))).add(BigInteger.ONE).subtract(r.multiply(TWO))).divide(FOUR);
            output.printf("Case #%d: %s\n", i, k);
    }
  }
  
  public static BigInteger sqrt(BigInteger n) {
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
