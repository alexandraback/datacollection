import java.io.File;
import java.util.Scanner;

public class cj2 {
  public static void main(String[] args) throws Exception {
    final Scanner scanner = new Scanner(new File("D:\\unsorted\\in.txt"));
    final int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      final int N = scanner.nextInt(), M = scanner.nextInt();
      final int[][] desired = new int[N][M];
      for (int n = 0; n < N; n++)
        for (int m = 0; m < M; m++)
          desired[n][m] = scanner.nextInt();
      String result = getResult(desired, N, M);
      System.out.println("Case #" + t + ": " + result);
    }
  }

  public static String getResult(final int[][] desired, final int N, final int M) {
    final int[][] current = new int[N][M];
    for (int n = 0; n < N; n++)
      for (int m = 0; m < M; m++)
        current[n][m] = 100;

    cut(desired, N, M, current);
    return isDone(desired, N, M, current) ? "YES" : "NO";
  }

  public static void cut(final int[][] desired, final int N, final int M, final int[][] current) {
    for (int n = 0; n < N; n++) {
      int cut = desired[n][0];
      for (int m = 1; m < M; m++)
        cut = Math.max(cut, desired[n][m]);
      for (int m = 0; m < M; m++)
        current[n][m] = Math.min(current[n][m], cut);
    }
    for (int m = 0; m < M; m++) {
      int cut = desired[0][m];
      for (int n = 1; n < N; n++)
        cut = Math.max(cut, desired[n][m]);
      for (int n = 0; n < N; n++)
      current[n][m] = Math.min(current[n][m], cut);
    }
  }

  public static boolean isDone(final int[][] desired, final int N, final int M, final int[][] current) {
    for (int n = 0; n < N; n++)
      for (int m = 0; m < M; m++)
        if (desired[n][m] != current[n][m])
          return false;
    return true;
  }
}
