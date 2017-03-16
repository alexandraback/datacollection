import java.util.*;

public class C {
  
  private static final boolean isPerfectSquare(long n) {
    if (n < 0) {
      return false;
    }
    long tst = (long)(Math.sqrt(n) + 0.5);
    return tst * tst == n;
  }
  
  private static final boolean isPalin(long orig) {
    long reversed = 0, n = orig;
    while (n > 0) {
      reversed = reversed * 10 + n % 10;
      n /= 10;
    }
    return orig == reversed;
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for (int k = 1; k <= n; k++) {
      long A = in.nextLong();
      long B = in.nextLong();
      long count = 0;
      for (long i = A; i <= B; i++) {
        if (isPerfectSquare(i) && isPalin(i) && isPalin(Math.round(Math.sqrt(i)))) {
          count++;
        }
      }
      System.out.printf("Case #%d: %d\n", k, count);
    }
    in.close();
  }

}