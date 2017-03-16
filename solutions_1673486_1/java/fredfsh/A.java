import java.io.*;
import java.lang.*;
import java.util.*;

public class A {
  private int H, W, D;
  private boolean[][] isEmpty;
  private int manx, many;
  private Map<String, Boolean> images = new HashMap<String, Boolean>();

  public static void main(String[] args) {
    A prob = new A();
    prob.run(args[0]);
  }

  public void run(String fileName) {
    try {
      Scanner fin = new Scanner(new File(fileName));
      PrintWriter fout = new PrintWriter(new File(fileName + ".out"));

      int T = fin.nextInt();
      for (int t = 1; t <= T; ++t) {
        fout.format("Case #%d: ", t);

        int A = fin.nextInt();
        int B = fin.nextInt();
        double[] p = new double[A];
        for (int i = 0; i < A; ++i) p[i] = fin.nextDouble();

        double result = B + 2;
        double pc = 1;
        double temp;
        int X = B - A;
        for (int i = A; i >= 0; --i) {
          if (i == A) {
            pc = 1;
          } else {
            pc *= p[A - i - 1];
          }
          temp = 2 * i + X + 1 + (1 - pc) * (B + 1);
          result = Math.min(result, temp);
        }

        fout.format("%.6f\n", result);
      }

      fin.close();
      fout.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
