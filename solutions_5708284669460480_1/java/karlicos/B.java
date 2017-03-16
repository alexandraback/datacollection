import java.io.PrintWriter;
import java.util.*;

public class B {
  public static void main(String[] args) {
    new B().run();
  }

  private void run() {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int tests = in.nextInt();
    for (int test = 0; test < tests; test++) {
      int k = in.nextInt(), l = in.nextInt(), s = in.nextInt();
      in.nextLine();
      String keyboard = in.nextLine();
      String target = in.nextLine();
//      System.out.println("CASE " + (test + 1));
      double ans = solve(keyboard, target, s);
      out.println(String.format("Case #%d: %.7f", test + 1, ans));
      out.flush();
    }

    in.close();
    out.close();
  }

  private double solve(String keyboardS, String targetS, int repeats) {
    for (char c : targetS.toCharArray()) {
      if (keyboardS.indexOf(c) == -1) {
        return 0.0;
      }
    }
    if (targetS.length() > repeats) {
      return 0.0;
    }

    int max = maxBananas(targetS, repeats);
//    System.out.println("MAX = " + max);

    double expected = expectedBananas(keyboardS, targetS, repeats);
//    System.out.println("EXPECTED = " + expected);

    return max - expected;
  }

  private double expectedBananas(String keyboardS, String targetS, int repeats) {
    char[] keyboard = keyboardS.toCharArray();
    char[] target = targetS.toCharArray();
    double[] prob = new double[256];
    for (char c = 0; c < 256; c++) {
      int count = 0;
      for (int i = 0; i < keyboard.length; i++) {
        if (keyboard[i] == c) {
          count++;
        }
      }
      prob[c] = ((double)count) / keyboard.length;
    }

    double prob1 = 1.0;
    for (char c : targetS.toCharArray()) {
      prob1 *= prob[c];
    }

    return (repeats - targetS.length() + 1) * prob1;
  }

  private int maxBananas(String targetS, int repeats) {
    int overlap = 0;
    for (int ov = targetS.length() - 1; ov > 0; ov--) {
      String prefix = targetS.substring(0, ov);
      String suffix = targetS.substring(targetS.length() - ov, targetS.length());
      if (prefix.equals(suffix)) {
        overlap = ov;
        break;
      }
    }
    int max = 1;
    max += (repeats - targetS.length()) / (targetS.length() - overlap);
    return max;
  }
}
