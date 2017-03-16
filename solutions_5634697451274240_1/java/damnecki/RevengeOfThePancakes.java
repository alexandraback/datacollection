import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class RevengeOfThePancakes {

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new File("data/revengeofthepancakes/B-large.in"));
    PrintStream ps = new PrintStream("data/revengeofthepancakes/out");
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      StringBuilder s = new StringBuilder(sc.next());
      int m = calc(s);
      ps.printf("Case #%d: %d\n", i, m);
      //System.out.printf("Case #%d: %d\n", i, m);
    }
  }

  private static int calc(StringBuilder s) {
    int m = 0;
    //System.out.println(s);
    while (s.lastIndexOf("-") != -1) {
      int r1 = s.lastIndexOf("-");
      int r2 = -1;
      while (s.charAt(++r2) == '+');
      if (r2 == 1) {
        s.setCharAt(0, '-');
        m++;
        //System.out.println(s);
      } else if (r2 > 1) {
        for (int j = 0; j < r2; j++) {
          s.setCharAt(j, reverse(s.charAt(j)));
        }
        m++;
        //System.out.println(s);
      }
      for (int j = 0; j <= r1; j++) {
        s.setCharAt(j, reverse(s.charAt(j)));
      }
      m++;
      //System.out.println(s);
    }
    return m;
  }

  private static char reverse(char c) {
    return c == '+' ? '-' : '+';
  }
}
