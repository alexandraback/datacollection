import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {

  static final String FILENAME = "A-small-attempt0";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;

  private void solve() throws IOException {
    long n = sc.nextLong();
    boolean[] test = new boolean[10];
    int total = 0;
    if (n == 0) {
      out.write("INSOMNIA");
      out.newLine();
    } else {
      for (long now = n;; now += n) {
        long tmp = now;
        while (tmp != 0) {
          if (!test[(int) (tmp % 10)]) {
            test[(int) (tmp % 10)] = true;
            total++;
          }
          tmp /= 10;
        }
        if (total == 10) {
          out.write(Long.toString(now));
          out.newLine();
          break;
        }
      }
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
    new A().run();
  }
}
