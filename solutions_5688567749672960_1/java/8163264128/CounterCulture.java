import java.util.*;

public class CounterCulture {
  public static void main(String []args) {
    Scanner in = new Scanner(System.in);
    final int T = in.nextInt();
    for (int i = 1; i <= T; i++) {
      final long N = in.nextLong();
      long zero = (N % 10L == 0L? 1L: 0L);
      System.out.println("Case #" + i + ": " + (zero + f(N - zero)));
    }
    in.close();
  }

  public static long f(long n) {
    if (n < 10) return n;
    long acc = 2L + f(pow(digits(n) - 1) - 1L);
    int []dArray = digitArray(n);
    acc += (dArray[0] - 1) + (dArray[dArray.length - 1] - 1);
    boolean zeroes = true;
    for (int i = 1; i < dArray.length / 2; i++) {
      acc += (dArray[i] + dArray[dArray.length - 1 - i]) * pow(i);
      zeroes &= (dArray[i] == 0);
    }
    if (!(dArray[0] == 1 && zeroes)) acc += 1;
    if (dArray.length % 2 == 1) {
      acc += dArray[dArray.length / 2] * pow(dArray.length / 2);
    }
    return acc;
  }

  public static int digits(long n) {
    int l = 0;
    while (n > 0L) {
      n /= 10L;
      l++;
    }
    return l;
  }

  public static long pow(int e) {
    long p = 1L;
    while (e-- > 0) p *= 10L;
    return p;
  }

  public static int[] digitArray(long n) {
    int []res = new int[digits(n)];
    for (int i = res.length - 1; i >= 0; i--) {
      res[i] = (int)(n % 10);
      n /= 10L;
    }
    return res;
  }
}
