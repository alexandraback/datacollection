import java.util.*;

public class CountingSheep {
  public static void main(String []args) {
    Scanner in = new Scanner(System.in);
    final int T = in.nextInt();
    for (int i = 1; i <= T; i++) {
      final int N = in.nextInt();
      int f = finalValue(N);
      System.out.println("Case #" + i + ": " + (f == 0? "INSOMNIA": f));
    }
  }
  
  private static int finalValue(int n) {
    if (n == 0) return 0;
    boolean []seen = new boolean[10];
    boolean []s2 = new boolean[10];
    for (int i = 1; ; i++) {
      hasDigit(s2, i * n);
      or(seen, s2);
      if (hasAll(seen)) return i * n;
    }
  }
  
  private static void hasDigit(boolean []b, int n) {
    for (int i = 0; i < b.length; i++) b[i] = false;
    if (n == 0) {
      b[0] = true;
      return;
    }
    while (n > 0) {
      b[n % 10] = true;
      n /= 10;
    }
    return;
  }
  
  private static void or(boolean []b1, boolean []b2) {
    for (int i = 0; i < b1.length; i++)
      b1[i] |= b2[i];
  }
  
  private static boolean hasAll(boolean []digits) {
    for (int i = 0; i < digits.length; i++)
      if (!digits[i]) return false;
    return true;
  }
}