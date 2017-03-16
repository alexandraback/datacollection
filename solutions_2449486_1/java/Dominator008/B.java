import java.util.*;

public class B {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    outer:
    for (int k = 1; k <= n; k++) {
      int N = in.nextInt();
      int M = in.nextInt();
      int[] maxOfRow = new int[N];
      int[] maxOfCol = new int[M];
      int[][] lawn = new int[N][M];
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          lawn[i][j] = in.nextInt();
        }
      }
      for (int i = 0; i < N; i++) {
        int rmax = 0;
        for (int j = 0; j < M; j++) {
          int curr = lawn[i][j];
          if (curr >= rmax) {
            rmax = curr;
          }
        }
        maxOfRow[i] = rmax;
      }
      for (int j = 0; j < M; j++) {
        int cmax = 0;
        for (int i = 0; i < N; i++) {
          int curr = lawn[i][j];
          if (curr >= cmax) {
            cmax = curr;
          }
        }
        maxOfCol[j] = cmax;
      }
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          int curr = lawn[i][j];
          if (curr < maxOfCol[j] &&  curr < maxOfRow[i]) {
            System.out.printf("Case #%d: NO\n", k);
            continue outer;
          }
        }
      }
      System.out.printf("Case #%d: YES\n", k);
    }
    in.close();
  }
}