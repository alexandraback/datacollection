import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class QA {

  static long sqr(long a){
    return a*a;
  }

  public static void main(String[] args) {
    final String PREFIX = "/home/saul/IdeaProjects/CodeJam1A/src/";

    try {
      Scanner sc = new Scanner(new File(PREFIX + "A-large.in"));
      //Scanner sc = new Scanner(new File(PREFIX + "QA.in"));
      PrintWriter out = new PrintWriter(new File(PREFIX + "QA.out"));
      //PrintWriter out = new PrintWriter(System.out);
      int n = sc.nextInt();
      for (int iCases = 0; iCases < n; iCases++) {
        BigInteger ans = new BigInteger("0");
        long r = sc.nextLong() , t = sc.nextLong();
        BigInteger min = BigInteger.ONE , max = new BigInteger("100000000000");
        BigInteger two = new BigInteger("2");
        BigInteger ra = new BigInteger(r + "");
        BigInteger tt = new BigInteger(t + "");
        while ( min.compareTo(max) <= 0 ){
          BigInteger mid = (min.add(max).divide(new BigInteger("2")));
          BigInteger needed = mid.multiply( two.multiply(mid).add( two.multiply(ra).subtract(BigInteger.ONE) ) );
          if ( needed.compareTo(tt) <= 0 ){
            ans = mid;
            min = mid.add(BigInteger.ONE);
          }else{
            max = mid.subtract(BigInteger.ONE);
          }
        }

        System.err.println("CASE " + iCases);
        out.println("Case #" + (iCases+1) + ": " + ans);
      }
      out.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

}
