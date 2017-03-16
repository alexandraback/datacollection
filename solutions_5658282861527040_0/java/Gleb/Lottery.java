import java.io.File;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Scanner;

public class Lottery implements Runnable {
  private static final String NAME = "lot";

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File(NAME + ".in"));
      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      for (int test = 1; test <= tests; test++) {
        int a = in.nextInt();
        int b = in.nextInt();
        int k = in.nextInt();
        int res = 0;
        for (int i = 0; i < a; i++) {
          for (int j = 0; j < b; j++) {
            if ((i & j) < k) res++;
          }
        }
        out.println("Case #" + test + ": " + res);
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Lottery()).start();
  }
}
