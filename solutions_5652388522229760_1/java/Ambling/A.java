package qualification;

import java.util.*;

class A {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      // TODO

      int N = scanner.nextInt();
      int end = 0;
      if (N != 0) {
        HashSet<Integer> set = new HashSet<Integer>(10);
        for (int i = 0; i < 10; i++) {
          set.add(i);
        }

        int k = 1;
        while (!set.isEmpty()) {
          int number = N * k;
          end = number;
          while (number > 0) {
            set.remove(number % 10);
            number /= 10;
          }
          ++ k;
        }
      }

      System.out.printf("Case #%d: %s\n", t, end == 0?"INSOMNIA":""+end);
    }
  }
}