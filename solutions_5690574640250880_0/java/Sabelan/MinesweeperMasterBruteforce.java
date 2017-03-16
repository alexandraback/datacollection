import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class MinesweeperMasterBruteforce {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("MinesweeperMaster.in"));
    PrintWriter out = new PrintWriter(new File("MinesweeperCorrect.out"));
    int cases = in.nextInt();
    for (int co = 1; co <= cases; co++) {
      r = in.nextInt();
      c = in.nextInt();
      int m = in.nextInt();
      need = r * c - m;
      b = new char[r][c];
      ans = null;
      for (char[] a : b)
        Arrays.fill(a, '.');
      System.out.printf("Case #%d:\n", co);
      out.printf("Case #%d:\n", co);
      if (need == 1) {
        for (int i = 0; i < r; i++)
          for (int j = 0; j < c; j++)
            b[i][j] = '*';
        b[0][0] = 'c';
        for (char[] a : b) {
          System.out.println(new String(a));
          out.println(new String(a));
        }
        continue;
      }
      done = false;
      bf(0, 0, m);
      if (!done) {
        System.out.printf("Impossible\n");
        out.printf("Impossible\n");
      } else {
        for (char[] a : ans) {
          System.out.println(new String(a));
          out.println(new String(a));
        }
      }
    }
    out.close();
  }

  static int r, c, need;
  static char[][] b, ans;
  static boolean done;

  public static void bf(int y, int x, int m) {
    if (done) return;
    if (x == c) {
      bf(y + 1, 0, m);
      return;
    }
    if (y == r) {
      if (verify()) done = true;
      if (done && ans == null) {
        ans = new char[r][c];
        for (int i = 0; i < r; i++)
          for (int j = 0; j < c; j++)
            ans[i][j] = b[i][j];
      }
      return;
    }
    int left = r * c;
    if (y != 0) left -= (y - 1) * c;
    left -= x;
    if (m != 0) {
      b[y][x] = '*';
      bf(y, x + 1, m - 1);
      b[y][x] = '.';
    }
    if (left != m) bf(y, x + 1, m);
  }

  public static boolean verify() {
    visited = new boolean[r][c];
    cnt = 0;
    boolean tested = false;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c && !tested; j++) {
        if (cntNeighbors(b, i, j) == 0) {
          tested = true;
          dfs(b, i, j);
          if (cnt == need) b[i][j] = 'c';
          if (cnt == need) return true;
          return false;
        }
      }
    }
    return false;
  }

  public static int cnt;
  public static boolean[][] visited;

  public static void dfs(char[][] b, int r, int c) {
    if (r < 0 || r >= visited.length || c < 0 || c >= visited[0].length)
      return;
    if (visited[r][c]) return;
    visited[r][c] = true;
    cnt++;
    if (cntNeighbors(b, r, c) == 0) for (int y = r - 1; y <= r + 1; y++)
      for (int x = c - 1; x <= c + 1; x++)
        dfs(b, y, x);
  }

  public static int cntNeighbors(char[][] b, int r, int c) {
    int ans = 0;
    for (int y = r - 1; y <= r + 1 && y < b.length; y++)
      for (int x = c - 1; x <= c + 1 && x < b[0].length; x++) {
        if (y < 0 || x < 0) continue;
        if (b[y][x] == '*') ans++;
      }
    return ans;
  }
}
