import java.awt.Point;
import java.util.*;

public class C {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int k = 1; k <= T; k++) {
      int R = in.nextInt();
      int C = in.nextInt();
      int M = in.nextInt();
      solve(k, R, C, M);
    }
    in.close();
  }
  
  private static void solve(int k, int R, int C, int M) {
    if (M == 0) {
      System.out.printf("Case #%d: \n", k);
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          if (i == 0 && j == 0) {
            System.out.print("c");
          } else {
            System.out.print(".");
          }
        }
        System.out.println();
      }
      return;
    }
    if (dfs(k, R, C, M) == 0) {
      System.out.printf("Case #%d: \nImpossible\n", k);
    }
  }
  
  private static int bfs(int x, int y, int R, int C, int[] flag) {
    int dir[][] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int ans = 1;
    Queue<Point> queue = new LinkedList<Point>();
    int[] vis = new int[105];
    Arrays.fill(vis, 0);

    queue.add(new Point(x, y));
    vis[x * C + y] = 1;

    while (queue.size() > 0) {
      Point p = queue.poll();
      boolean mark = true;
      for (int i = 0; i < 8; i++) {
        int nx = p.x + dir[i][0], ny = p.y + dir[i][1];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
          if (flag[nx * C + ny] == 1) {
            mark = false;
          }
        }
      }
      if (mark) {
        for (int i = 0; i < 8; i++) {
          int nx = p.x + dir[i][0], ny = p.y + dir[i][1];
          if (nx >= 0 && nx < R && ny >= 0 && ny < C
              && vis[nx * C + ny] == 0) {
            vis[nx * C + ny] = 1;
            ans++;
            queue.add(new Point(nx, ny));
          }
        }
      }
    }
    return ans;
  }
  
  private static int dfs(int k, int R, int C, int M) {
    int comb = (1 << M) - 1;
    int res = R * C - M;

    while (comb < 1 << R * C) {
      int p1 = comb & -comb, p2 = comb + p1;
      comb = ((comb & ~p2) / p1 >> 1) | p2;
      int[] flag = new int[105];
      Arrays.fill(flag, 0);
      int i = 1;
      int j = 0;
      while (true) {
        if ((i & comb) > 0) {
          flag[j] = 1;
        }
        ++j;
        i *= 2;
        if (j >= R * C) {
          break;
        }
      }

      for (int x = 0; x < R; ++x) {
        for (int y = 0; y < C; ++y) {
          if (flag[x * C + y] == 0) {
            if (bfs(x, y, R, C, flag) == res) {
              System.out.printf("Case #%d: \n", k);
              for (int l = 0; l < R; ++l) {
                for (int g = 0; g < C; ++g) {
                  if (l == x && g == y) {
                    System.out.printf("c");
                  } else if (flag[l * C + g] == 1) {
                    System.out.printf("*");
                  } else {
                    System.out.printf(".");
                  }
                }
                System.out.println();
              }
              return 1;
            }
          }
        }
      }
    }
    return 0;
  }
}
