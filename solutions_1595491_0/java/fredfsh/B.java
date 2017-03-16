import java.io.*;
import java.lang.*;
import java.util.*;

public class B {
  public static void main(String[] args) {
    B prob = new B();
    prob.run(args[0]);
  }

  public void run(String fileName) {
    try {
      Scanner fin = new Scanner(new File(fileName));
      PrintWriter fout = new PrintWriter(new File(fileName + ".out"));

      int T = fin.nextInt();
      for (int t = 1; t <= T; ++t) {
        fout.format("Case #%d: ", t);

        int N = fin.nextInt();
        int S = fin.nextInt();
        int p = fin.nextInt();

        int result = 0;
        for (int i = 0; i < N; ++i) {
          int ti = fin.nextInt();
          if (p == 0) {
            ++result;
            continue;
          }
          if (ti >= (3 * p - 2)) {
            ++result;
            continue;
          }
          if (p == 1) continue;
          if (ti >= (3 * p - 4)) {
            if (S == 0) continue;
            ++result;
            --S;
          }
        }

        fout.format("%d\n", result);
      }

      fin.close();
      fout.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
