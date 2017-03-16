import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class FairSquareDumb implements Runnable {
  boolean isFair(long i) {
    String s = Long.toString(i);
    char[] c = new char[s.length()];
    for (int k = 0; k < s.length(); k++) {
      c[s.length() - k - 1] = s.charAt(k);
    }
    return s.equals(new String(c));
  }

  @Override
  public void run() {
    try {
      int MAX = 100000000;

      ArrayList<Long> a = new ArrayList<Long>();
      for (int i = 1; i <= MAX; i++) {
        long l = i;
        if (isFair(l) && isFair(l * l)) {
          a.add(l * l);
        }
      }

      Scanner in = new Scanner(new File("fair.in"));
      PrintWriter out = new PrintWriter("fair.out");

      int tests = in.nextInt();

      for (int test = 1; test <= tests; test++) {
        long A = in.nextLong();
        long B = in.nextLong();
        int res = 0;
        for (Long l: a) {
          if (A <= l && l <= B) res++;
        }
        out.println("Case #" + test + ": " + res);
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new FairSquareDumb()).start();
  }
}
