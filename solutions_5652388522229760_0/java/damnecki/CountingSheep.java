import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class CountingSheep {

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new File("data/countingsheep/A-small-attempt0.in"));
    PrintStream ps = new PrintStream("data/countingsheep/out");
    int t = sc.nextInt();
    for (int i = 1; i <= t; i++) {
      long l = calc(sc.nextLong());
      String r = l == 0 ? "INSOMNIA" : String.valueOf(l);
      ps.printf("Case #%d: %s\n", i, r);
      //System.out.printf("Case #%d: %s\n", i, r);
    }
  }

  private static long calc(long n) {
    if (n == 0) {
      return 0;
    }
    Set<String> s = new HashSet<String>();
    long i = 0;
    long nCur = 0;
    while (s.size() < 10) {
      nCur = (++i) * n;
      s.addAll(Arrays.asList(String.valueOf(nCur).split("")));
    }
    return nCur;
  }
}
