import java.io.*;
import java.util.Scanner;

public class Lawn implements Runnable {
  int nextInt(StreamTokenizer in) throws Exception {
    in.nextToken();
    return (int) in.nval;
  }

  @Override
  public void run() {
    try {
      StreamTokenizer in = new StreamTokenizer(new BufferedReader(new FileReader("lawn.in")));
      PrintWriter out = new PrintWriter("lawn.out");

      int tests = nextInt(in);

      for (int test = 1; test <= tests; test++) {
        int n = nextInt(in);
        int m = nextInt(in);
        int[][] l = new int[n][m];
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++)
            l[i][j] = nextInt(in);

        int[] w = new int[n];
        int[] h = new int[m];
        for (int i = 0; i < n; i++) {
          int max = l[i][0];
          for (int j = 0; j < m; j++) max = Math.max(max, l[i][j]);
          w[i] = max;
        }
        for (int i = 0; i < m; i++) {
          int max = l[0][i];
          for (int j = 0; j < n; j++) max = Math.max(max, l[j][i]);
          h[i] = max;
        }

        boolean ok = true;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            if (w[i] != l[i][j] && h[j] != l[i][j]) ok = false;
          }
        }
        out.print("Case #" + test + ": ");
        if (ok) out.println("YES");
        else out.println("NO");
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Lawn()).start();
  }
}
