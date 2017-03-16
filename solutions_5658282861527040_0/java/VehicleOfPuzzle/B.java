import java.util.*;

class B {
  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    for (int tcc = sc.nextInt(), tc = 1; tc <= tcc; ++tc) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      int k = sc.nextInt();
      int ans = 0;
      for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
          if ((i & j) < k) ++ans;
        }
      }
      System.out.printf("Case #%d: %d%n", tc, ans);
    }
  }
}
