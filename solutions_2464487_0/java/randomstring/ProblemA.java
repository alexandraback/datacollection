import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;


public class ProblemA implements Problem {

  protected BigInteger r, t;

  public ProblemA (Scanner s) {
    r = s.nextBigInteger();
    t = s.nextBigInteger();
  }

  @Override
  public String solve () {
    BigInteger square = r.multiply(new BigInteger("2")).subtract(new BigInteger("1")).pow(2).add(t.multiply(new BigInteger("8")));
    BigInteger four_square = square.multiply(new BigInteger("16"));
    BigInteger four_sqrt = big_sqrt(four_square);
    BigInteger four_answer = four_sqrt.add(new BigInteger("4")).subtract(r.multiply(new BigInteger("8")));
    BigInteger answer = four_answer.divide(new BigInteger("16"));
//    System.out.println("square: " + square.toString());
//    System.out.println("four_square: " + four_square.toString());
//    System.out.println("four_sqrt: " + four_sqrt.toString());
//    System.out.println("four_answer: " + four_answer.toString());
//    System.out.println("answer: " + answer.toString());
    return answer.toString();
  }

  BigInteger big_sqrt(BigInteger n) {
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
