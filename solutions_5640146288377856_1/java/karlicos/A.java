import java.io.PrintWriter;
import java.util.*;

public class A {
  public static void main(String[] args) {
    new A().run();
  }

  private void run() {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int tests = in.nextInt();
    for (int test = 0; test < tests; test++) {
      int r = in.nextInt(), c = in.nextInt(), w = in.nextInt();
      int ans = solve(r, c, w);
      out.println(String.format("Case #%d: %s", test + 1, ans));
      out.flush();
    }

    in.close();
    out.close();
  }

  private int solve(int r, int c, int w) {
    int score = c / w * r - 1;
    int rem = c % w;
    if (rem == 0) {
      return score + w;
    } else {
      return score + w + 1;
    }
  }
}
