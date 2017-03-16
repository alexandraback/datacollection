import java.io.*;
import java.util.*;

public class C {
  
  static final int maxn = 2000010;
  static int A, B;
  static boolean was[] = new boolean[maxn];
  static long ans;

  static void examine(int x) {
    String s = "" + x;
    int n = s.length();

    int num = 1;
    was[x] = true;
    for (int i = 1; i < n; i++) {
      s = s.substring(1) + s.charAt(0);
      if (s.charAt(0) == '0') continue;

      int y = Integer.parseInt(s);
      if (was[y]) break;
      if (y >= A && y <= B) {
        was[y] = true;
        num++;
      }
    }

    ans += num * (num - 1) / 2;
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(new InputStreamReader(System.in));
    int T = in.nextInt();
    for (int q = 1; q <= T; q++) {
      Arrays.fill(was, false);
      ans = 0;
      A = in.nextInt(); B = in.nextInt();
      for (int i = A; i <= B; i++) {
        if (was[i]) continue;
        examine(i);
      }
      System.out.printf("Case #%d: %d\n", q, ans);
    }
  }
}
