import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author nik
 */
public class Osmos {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("A-small-attempt0.in"));
    PrintWriter out = new PrintWriter("osmos.out");
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      int a = in.nextInt();
      int n = in.nextInt();
      int[] s = new int[n];
      for (int i = 0; i < s.length; i++) {
        s[i] = in.nextInt();
      }
      Arrays.sort(s);
      int r;
      if (a == 1) {
        r = n;
      }
      else {
        r = Integer.MAX_VALUE;
        int a0 = a;
        for (int i = 0; i <= n; i++) {
          int x = n-i;
          int j = 0;
          a = a0;
          while (j < i) {
            if (s[j] < a) {
              a += s[j];
              j++;
            }
            else {
              a += a-1;
              x++;
            }
          }
          r = Math.min(r, x);
        }
      }
      out.println("Case #"+t+": " + r);
    }
    out.close();
    in.close();
  }

}
