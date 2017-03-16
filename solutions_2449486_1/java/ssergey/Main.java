import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-large.out")));
    Solver solver = new Solver();
    solver.solve(in, out);
    in.close();
    out.close();
  }
}

class Solver {

  public void d(int[][] a) {
    System.out.println();
    for (int i = 0; i < a.length; i++) {
      for (int j = 0; j < a[i].length; j++) {
        System.out.print(a[i][j]);
        System.out.print(" ");
      }
      System.out.println();
    }
  }

  public void solve(BufferedReader in, PrintWriter out) throws IOException {
    int ntest = Integer.parseInt(in.readLine());
    for (int itest = 1; itest <= ntest; itest++) {
      StringTokenizer st = new StringTokenizer(in.readLine());
      int n = Integer.parseInt(st.nextToken());
      int m = Integer.parseInt(st.nextToken());
      int[][] t = new int[n][m];
      for (int i = 0; i < n; i++) {
        st = new StringTokenizer(in.readLine());
        for (int j = 0; j < m; j++) {
          t[i][j] = Integer.parseInt(st.nextToken());
        }
      }
      int[][] src = new int[n][m];
      for (int i = 0; i < n; i++) {
        Arrays.fill(src[i], 100);
      }
      int[] minRow = new int[n];
      int[] minCol = new int[m];
      int[] maxRow = new int[n];
      int[] maxCol = new int[m];

      while (true) {
        Arrays.fill(minRow, Integer.MAX_VALUE);
        Arrays.fill(maxRow, -1);
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            minRow[i] = Math.min(minRow[i], t[i][j]);
            maxRow[i] = Math.max(maxRow[i], t[i][j]);
          }
        }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            if (src[i][j] > maxRow[i]) {
              src[i][j] = maxRow[i];
            }
            if (minRow[i] == maxRow[i]) {
              src[i][j] = maxRow[i];
            }
          }
        }
        Arrays.fill(minCol, Integer.MAX_VALUE);
        Arrays.fill(maxCol, -1);
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            minCol[j] = Math.min(minCol[j], t[i][j]);
            maxCol[j] = Math.max(maxCol[j], t[i][j]);
          }
        }
        boolean changed = false;
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
            if (src[j][i] > maxCol[i]) {
              src[j][i] = maxCol[i];
            }
            if (minCol[i] == maxCol[i]) {
              if (src[j][i] != maxCol[i]) {
                changed = true;
              }
              src[j][i] = maxCol[i];
            }
          }
        }

        if (!changed) {
          break;
        }
      }
      d(src);
      boolean can = true;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          can &= (t[i][j] == src[i][j]);
        }
      }
      out.print(String.format("Case #%d: ", itest));
      if (can) {
        out.println("YES");
      } else {
        out.println("NO");
      }
    }
  }
}
