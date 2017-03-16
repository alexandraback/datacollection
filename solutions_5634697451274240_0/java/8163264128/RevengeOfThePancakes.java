import java.util.*;

public class RevengeOfThePancakes {
  public static void main(String []args) {
    Scanner in = new Scanner(System.in);
    final int T = in.nextInt();
    for (int i = 1; i <= T; i++) {
      final String s = in.next();
      char c = '+';
      int f = 0;
      for (int j = s.length() - 1; j >= 0; j--) {
        if (c != s.charAt(j)) {
          c = s.charAt(j);
          f++;
        }
      }
      System.out.println("Case #" + i + ": " + f);
    }
  }
}