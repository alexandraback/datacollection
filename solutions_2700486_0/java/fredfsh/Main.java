import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) throws Exception {
    Main p = new Main();
    p.run(args[0]);
  }

  private void run(String inputFileName) throws Exception {
    Scanner fin = new Scanner(new BufferedInputStream(
          new FileInputStream(inputFileName)));
    PrintWriter fout = new PrintWriter(new BufferedWriter(
          new FileWriter(inputFileName + ".out")));

    T = fin.nextInt();
    fin.nextLine();
    for (int tt = 1; tt <= T; ++tt) {
      //input
      N = fin.nextInt();
      int X = fin.nextInt();
      if (X < 0) X = -X;
      int Y = fin.nextInt();

      //run
      double result = 0;
      int n = getLayer(N);
      --n;
      do {
        if ((X + Y) > 2 * n) {
          result = 0;
          break;
        }

        if ((n == 0) || ((X + Y) <= 2 * (n - 1))) {
          result = 1.0;
          break;
        }

        int K = N - (2 * n * n - n);
        int L = Y + 1;
        double[] prob = new double[2 * n + 2];
        if (K == 4 * n + 1) {
          result = 1.0;
          break;
        }
        if (K <= 2 * n) {
          if (L > K) {
            result = 0;
            break;
          }
          prob[1] = 1 - Math.pow(.5, K);
          for (int i = 2; i <= K; ++i) {
            prob[i] = 1 - (1 - prob[i-1] + c(K, i-1));
            //System.out.println(" i = " + i + ", " + prob[i]);
          }
          result = prob[L];
        } else {
          // 4 * n + 1 > K > 2 * n
          int R = K - 2 * n;
          if (L <= R) {
            result = 1.0;
            break;
          }
          int S = L - R;
          int T = K - 2 * R;
          prob[1] = 1 - Math.pow(.5, T);
          for (int i = 2; i <= T; ++i) {
            prob[i] = 1 - (1 - prob[i-1] + c(T, i-1));
          }
          if (L == 2 * n + 1) {
            result = 0;
          } else {
            result = prob[S];
          }
        }

      } while (false);

      //output
      fout.printf("Case #%d: %.4f\n", tt, result);
    }

    fin.close();
    fout.close();
  }

  private int getLayer(int xx) {
    double x = xx;
    int n = (int) Math.ceil(Math.sqrt(x/2.0 + 1.0/16.0) + .25);
    // double check
    if (2 * n * n - n < xx) return n + 1;
    if (2 * (n-1) * (n-1) - (n-1) >= xx) return n - 1;
    return n;
  }

  private double c(int n, int r) {
    double result = Math.pow(.5, n);
    for (int i = 0; i < r; ++i) {
      result *= (double) (n - i) / (double) (r - i);
    }
    return result;
  }

  private int T;
  private int N, M;
}
