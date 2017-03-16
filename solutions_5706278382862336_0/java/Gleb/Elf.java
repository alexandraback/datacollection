import java.io.*;
import java.util.*;

public class Elf implements Runnable {
  private static final String NAME = "elf";

  int nextInt(StreamTokenizer in) throws Exception {
    in.nextToken();
    return (int) in.nval;
  }

  long nextLong(StreamTokenizer in) throws Exception {
    in.nextToken();
    return (long) in.nval;
  }

  long[] pow(long a) {
    int pow = 0;
    while (a % 2 == 0) {
      pow++;
      a = a / 2;
    }
    return new long[]{pow, a};
  }

  @Override
  public void run() {
    try {
      Scanner in = new Scanner(new File(NAME + ".in"));
      //BufferedReader in = new BufferedReader(new FileReader(new File(NAME + "in")));
      //StreamTokenizer in = new StreamTokenizer(new BufferedReader(new FileReader(new File(NAME + "in"))));

      PrintWriter out = new PrintWriter(NAME + ".out");

      int tests = in.nextInt();

      long[] p = new long[41];
      p[0] = 1;
      for (int i = 1; i < p.length; i++) p[i] = p[i - 1] * 2;

      for (int test = 1; test <= tests; test++) {
        String[] s = in.next().split("/");
        long a = Long.parseLong(s[0]);
        long b = Long.parseLong(s[1]);
        long[] pow = pow(b);
        if (a % pow[1] != 0) {
          out.println("Case #" + test + ": impossible");
          continue;
        }
        a = a / pow[1];
        int pp = (int) pow[0];
        while (pp >= 0 && a < p[pp]) {
          pp--;
        }
        out.println("Case #" + test + ": " + (pow[0] - pp));
      }

      out.close();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  public static void main(String[] args) {
    new Thread(new Elf()).start();
  }
}
