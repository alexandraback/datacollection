import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;


public class B {

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));


    String ss = reader.readLine();
    int n = Integer.parseInt(ss);

    for (int i = 0; i < n; i++) {
      Map<String, Integer> map = new HashMap<String, Integer>();
      ss = reader.readLine();

      String[] p = ss.split(" ");
      int H = Integer.parseInt(p[0]);
      int N = Integer.parseInt(p[1]);
      int M = Integer.parseInt(p[2]);

      int[][] floor = new int[N][M];
      int[][] ceil = new int[N][M];

      for (int j = 0; j < N; j++) {
        ss = reader.readLine();
        p = ss.split(" ");
        for (int k = 0; k < p.length; k++) {
          ceil[j][k] = Integer.parseInt(p[k]);
        }
      }
      for (int j = 0; j < N; j++) {
        ss = reader.readLine();
        p = ss.split(" ");
        for (int k = 0; k < p.length; k++) {
          floor[j][k] = Integer.parseInt(p[k]);
        }
      }

      int[] dx = new int[]{1, 0, -1, 0};
      int[] dy = new int[]{0, -1, 0, 1};

      // fill
      int[][] x = new int[N][M];
      List<Point> queue = new LinkedList<Point>();
      queue.add(new Point(0, 0));
      x[0][0] = 1;
      while (!queue.isEmpty()) {
        Point q = queue.remove(0);
        for (int d = 0; d < 4; d++) {
          int x1 = q.x + dx[d];
          int y1 = q.y + dy[d];
          if (x1 < 0 || x1 >= M) {
            continue;
          }
          if (y1 < 0 || y1 >= N) {
            continue;
          }
          if (Math.max(H, floor[q.y][q.x]) > ceil[y1][x1] - 50) {
            continue;
          }
          if (ceil[q.y][q.x] - 50 < Math.max(H, floor[y1][x1])) {
            continue;
          }
          if (x[y1][x1] == 0) {
            x[y1][x1] = 1;
            queue.add(new Point(x1, y1));
            continue;
          }
        }
      }

      // fill
      double[][] y = new double[N][M];

      List<Point> queue2 = new LinkedList<Point>();
      for (int i1 = 0; i1 < N; i1++) {
        for (int i2 = 0; i2 < M; i2++) {
          y[i1][i2] = -1;
          if (x[i1][i2] == 1) {
            y[i1][i2] = 0;
            queue2.add(new Point(i2, i1));
          }
        }
      }

      while (!queue2.isEmpty()) {
        Point q = queue2.remove(0);

        for (int d = 0; d < 4; d++) {
          int x1 = q.x + dx[d];
          int y1 = q.y + dy[d];
          if (x1 < 0 || x1 >= M) {
            continue;
          }
          if (y1 < 0 || y1 >= N) {
            continue;
          }

          // move for 1 sec
          boolean good = true;
          if (Math.max(H - y[q.y][q.x] * 10, floor[q.y][q.x]) > ceil[y1][x1] - 50) {
            good = false;
          }
          if (ceil[q.y][q.x] - 50 < Math.max(H - y[q.y][q.x] * 10, floor[y1][x1])) {
            good = false;
          }
          if (good) { 
            double t = 10;
            if (H - y[q.y][q.x] * 10 >= floor[q.y][q.x] + 20) {
              t = 1;
            }
            if (y[y1][x1] == -1 || y[y1][x1] > y[q.y][q.x] + t) {
              y[y1][x1] = y[q.y][q.x] + t;
              queue2.add(new Point(x1, y1));
            }
          } else {
            double tt = -1;
            double tt1 = -1;
            double tt2 = -1;
            // check for the water going down
            if (floor[q.y][q.x] <= ceil[y1][x1] - 50) {
              tt1 = ((H - y[q.y][q.x] * 10) - (ceil[y1][x1] - 50)) / (double) 10;
            }
            if (ceil[q.y][q.x] - 50 >= floor[y1][x1]) {
              tt2 = ((H - y[q.y][q.x] * 10) - (ceil[q.y][q.x] - 50)) / (double) 10;
            }
            tt = Math.max(tt1, tt2);
            if (tt > 0) {
              double t = 10;
              if (H - (y[q.y][q.x] + tt) * 10 >= floor[q.y][q.x] + 20) {
                t = 1;
              }
              if (y[y1][x1] == -1 || y[y1][x1] > y[q.y][q.x] + t + tt) {
                y[y1][x1] = y[q.y][q.x] + t + tt;
                queue2.add(new Point(x1, y1));
              }
            }
          }
        }
      }

      String res = "" + y[N - 1][M - 1];

      String sss = "Case #" + (i + 1) + ": " + res;
      System.out.println(sss);
    }
  }
}
