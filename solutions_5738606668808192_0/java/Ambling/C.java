package qualification;

import java.util.Scanner;

class C {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      // TODO

      int N = scanner.nextInt();
      int J = scanner.nextInt();

      int[] bits = new int[N/2];
      for (int i = 0; i < bits.length; i++) {
        if (i == 0 || i == bits.length-1) {
          bits[i] = 1;
        } else {
          bits[i] = 0;
        }
      }

      System.out.printf("Case #%d:\n", t);
      for (int i = 0; i < J; i++) {
        int value = i;
        for (int b = 1; b < bits.length-1; b++) {
          bits[b] = value % 2;
          value /= 2;
        }

        for (int repeat = 0; repeat < 2; repeat ++) {
          for (int b = bits.length-1; b >= 0; b--) {
            System.out.print(bits[b]);
          }
        }

        for (int divider = 2; divider <= 10; divider ++) {
          System.out.print(" " + (long)(Math.pow(divider, N/2)+1));
        }

        System.out.print("\n");
      }
    }
  }
}