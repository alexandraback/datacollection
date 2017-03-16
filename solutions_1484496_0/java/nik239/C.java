import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author nik
 */
public class C {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("C-small-attempt0.in"));
    PrintWriter out = new PrintWriter("c.out");
    int T = in.nextInt();
    int[] x = new int[100000*20];
    for (int t = 1; t <= T; t++) {
      int n = in.nextInt();
      int[] s = new int[n];
      for (int i = 0; i < n; i++) {
        s[i] = in.nextInt();
      }
      Arrays.fill(x, -1);
      x[0] = 0;
      int m1 = -1, m2 = -1;
      outer:
      for (int i = 0; i < x.length; i++) {
        int m = x[i];
        if (m == -1) continue;
        for (int j = 0; j < n; j++) {
          if (((1 << j) & m) != 0 || i + s[j] >= x.length) continue;
          int nm = m | (1 << j);
          int mm = x[i+s[j]];
          if (mm == nm) continue;
          if (mm != -1) {
            m1 = nm; m2 = mm;
            break outer;
          }
          x[i+s[j]] = nm;
        }
      }

      out.println("Case #"+t+":");
      if (m1 == -1) {
        out.println("Impossible");
      }
      else {
        writeSet(out, s, m1);
        writeSet(out, s, m2);
      }
    }
    out.close();
    in.close();
  }

  private static void writeSet(PrintWriter out, int[] s, int mask) {
    int k = 0;
    StringBuilder buf = new StringBuilder();
    while (mask > 0) {
      if ((mask & 1) != 0) {
        if (buf.length() > 0) buf.append(' ');
        buf.append(s[k]);
      }
      k++;
      mask >>= 1;
    }
    out.println(buf);
  }

}
