import java.util.*;
import java.io.*;
import java.lang.*;

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

    //pre
    int[] count = new int[10000001];
    for (long i = 1; i <= 10000000; ++i) {
      long sqr = i * i;
      count[(int) i] = count[(int) i - 1];
      if (palin(i) && palin(sqr)) ++count[(int) i];
    }

    T = fin.nextInt();
    fin.nextLine();
    for (int tt = 1; tt <= T; ++tt) {
      int result = 0;

      //input
      long A = fin.nextInt();
      long B = fin.nextInt();

      //run
      result = count[(int) Math.sqrt((double) B)];
      if (A != 0) {
        result -= count[(int) Math.sqrt((double) (A - 1))];
      }

      //output
      fout.printf("Case #%d: %d\n", tt, result);
    }

    fin.close();
    fout.close();
  }

  private boolean palin(long x) {
    String str = Long.toString(x);
    int l = str.length();
    for (int i = 0, j = l - 1; i < j; ++i, --j) {
      if (str.charAt(i) != str.charAt(j)) return false;
    }
    return true;
  }

  private int T;
  private int N, M;
}
