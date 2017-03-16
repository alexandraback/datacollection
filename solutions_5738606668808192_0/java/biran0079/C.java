import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Ran Bi (ran.bi@addepar.com)
 */
public class C {

  static List<BigInteger> primes = new ArrayList<>();

  static void findPrimes(int n) {
    boolean[] p = new boolean[n];
    Arrays.fill(p, true);
    p[0] = p[1] = false;
    int k = 2;
    while (k < n) {
      if (p[k]) {
        primes.add(BigInteger.valueOf(k));
        for (int i = 2 * k; i < n; i += k) {
          p[i] = false;
        }
      }
      k++;
    }
  }

  static List<BigInteger> test(BigInteger v) {
    List<BigInteger> res = new ArrayList<>();
    for (int base = 2; base <= 10; base++) {
      BigInteger t = new BigInteger(v.toString(2), base);
      if (t.isProbablePrime(10) || !findFactor(t, res)) {
        return null;
      }
    }
    return res;
  }

  private static boolean findFactor(BigInteger v, List<BigInteger> res) {
    for (BigInteger p : primes) {
      if (v.remainder(p).equals(BigInteger.ZERO)) {
        res.add(p);
        return true;
      }
    }
    return false;
  }

  public static void main(String[] args) {
    findPrimes(10000);
    int N = 16;
    int J = 50;
    BigInteger two = BigInteger.valueOf(2);
    BigInteger st = two.pow(N - 1).add(BigInteger.ONE);
    List<String> res = new ArrayList<>();
    while (res.size() < J) {
      List<BigInteger> l = test(st);
      if (l != null) {
        StringBuilder sb = new StringBuilder();
        sb.append(st.toString(2));
        l.stream().forEach(i -> sb.append(' ').append(i));
        res.add(sb.toString());
      }
      st = st.add(two);
    }
    System.out.println("Case #1:");
    res.stream().forEach(System.out::println);
  }
}
