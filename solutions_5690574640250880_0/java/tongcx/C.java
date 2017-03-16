import java.util.*;

class C {
  static void paintGrid(char[][] grid, int R, int C) {
    for (int i = 0; i < R; i++)
      for (int j = 0; j < C; j++)
        grid[i][j] = '.';
  }

  static char[][] solve(int R, int C, int B) {
    char[][] grid = new char[R][C];
    for (int i = 0; i < R; i++)
      Arrays.fill(grid[i], '*');
    if (R == 1)
      paintGrid(grid, 1, B);
    else if (R == 2) {
      if (B == 2 || (B%2 == 1 && B != 1))
        return null;
      if (B%2 == 0)
        paintGrid(grid, 2, B/2);
    } else {
      if (B == 1) {
      } else if (B == 2 || B == 3 || B == 5 || B == 7)
        return null;
      else if (B == 4)
        paintGrid(grid, 2, 2);
      else if (B == 6)
        paintGrid(grid, 3, 2);
      else {
        if (B <= 3*R) {
          if (B % 3 == 2) {
            paintGrid(grid, B/3+1, 2);
            paintGrid(grid, B/3, 3);
          } else if (B % 3 == 0) {
            paintGrid(grid, B/3, 3);
          } else {
            paintGrid(grid, B/3+1, 2);
            paintGrid(grid, B/3-1, 3);
          }
        } else {
          if (B%R == 1) {
            paintGrid(grid, R, B/R);
            grid[R-1][B/R - 1] = '*';
            grid[0][B/R] = '.';
            grid[1][B/R] = '.';
          } else {
            paintGrid(grid, R, B/R);
            paintGrid(grid, B%R, B/R+1);
          }
        }
      }
    }
    grid[0][0] = 'c';
    return grid;
  }

  static char[][] transpose(char[][] A) {
    if (A == null) return null;
    int n = A.length, m = A[0].length;
    char[][] B = new char[m][n];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        B[j][i] = A[i][j];
    return B;
  }

  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();
    for (int caseNo = 1; caseNo <= T; caseNo++) {
      int R = cin.nextInt(), C = cin.nextInt(), M = cin.nextInt();
      int B = R*C - M;
      System.out.format("Case #%d:\n", caseNo);
      char[][] res;
      if (R > C) {
        res = transpose(solve(C, R, B));
      } else {
        res = solve(R, C, B);
      }
      if (res == null)
        System.out.println("Impossible");
      else {
        for (int i = 0; i < R; i++)
          System.out.println(res[i]);
      }
    }
  }
}
