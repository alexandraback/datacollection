import java.io.File;
import java.util.Scanner;

public class cj5 {
  public static void main(String[] args) throws Exception {
    final Scanner scanner = new Scanner(new File("D:\\unsorted\\in.txt"));
    final int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      final int E = scanner.nextInt();
      final int R = scanner.nextInt();
      final int N = scanner.nextInt();
      final int[] v = new int[N];
      for (int n = 0; n < N; n++)
        v[n] = scanner.nextInt();

      System.out.println("Case #" + t + ": " + max(v, N, 0, E, R, E));
    }
  }

  public static int max(int[] v, int N, int current, int energy, int R, int E) {
    if (current == N) return 0;

    int best = 0;
    for (int i = 0; i <= energy; i++) {
      best = Math.max(best, i * v[current] + max(v, N, current + 1, Math.min(E, energy - i + R), R, E));
    }

    return best;
  }
}
