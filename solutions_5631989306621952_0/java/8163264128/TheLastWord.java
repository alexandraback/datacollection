import java.util.*;

public class TheLastWord {
  public static void main(String []args) {
    Scanner in = new Scanner(System.in);
    final int T = in.nextInt();
    for (int i = 1; i <= T; i++) {
      final String S = in.next();
      String y = "" + S.charAt(0);
      for (int j = 1; j < S.length(); j++) {
        if (y.charAt(0) <= S.charAt(j)) y = S.charAt(j) + y;
        else y = y + S.charAt(j);
      }
      System.out.println("Case #" + i + ": " + y);
    }
  }
}