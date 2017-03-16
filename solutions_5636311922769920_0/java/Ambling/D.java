package qualification;

import java.util.Scanner;

class D {
  public static long power(long a, long pow) {
    long re = 1;
    while (pow > 0) {
      re *= a;
      -- pow;
    }
    return re;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      // TODO

      int K = scanner.nextInt();
      int C = scanner.nextInt();
      int S = scanner.nextInt();

      String re = " IMPOSSIBLE";
      if (C * S >= K) {
        int need = (int)Math.ceil(1.0 * K / C);
        long[] checks = new long[need];

        int now = 0;
        for (int i = 0; i < need; i++) {
          long check = 0;
          int pow = C - 1;
          while (pow >= 0 && now < K) {
            check += power(K, pow) * now;
            -- pow;
            ++ now;
          }

          checks[i] = check + 1;
        }

        re = "";
        for (long check: checks) {
          re = re + " " + check;
        }
      }

      System.out.printf("Case #%d:%s\n", t, re);
    }
  }
}