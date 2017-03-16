import java.util.*;

class Main {
  final static int MAX = 1000000;

  static int reverse(int n) {
    StringBuilder sb = new StringBuilder(n + "");
    sb.reverse();
    String s = sb.toString().replaceAll("^0*(\\d)", "$1");
    return Integer.parseInt(s);
  }

  public static void main(String[] args) {
    int[] memo = new int[1 + MAX];
    for (int i = 2; i <= MAX; ++i) memo[i] = Integer.MAX_VALUE - 100;
    memo[1] = 1;
    for (int i = 2; i <= MAX; ++i) {
      if (memo[i-1] + 1 < memo[i]) memo[i] = memo[i-1] + 1;
      int ir = reverse(i);
      if (memo[i] + 1 < memo[ir]) memo[ir] = memo[i] + 1;
    }

    Scanner sc = new Scanner(System.in);
    int tcc = sc.nextInt();
    for (int tc = 1; tc <= tcc; ++tc) {
      System.out.printf("Case #%d: %s\n", tc, memo[sc.nextInt()]);
    }
  }
}
