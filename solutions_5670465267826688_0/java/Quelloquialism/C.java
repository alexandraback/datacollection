import java.util.Scanner;

public class C {
  static int L;
  static long X;
  static char[] s;

  public static void main(String[] args) throws Throwable {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int tc = 1; tc <= T; tc++) {
      L = in.nextInt();
      X = in.nextLong();
      s = in.next().toCharArray();
      boolean good = false;
      int target = 'i';
      int curr = '1';
      int neg = 0;
      for (long i = 0; i < L * X; i++) {
        curr = mult(curr, get(i));
        neg = (curr & 256) ^ neg;
        curr &= ~256;
        if (target <= 'k' && curr == target) {
          target++;
          curr = '1';
        }
      }
      good = neg == 0 && curr == '1' && target > 'k';
      System.out.printf("Case #%d: %s\n", tc, good ? "YES" : "NO");
    }
  }

  static int get(long i) {
    return s[(int)(i % L)];
  }

  /*
   *   | 1 | i | j | k
   * --+---+---+---+---
   * 1 | 1 | i | j | k
   * --+---+---+---+---
   * i | i |-1 | k |-j
   * --+---+---+---+---
   * j | j |-k |-1 | i
   * --+---+---+---+---
   * k | k | j |-i |-1
   * --+---+---+---+---
   */
  static int mult(int a, int b) throws Throwable {
    int neg = (a & 256) ^ (b & 256);
    a &= ~256;
    b &= ~256;
    if (a == '1') {
      return b ^ neg;
    } else if (b == '1') {
      return a ^ neg;
    } else if (a == b) {
      return 256 ^ '1' ^ neg;
    } else if (a == 'i' && b == 'j') {
      return 'k' ^ neg;
    } else if (a == 'i' && b == 'k') {
      return 'j' ^ 256 ^ neg;
    } else if (a == 'j' && b == 'i') {
      return 'k' ^ 256 ^ neg;
    } else if (a == 'j' && b == 'k') {
      return 'i' ^ neg;
    } else if (a == 'k' && b == 'i') {
      return 'j' ^ neg;
    } else if (a == 'k' && b == 'j') {
      return 'i' ^ 256 ^ neg;
    } else {
      throw new Exception(":(");
    }
  }
}
