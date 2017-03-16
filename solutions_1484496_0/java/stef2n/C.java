import java.util.ArrayList;
import java.util.Scanner;

public class C {

  static ArrayList<Integer>[] lists;

  static int N;
  static Scanner scanner = new Scanner(System.in);
  static int[] x;

  static void generate(int k, int s, int mask) {
    if (k == N) {
      lists[s].add(mask);
      return;
    }
    generate(k + 1, s, mask);
    generate(k + 1, s + x[k], mask | (1 << k));
  }

  public static void main(String[] args) {
    lists = new ArrayList[2000001];
    for (int i = 0; i < 2000001; ++i)
      lists[i] = new ArrayList<Integer>();

    int T = scanner.nextInt();
    for (int t = 1; t <= T; ++t) {
      N = scanner.nextInt();
      x = new int[N];
      for (int i = 0; i < N; ++i)
        x[i] = scanner.nextInt();
      for (ArrayList list : lists)
        list.clear();
      generate(0, 0, 0);

      System.out.println("Case #" + t + ":");
      boolean stop = false;
      for (ArrayList list : lists) {
        for (Object m1 : list) {
          for (Object m2 : list) {
            if (m1 != m2) {
              int mask1 = (Integer) m1;
              int mask2 = (Integer) m2;
              if ((mask1 & mask2) == 0) {
                for (int i = 0; i < N; ++i)
                  if ((mask1 & (1 << i)) != 0)
                    System.out.print(x[i] + " ");
                System.out.println();

                for (int i = 0; i < N; ++i)
                  if ((mask2 & (1 << i)) != 0)
                    System.out.print(x[i] + " ");
                System.out.println();

                stop = true;
                break;
              }
            }
          }
          if (stop)
            break;
        }
        if (stop)
          break;
      }

      if (!stop)
        System.out.println("Impossible");
    }
  }
}
