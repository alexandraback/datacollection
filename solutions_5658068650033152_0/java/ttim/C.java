package codejam.r1c;

import codejam.Task;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C extends Task {
  public static void main(String[] args) throws IOException {
//    runConsole(new C());
    runSmall(new C(), 0);
//    runLarge(new C());
  }

  @Override
  protected String getName() {
    return "C";
  }

  @Override
  protected void runOne(Scanner input, PrintWriter output) {
    int n = input.nextInt();
    int m = input.nextInt();
    int k = input.nextInt();

    output.println(runRec(new int[n][m], 0, 0, 0, n, m, k));
  }

  private static int runRec(int[][] field, int i, int j, int count, int n, int m, int k) {
    if (i == n) {
      // check, return count or MAX_VALUE
      int[][] copy = new int[n][m];
      for (int ni = 0; ni < n; ni++) {
        for (int nj = 0; nj < m; nj++) {
          copy[ni][nj] = field[ni][nj];
        }
      }
      boolean changed = true;
      while (changed) {
        changed = false;
        for (int ni = 0; ni < n; ni++) {
          for (int nj = 0; nj < m; nj++) {
            if (copy[ni][nj] == 0) {
              if (ni == 0 || nj == 0 || ni == n - 1 || nj == m - 1) {
                copy[ni][nj] = 2;
                changed = true;
              } else {
                if (copy[ni - 1][nj] == 2 || copy[ni + 1][nj] == 2 || copy[ni][nj - 1] == 2 || copy[ni][nj + 1] == 2) {
                  copy[ni][nj] = 2;
                  changed = true;
                }
              }
            }
          }
        }
      }

      int curCount = n*m;
      for (int ni = 0; ni < n; ni++) {
        for (int nj = 0; nj < m; nj++) {
          if (copy[ni][nj] == 2) {
            curCount--;
          }
        }
      }

      if (curCount >= k) {
        return count;
      } else {
        return Integer.MAX_VALUE;
      }
    }

    int ni = i, nj = j + 1;
    if (nj == m) {
      ni++;
      nj = 0;
    }

    int ans1 = runRec(field, ni, nj, count, n, m, k);
    field[i][j] = 1;
    int ans2 = runRec(field, ni, nj, count + 1, n, m, k);
    field[i][j] = 0;

    return Math.min(ans1, ans2);
  }
}
