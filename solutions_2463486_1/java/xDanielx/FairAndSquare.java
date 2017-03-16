import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FairAndSquare {
  public static void main(String[] args) {
    List<Long> fairAndSquareNumbers = new ArrayList<Long>();
    for (long n = 0; n <= 1e7; ++n)
      if (isPalindrome(n) && isPalindrome(n * n))
        fairAndSquareNumbers.add(n * n);

    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int t = 1; t <= T; ++t) {
      long A = sc.nextLong(), B = sc.nextLong();
      int count = 0;
      for (long n : fairAndSquareNumbers)
        if (A <= n && n <= B)
          ++count;
      System.out.printf("Case #%d: %d\n", t, count);
    }
  }

  private static boolean isPalindrome(long l) {
    String s = Long.toString(l);
    return s.equals(new StringBuilder(s).reverse().toString());
  }
}
