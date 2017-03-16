import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class FallingDiamonds {
  public static int offset = 500;

  public BufferedReader br;
  public int n, x, y, t, cnt;
  public double ans;
  public boolean[][] state;

  public void DFS(int k, int num) {
    if (k == n) {
      if (state[x+offset][y])
        cnt += num;
      return;
    }
    int dx = offset;
    int dy = 500;
    while (dy >= 2 && !state[dx][dy-2])
      dy -= 2;
    if (dy == 0) {
      state[dx][dy] = true;
      DFS(k + 1, num);
      state[dx][dy] = false;
    }
    else if (state[dx-1][dy-1] && state[dx+1][dy-1]) {
      state[dx][dy] = true;
      DFS(k + 1, num);
      state[dx][dy] = false;
    }
    else if (state[dx+1][dy-1]) {
      while (dy >= 1 && !state[dx-1][dy-1]) {
        dx--;
        dy--;
      }
      state[dx][dy] = true;
      DFS(k + 1, num);
      state[dx][dy] = false;
    }
    else if (state[dx-1][dy-1]) {
      while (dy >= 1 && !state[dx+1][dy-1]) {
        dx++;
        dy--;
      }
      state[dx][dy] = true;
      DFS(k + 1, num);
      state[dx][dy] = false;
    }
    else {
      int tx = dx;
      int ty = dy;
      while (dy >= 1 && !state[dx-1][dy-1]) {
        dx--;
        dy--;
      }
      state[dx][dy] = true;
      DFS(k + 1, num >> 1);
      state[dx][dy] = false;
      dx = tx;
      dy = ty;
      while (dy >= 1 && !state[dx+1][dy-1]) {
        dx++;
        dy--;
      }
      state[dx][dy] = true;
      DFS(k + 1, num >> 1);
      state[dx][dy] = false;
    }
  }

  public void go() throws Throwable {
    br = new BufferedReader(new InputStreamReader(System.in));
    t = Integer.parseInt(br.readLine());
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      String[] ss = br.readLine().split(" +");
      n = Integer.parseInt(ss[0]);
      x = Integer.parseInt(ss[1]);
      y = Integer.parseInt(ss[2]);
      if (x < -500 || x > 500 || y > 500)
        System.out.println("Case #" + caseNo + ": 0.0");
      else {
        cnt = 0;
        state = new boolean[1005][1005];
        DFS(0, 1 << n);
        ans = (double) cnt / (double) (1 << n);
      	System.out.println("Case #" + caseNo + ": " + ans);
      }
    }
  }

  public static void main(String[] args) throws Throwable {
    new FallingDiamonds().go();
  }
}
