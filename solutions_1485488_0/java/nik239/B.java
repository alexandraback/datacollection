import java.io.*;
import java.util.*;

/**
 * @author nik
 */
public class B {
  private static final int[][] DIRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("B-small-attempt0.in"));
    PrintWriter out = new PrintWriter("b.out");
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int h = in.nextInt();
      int n = in.nextInt();
      int m = in.nextInt();
      Cave[][] caves = new Cave[n][m];
      for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
          caves[x][y] = new Cave(x, y);
        }
      }
      for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
          caves[x][y].ceil = in.nextInt();
        }
      }
      for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
          caves[x][y].floor = in.nextInt();
        }
      }
      SortedSet<Cave> next = new TreeSet<Cave>();
      caves[0][0].t = 0;
      next.add(caves[0][0]);
      Cave exit = caves[n-1][m-1];
      while (!exit.reached) {
        Cave cur = next.first();
        next.remove(cur);
        cur.reached = true;
        for (int[] dir : DIRS) {
          int nx = cur.x+dir[0];
          int ny = cur.y+dir[1];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          Cave nc = caves[nx][ny];
          if (nc.reached || nc.floor > cur.ceil-50 || nc.floor > nc.ceil-50 || cur.floor > nc.ceil-50) continue;
          int nh = nc.ceil - 50;
          double nt = Math.max(cur.t, (h-nh)*0.1);
          if (nt > 1e-5) {
            if (h-10*nt >= cur.floor+20-1e-7) {
              nt += 1;
            }
            else {
              nt += 10;
            }
          }
          next.remove(nc);
          nc.t = Math.min(nc.t, nt);
          next.add(nc);
        }
      }

      out.printf(Locale.US, "Case #"+t+": %.6f\n", exit.t);
    }
    out.close();
    in.close();
  }

  private static final class Cave implements Comparable<Cave> {
    public final int x, y;
    public int ceil, floor;
    public double t = 1e10;
    public boolean reached;

    private Cave(int x, int y) {
      this.x = x;
      this.y = y;
    }

    public int compareTo(Cave o) {
      int z = Double.compare(t, o.t);
      if (z != 0) return z;
      if (x < o.x) return -1;
      if (x > o.x) return 1;
      if (y < o.y) return -1;
      if (y > o.y) return 1;
      return 0;
    }
  }
}
