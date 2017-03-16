import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;


public class War {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("War.in"));
    PrintWriter out = new PrintWriter(new File("War.out"));
    int cases = in.nextInt();
    for (int co = 1; co <= cases; co++) {
      int n = in.nextInt();
      double[] me = new double[n];
      for (int i = 0; i < n; i++)
        me[i] = in.nextDouble();
      double[] op = new double[n];
      for (int i = 0; i < n; i++)
        op[i] = in.nextDouble();
      
      TreeSet<Double> o = new TreeSet<Double>();
      for (double d : op)
        o.add(d);
      
      Arrays.sort(me);
      int regScore = 0;
      for (double d : me) {
        if (o.higher(d) == null) {
          regScore++;
        } else {
          o.remove(o.higher(d));
        }
      }
      o = new TreeSet<Double>();
      for (double d : op)
        o.add(d);
      
      int l = 0, r = n - 1;
      int cheatScore = 0;
      while (l <= r) {
        if (me[r] >= o.last()) {
          cheatScore++;
          r--;
          o.pollLast();
        } else {
          l++;
          o.pollLast();
        }
      }
      
      System.out.printf("Case #%d: %d %d\n", co, cheatScore, regScore);
      out.printf("Case #%d: %d %d\n", co, cheatScore, regScore);
    }
    out.close();
  }
}
