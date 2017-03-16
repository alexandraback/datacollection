import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Fractiles {

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new File("data/fractiles/D-small-attempt0.in"));
    PrintStream ps = new PrintStream("data/fractiles/out");
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      List<Long> result = calc(sc.nextInt(), sc.nextInt(), sc.nextInt());
      ps.printf("Case #%d:", i);
      //System.out.printf("Case #%d:", i);
      if (result.isEmpty()) {
        ps.print(" IMPOSSIBLE");
        //System.out.print(" IMPOSSIBLE");
      }
      for (Long r : result) {
        ps.printf(" %d", r);
        //System.out.printf(" %d", r);
      }
      ps.println();
      //System.out.println();
    }
  }

  private static List<Long> calc(long k, long c, long s) {
    List<Long> result = new ArrayList<Long>();
    if (s == k) {
      result.add(1L);
      long r = (long) Math.pow(k, c - 1);
      for (long i = 1; i < k; i++) {
        result.add(result.get(result.size() - 1) + r);
      }
    }
    return result;
  }
}
