import java.io.*;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author nik
 */
public class A {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("A-small-attempt0 (1).in"));
    PrintWriter out = new PrintWriter("a.out");
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int[] s = new int[n];
      int x = 0;
      for (int i = 0; i < s.length; i++) {
        s[i] = in.nextInt();
        x += s[i];
      }

      out.print("Case #"+t+":");
      for (int i = 0; i < s.length; i++) {
        double l = 0, r = 1;
        while (r-l > 1e-9) {
          double m = (r+l)/2;
          double rem = 1-m, score = s[i]+x*m;
          for (int j = 0; j < n; j++) {
            if (j != i && s[j] < score) {
              rem -= (score - s[j])/x;
            }
          }
          if (rem < 0) {
            r = m;
          }
          else {
            l = m;
          }
        }
        out.printf(Locale.US, " %.6f", r*100);
      }
      out.println();
    }
    out.close();
    in.close();
  }

}
