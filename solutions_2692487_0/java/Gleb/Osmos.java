import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos implements Runnable {
  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File("a.in"));
      PrintWriter out = new PrintWriter("a.out");
      //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
      //StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

      int testNum = in.nextInt();

      for (int test = 1; test <= testNum; test++) {
        long a = in.nextInt();
        int n = in.nextInt();
        long[] b = new long[n];
        for (int i = 0; i < n; i++) b[i] = in.nextLong();
        Arrays.sort(b);

        if (a == 1) {
          out.println("Case #" + test + ": " + n);
          continue;
        }

        long res = n;
        long c = 0;
        for (int i = 0; i < n; i++) {
          while (a <= b[i]) {
            a = 2 * a - 1;
            c++;
          }
          a = a + b[i];
          res = Math.min(res, c + n - i - 1);
        }
        res = Math.min(res, c);
        out.println("Case #" + test + ": " + res);
      }
      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Osmos()).start();
  }
}
