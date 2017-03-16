import java.util.*;
import java.math.BigInteger;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();

    for(int CASE = 1; CASE <= T; CASE++){
      BigInteger r = sc.nextBigInteger();
      BigInteger t = sc.nextBigInteger();

      BigInteger base = r.add(BigInteger.ONE).multiply(r.add(BigInteger.ONE)).subtract(r.multiply(r));
      BigInteger lo = BigInteger.ONE;
      BigInteger hi = new BigInteger("800000000");

      while(lo.add(BigInteger.ONE).compareTo(hi) < 0){
        BigInteger mi = lo.add(hi).divide(new BigInteger("2"));

        BigInteger need = mi.multiply(base).add(mi.subtract(BigInteger.ONE).multiply(mi).multiply(new BigInteger("2")));
        if(need.compareTo(t) <= 0){
          lo = mi;
        }
        else{
          hi = mi;
        }
      }

      System.out.println("Case #" + CASE + ": " + lo);
    }
  }
}
