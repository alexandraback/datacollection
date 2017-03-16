import java.util.*;

public class C {
  private static int[] answer = {
    134217727,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    134217215,
    0,
    0,
    134213630,
    134209013,
    0,
    0,
    0,
    0,
    133955071,
    0,
    0,
    131854334,
    127131125,
    0,
    115310070,
    79358373,
    22102794,
    134217727,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    134217727,
    0,
    0,
    134217727,
    134217727,
    0,
    0,
    0,
    0,
    133955583,
    0,
    0,
    131858431,
    127139839,
    0,
    117436414,
    83873788,
    62580637
  };
  private static void printAll(int ti, int j, int p, int s) {
    int count = j * p * s;
    System.out.println("Case #" + ti + ": " + count);
    for (int ji = 1; ji <= j; ji++)
      for (int pi = 1; pi <= p; pi++)
        for (int si = 1; si <= s; si++)
          System.out.println("" + ji + " " + pi + " " + si);
  }

  private static void printAnswer(int ti, int j, int p, int s, int k) {
    int ans = answer[j - 1 + (p - 1) * 3 + (s - 1) * 9 + (k - 1) * 27];
    int count = 0;
    for (int i = 0; i < 27; i++) {
      int x = (ans >> i) & 1;
      if (x == 1) {
        int c1 = i % 3;
        int c2 = i / 3 % 3;
        int c3 = i / 9;
        if (c1 < j && c2 < p && c3 < s)
          count++;
      }
    }
    System.out.println("Case #" + ti + ": " + count);
    for (int i = 0; i < 27; i++) {
      int x = (ans >> i) & 1;
      if (x == 1) {
        int c1 = i % 3;
        int c2 = i / 3 % 3;
        int c3 = i / 9;
        if (c1 < j && c2 < p && c3 < s)
          System.out.println("" + (c1 + 1) + " " + (c2 + 1) + " " + (c3 + 1));
      }
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    for (int ti = 1; ti <= t; ti++) {
      int j = sc.nextInt();
      int p = sc.nextInt();
      int s = sc.nextInt();
      int k = sc.nextInt();
      if (k >= 3)
        printAll(ti, j, p, s);
      else
        printAnswer(ti, j, p, s, k);
    }
  }
}
