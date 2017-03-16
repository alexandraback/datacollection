import java.util.*;
import java.math.*;

class Diamonds
{
  public static void main(String... args)
  {
    Scanner sc = new Scanner(System.in);

    int tests = sc.nextInt();
    for (int test = 1; test <= tests; ++test)
    {
      int n = sc.nextInt();
      int x = sc.nextInt();
      int y = sc.nextInt();
      System.out.println("Case #" + test + ": " + solve(n, x, y));
    }
  }

  public static double solve(int n, int x, int y)
  {
    x = x < 0 ? -x : x;
    int index = (x + y) / 2;
    int prevIndex = index - 1;
    n -= (prevIndex + 1) * (1 + 2 * prevIndex);
    if (n <= 0)
    {
      return 0.0;
    }
    if (n >= (1 + 4*index))
    {
      return 1.0;
    }
    int y1 = y + 1;
    if ((n - 2 * index) >= y1)
    {
      return 1.0;
    }
    if (x == 0)
    {
      return 0.0;
    }
    if (y1 > n)
    {
      return 0.0;
    }
    BigInteger numerator = BigInteger.ZERO;
    for (int i = 0; i < y1; ++i)
    {
      numerator = numerator.add(choose(n, i));
    }
    return 1.0 - (numerator.doubleValue() * Math.pow(0.5, n));
  }
  public static BigInteger choose(int n, int k)
  {
    k = Math.max(k, n-k);
    BigInteger result = BigInteger.ONE;
    for (int i = k+1; i <= n; ++i)
    {
      result = result.multiply(BigInteger.valueOf(i));
    }
    for (int i = 1; i <= n - k; ++i)
    {
      result = result.divide(BigInteger.valueOf(i));
    }
    return result;
  }
}
