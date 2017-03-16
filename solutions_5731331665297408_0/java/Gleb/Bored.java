import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Bored implements Runnable {
  private static final String NAME = "bor";

  int n;
  String res = "";
  String[] s;
  int[] path;
  int[] prev;

  boolean[][] g;
  boolean[] f;
  boolean[] w;

  private String getRes() {
    StringBuilder b = new StringBuilder();
    for (int i = 0; i < n - 1; i++) {
      b.append(s[path[i]]);
    }
    return b.toString();
  }

  private void go(int v, int num) {
    //System.out.println(v + " " + Arrays.toString(prev) + " " + num);
    boolean sF = !f[v];
    boolean sW = !w[v];
    if (sF) f[v] = true;
    if (sW) w[v] = true;

    boolean[] myF = Arrays.copyOf(f, n);
    boolean[] myW = Arrays.copyOf(w, n);
    int[] myP = Arrays.copyOf(path, n);
    int[] myPrev = Arrays.copyOf(prev, n);

    if (num == n - 1) {
      String cur = getRes();
      if ((res.length() == 0) || cur.compareTo(res) < 0) res = cur;
    } else {
      for (int i = 0; i < n; i++) if (g[v][i] && !f[i]) {
        prev[i] = v;
        if (!w[i]) {
          path[num] = i;
          go(i, num + 1);
        } else {
          go(i, num);
        }
        f = myF;
        w = myW;
        path = myP;
        prev = myPrev;
      }
      if (prev[v] >= 0) go(prev[v], num);
      f = myF;
      w = myW;
      path = myP;
      prev = myPrev;
    }
    if (sF) f[v] = false;
    if (sW) w[v] = false;
  }

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File(NAME + ".in"));
      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      for (int test = 1; test <= tests; test++) {
        n = in.nextInt() + 1;
        int m = in.nextInt();
        s = new String[n - 1];
        for (int i = 0; i < n - 1; i++) {
          s[i] = in.next();
        }
        g = new boolean[n][n];
        for (int i = 0; i < m; i++) {
          int a = in.nextInt() - 1;
          int b = in.nextInt() - 1;
          g[a][b] = true;
          g[b][a] = true;
        }
        f = new boolean[n];
        w = new boolean[n];
        path = new int[n];
        res = "";
        prev = new int[n];

        int min = 0;
        for (int i = 0; i < n - 1; i++) {
          if (s[i].compareTo(s[min]) < 0) min = i;
        }

        for (int i = 0; i < n; i++) if (g[min][i]) {
          g[n - 1][i] = true;
          g[i][n - 1] = true;
        }
        path[0] = min;
        prev[min] = -1;
        w[n - 1] = true;
        f[n - 1] = true;
        go(min, 1);
        out.println("Case #" + test + ": " + res);
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Bored()).start();
  }
}
