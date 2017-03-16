import java.util.Arrays;
import java.util.Scanner;

public class Lawnmower {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int t = 1; t <= T; ++t) {
      int N = sc.nextInt(), M = sc.nextInt();
      int[][] lawn = new int[N][M];
      for (int r = 0; r < N; ++r)
        for (int c = 0; c < M; ++c)
          lawn[r][c] = sc.nextInt();
      System.out.printf("Case #%d: %s\n", t, possible(lawn) ? "YES" : "NO");
    }
  }

  private static boolean possible(int[][] target) {
    int[][] lawn = new int[target.length][target[0].length];
    for (int[] row : lawn)
      Arrays.fill(row, 100);

    for (int r = 0; r < target.length; ++r) {
      int targetMax = 0;
      for (int c = 0; c < target[r].length; ++c)
        targetMax = Math.max(targetMax, target[r][c]);
      for (int c = 0; c < target[r].length; ++c)
        lawn[r][c] = Math.min(lawn[r][c], targetMax);
    }

    for (int c = 0; c < target[0].length; ++c) {
      int targetMax = 0;
      for (int r = 0; r < target.length; ++r)
        targetMax = Math.max(targetMax, target[r][c]);
      for (int r = 0; r < target.length; ++r)
        lawn[r][c] = Math.min(lawn[r][c], targetMax);
    }

    return Arrays.deepEquals(lawn, target);
  }
}
