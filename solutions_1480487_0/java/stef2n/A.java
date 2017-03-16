import java.util.Scanner;

public class A {

  static int current;
  static int N, X;
  static int[] s;
  static Scanner scanner = new Scanner(System.in);

  static double binarySearch(double lo, double hi) {
    double mid = (lo + hi) / 2.;
    if (hi - lo < 1.e-7)
      return mid;

    double total = 0;
    double t = s[current] + X * mid;
    for (int i = 0; i < N; ++i)
      if (i == current) {
        total += mid;
      } else {
        double y = (t - s[i]) / X;
        if (y < 0)
          y = 0;
        total += y;
      }

    if (total > 1 + 1.e-9)
      return binarySearch(lo, mid);
    else
      return binarySearch(mid, hi);
  }

  public static void main(String[] args) {
    int T = scanner.nextInt();
    for (int t = 1; t <= T; ++t) {
      N = scanner.nextInt();
      s = new int[N];
      X = 0;
      for (int i = 0; i < N; ++i) {
        s[i] = scanner.nextInt();
        X += s[i];
      }

      System.out.print("Case #" + t + ":");
      for (int i = 0; i < N; ++i) {
        current = i;
        double result = binarySearch(0, 1);
        System.out.print(" " + (result * 100.));
      }
      System.out.println();
    }
  }
}
