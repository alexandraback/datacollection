import java.util.*;

class B {
  private static final int MAX = 100;

  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    int tcc = sc.nextInt();
    for (int tc = 1; tc <= tcc; ++tc) {
      int r = sc.nextInt();
      int c = sc.nextInt();
      int[][] grid = new int[r][c];
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          grid[i][j] = sc.nextInt();
        }
      }

      int[] counts = new int[MAX + 1];
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          ++counts[grid[i][j]];
        }
      }

      boolean possible = true;
      for (int h = 1; h < MAX && possible;) {
        int nh = h + 1;
        while (nh < MAX && counts[nh] == 0) ++nh;

        boolean[] rowFull = new boolean[r];
        for (int i = 0; i < r; ++i) {
          rowFull[i] = true;
          for (int j = 0; j < c; ++j) if (grid[i][j] != h) {
            rowFull[i] = false;
            break;
          }
        }

        boolean[] colFull = new boolean[c];
        for (int j = 0; j < c; ++j) {
          colFull[j] = true;
          for (int i = 0; i < r; ++i) if (grid[i][j] != h) {
            colFull[j] = false;
            break;
          }
        }

        for (int i = 0; i < r && possible; ++i) {
          for (int j = 0; j < c && possible; ++j) {
            if (grid[i][j] == h) {
              grid[i][j] = nh;
              possible = rowFull[i] || colFull[j];
            }
          }
        }

        h = nh;
      }

      System.out.printf("Case #%d: ", tc);
      System.out.println(possible ? "YES" : "NO");
    }
  }
}
