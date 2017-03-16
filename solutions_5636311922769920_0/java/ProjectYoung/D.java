import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class D {

  static final String FILENAME = "D-small-attempt1";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;

  private void printAnswer(int k, int c, int s) throws IOException {
    long ans = 0;
    for (int i = 0; i < c; i++) {
      ans *= k;
      ans += s;
      if (s < k - 1) {
        s++;
      }
    }
    out.write(Long.toString(ans + 1));
  }

  private void solve() throws IOException {
    int k = sc.nextInt();
    int c = sc.nextInt();
    int s = sc.nextInt();
    int need = (k + c - 1) / c;
    if (need > s) {
      out.write("IMPOSSIBLE");
      out.newLine();
    } else {
      for (int i = 0; i < need - 1; i++) {
        printAnswer(k, c, i * c);
        out.write(" ");
      }
      printAnswer(k, c, Math.max(k - c, 0));
      out.newLine();
    }
  }

  private void run() throws IOException {
    sc = new Scanner(new File(IN));
    out = new BufferedWriter(new FileWriter(OUT));
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      out.write("Case #" + i + ": ");
      solve();
    }
    sc.close();
    out.close();
  }

  public static void main(String args[]) throws Exception {
    new D().run();
  }
}
