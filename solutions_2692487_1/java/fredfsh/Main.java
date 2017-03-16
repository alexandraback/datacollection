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
      A = fin.nextLong();
      N = fin.nextInt();
      data = new long[N];
      for (int i = 0; i < N; ++i) data[i] = fin.nextLong();

      //run
      int result = 0;
      Arrays.sort(data);
      boolean failed = false;
      long Abak = A;
      for (int i = 0; i < N; ++i) {
        if (Abak > data[i]) {
          Abak += data[i];
        } else {
          failed = true;
          break;
        }
      }
      if (failed) result = get(0, N);

      //output
      fout.printf("Case #%d: %d\n", tt, result);
    }

    fin.close();
    fout.close();
  }

  private int get(int left, int right) {
    if (left + 1 == right) return right;
    int middle = (left + right) / 2;
    if (can(middle)) return get(left, middle);
    else return get(middle, right);
  }

  private boolean can(int x) {
    long Abak = A;
    for (int i = 0; i < N; ++i) {
      if (Abak > data[i]) {
        Abak += data[i];
        continue;
      }
      if (x >= N - i) return true;
      while ((Abak <= data[i]) && (x > 0)) {
        Abak = 2 * Abak - 1;
        --x;
      }
      if (Abak <= data[i]) return false;
      Abak += data[i];
    }
    return true;
  }

  private int T;
  private int N;
  private long A;
  private long[] data;
}
