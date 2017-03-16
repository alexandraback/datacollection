import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.*;

public class CoinJam {

  private static final BigInteger TWO = new BigInteger("2");
  private static final BigInteger ITER = new BigInteger("10000");

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new File("data/coinjam/C-small-attempt0.in"));
    PrintStream ps = new PrintStream("data/coinjam/out");
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      Map<BigInteger, List<Long>> result = calc(sc.nextInt(), sc.nextInt());
      ps.printf("Case #%d:\n", t);
      //System.out.printf("Case #%d:\n", t);
      for (Map.Entry<BigInteger, List<Long>> entry : result.entrySet()) {
        ps.print(entry.getKey().toString(2));
        //System.out.print(entry.getKey().toString(2));
        for (Long div : entry.getValue()) {
          ps.print(" " + div);
          //System.out.print(" " + div);
        }
        ps.println();
        //System.out.println();
      }
    }
  }

  private static Map<BigInteger, List<Long>> calc(int n, int j) {
    BigInteger number = new BigInteger("2").pow(n - 1).add(BigInteger.ONE);
    Map<BigInteger, List<Long>> result = new TreeMap<BigInteger, List<Long>>();
    int ii = 0;
    while (result.size() < j) {
      if (!isPrime(number)) {
        List<Long> divisors = divisors(number);
        if (!divisors.contains(0L)) {
          result.put(number, divisors);
        }
      }
      number = number.add(TWO);
    }
    return result;
  }

  private static boolean isPrime(BigInteger number) {
    boolean prime = false;
    for (int i = 2; i <= 10; i++) {
      BigInteger num = new BigInteger(number.toString(2), i);
      prime = num.isProbablePrime(10);
      if (prime) {
        break;
      }
    }
    return prime;
  }

  private static List<Long> divisors(BigInteger numberInBase2) {
    List<Long> divisors = new ArrayList<Long>();
    for (int i = 2; i <= 10; i++) {
      divisors.add(divisor(numberInBase2, i));
    }
    return divisors;
  }

  private static long divisor(BigInteger numberInBase2, int base) {
    BigInteger number = new BigInteger(numberInBase2.toString(2), base);
    //BigInteger numDived = number.divide(TWO);
    for (BigInteger i = TWO; i.compareTo(ITER) < 0; i = i.add(BigInteger.ONE)) {
      BigInteger[] divRes = number.divideAndRemainder(i);
      if (divRes[1].equals(BigInteger.ZERO)) {
        return i.longValue();
      }
    }
    return 0;
  }
}
