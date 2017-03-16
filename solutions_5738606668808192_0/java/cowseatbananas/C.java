import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class C {
  public static Random gen = new Random();

  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int tc = 1; tc <= T; ++tc) {
      int N = in.nextInt();
      int J = in.nextInt();

      System.out.print("Case #");
      System.out.print(tc);
      System.out.println(":");
      for (long x = (1L << (N - 1)) + 1; (x < (1L << N)) && J > 0; x += 2) {
        String xs = Long.toBinaryString(x);

        boolean ok = true;
        for (int base = 2; base <= 10; ++base) {
          BigInteger y = (base == 2) ? BigInteger.valueOf(x) : new BigInteger(xs, base);
          if (y.isProbablePrime(40)) {
            ok = false;
            break;
          }
        }

        if (!ok) continue;
        BigInteger[] factors = new BigInteger[11];
        for (int base = 2; base <= 10; ++base) {
          BigInteger y = (base == 2) ? BigInteger.valueOf(x) : new BigInteger(xs, base);
          factors[base] = pollardRho(y);
          if (factors[base].equals(BigInteger.ZERO) ||
              factors[base].equals(y)) {
            ok = false;
            break;
          }
        }
        if (!ok) continue;
        System.out.print(Long.toBinaryString(x));
        for (int base = 2; base <= 10; ++base) {
          System.out.print(" ");
          System.out.print(factors[base]);
        }
        System.out.print("\n");
        --J;
      }
    }
  }

  public static BigInteger pollardRho(BigInteger y) {
    BigInteger x = new BigInteger(y.bitLength(), gen);
    BigInteger x2 = x;
    BigInteger c = new BigInteger(y.bitLength(), gen);
    BigInteger d;

    BigInteger two = BigInteger.valueOf(2);
    if (y.mod(two).equals(BigInteger.ZERO)) return two;

    int iters = 0;
    do {
      if (++iters > 3000) return BigInteger.ZERO;
      x = x.multiply(x).mod(y).add(c).mod(y);
      x2 = x2.multiply(x2).mod(y).add(c).mod(y);
      x2 = x2.multiply(x2).mod(y).add(c).mod(y);
      d = x.subtract(x2).gcd(y);
    } while (d.equals(BigInteger.ONE));

    return d;
  }
}
