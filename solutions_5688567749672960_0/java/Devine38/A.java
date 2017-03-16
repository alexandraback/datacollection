import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class A {
  static final boolean DEBUG = false;
  static Scanner in;
  static List<PrintStream> out;

  public static void main(String[] args) throws FileNotFoundException {
    out = new ArrayList<>();
    out.add(System.out);
    if (DEBUG) {
      in = new Scanner(new File("t"));
    } else {
      in = new Scanner(new File(A.class.getName() + ".in"));
      out.add(new PrintStream(A.class.getName() + ".out"));
    }
    int T = i();
    for (int i = 0; i < T; i++) {
      pf("Case #%d: %s\n", i + 1, solve());
    }
    System.out.println("Done");
    in.close();
    for (PrintStream ps : out) {
      ps.close();
    }
  }

  static String solve() {
    int N = i();
    int[] nums = new int[N + 1];
    Arrays.fill(nums, Integer.MAX_VALUE - 1);
    nums[0] = 0;
    for (int i = 1; i <= N; i++) {
      nums[i] = Math.min(nums[i - 1] + 1, nums[i]);
      if (reversed(i) <= N) {
        nums[reversed(i)] = Math.min(nums[reversed(i)], nums[i] + 1);
      }
    }
//    System.out.println(Arrays.toString(nums));

    return nums[N] + "";
  }

  static int reversed(int n) {
    String s = Integer.toString(n);
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < s.length(); i++) {
      sb.append(s.charAt(s.length() - 1 - i));
    }
    while (sb.charAt(0) == '0') {
      sb.replace(0, 2, "" + sb.charAt(1));
    }
    return Integer.parseInt(sb.toString());
  }

  static void p(String x) {
    for (PrintStream ps : out) {
      ps.print(x);
    }
  }

  static void pl(String x) {
    for (PrintStream ps : out) {
      ps.println(x);
    }
  }

  static void pf(String format, Object... args) {
    for (PrintStream ps : out) {
      ps.printf(format, args);
    }
  }

  static String f(String format, Object... args) {
    return String.format(format, args);
  }

  static int i() {
    return in.nextInt();
  }

  static long l() {
    return in.nextLong();
  }

  static String s(String pattern) {
    return in.next(pattern);
  }

  static String li() {
    return in.nextLine();
  }
}