import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B {

  static final String FILENAME = "B-large";
  static final String IN = FILENAME + ".in";
  static final String OUT = FILENAME + ".out";
  Scanner sc;
  BufferedWriter out;

  private void solve() throws IOException {
    String pancake = sc.next();
    int times = 1;
    for(int i = 1; i < pancake.length(); i++) {
      if(pancake.charAt(i) != pancake.charAt(i - 1)) {
        times++;
      }
    }
    if(pancake.charAt(pancake.length() - 1) == '+') {
      times--;
    }
    out.write(Integer.toString(times));
    out.newLine();
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
    new B().run();
  }
}
