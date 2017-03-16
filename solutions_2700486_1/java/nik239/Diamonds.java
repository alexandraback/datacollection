import java.io.*;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author nik
 */
public class Diamonds {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("B-large.in"));
    PrintWriter out = new PrintWriter("diamonds.out");
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int x = Math.abs(in.nextInt());
      int y = in.nextInt();
      int k = (x+y)/2;
      int s = 0;
      for (int i = 0; i < k; i++) {
        s += 4*i+1;
      }
      double p;
      if (n <= s) {
        p = 0;
      }
      else if (n >= s+4*k+1) {
        p = 1;
      }
      else {
        int a = n-s;
        if (a > 2*k+y) {
          p = 1;
        }
        else if (a <= y || y == 2*k) {
          p = 0;
        }
        else {
          p = prob(a, y+1);
        }
      }
      out.printf(Locale.US, "Case #%d: %.6f", t, p);
      out.println();
    }
    out.close();
    in.close();
  }

  private static double prob(int a, int b) {
    double[] p0 = new double[a+1];
    double[] p1 = new double[a+1];
    p0[0] = 1;
    for (int i = 0; i < a; i++) {
      p1[0] = 1;
      for (int j = 1; j <= a; j++) {
        p1[j] = 0.5*p0[j]+0.5*p0[j-1];
      }
      double[] t = p1;
      p1 = p0;
      p0 = t;
    }
    return p0[b];
  }

}
