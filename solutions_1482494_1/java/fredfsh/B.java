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
        int[] a = new int[N];
        int[] b = new int[N];
        int[] stage = new int[N];
        for (int i = 0; i < N; ++i) {
          a[i] = fin.nextInt();
          b[i] = fin.nextInt();
        }

        int stars = 0;
        int done = 0;
        int result = 0;
        do {
          int i;
          for (i = 0; i < N; ++i) {
            if ((stage[i] <= 1) && (stars >= b[i])) {
              stars += (2 - stage[i]);
              ++done;
              ++result;
              stage[i] = 2;
              break;
            }
          }
          if (i < N) continue;

          int maxB = -1;
          int toDo = -1;
          for (i = 0; i < N; ++i) {
            if ((stage[i] == 0) && (stars >= a[i])) {
              if (b[i] > maxB) {
                maxB = b[i];
                toDo = i;
              }
            }
          }
          if (toDo == -1) break;
          stars += 1;
          ++result;
          stage[toDo] = 1;
        } while (true);

        if (done == N) {
          fout.format("%d\n", result);
        } else {
          fout.format("Too Bad\n");
        }
      }

      fin.close();
      fout.close();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}
