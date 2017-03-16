import java.io.PrintWriter;
import java.util.*;

public class C {
  public static void main(String[] args) {
    new C().run();
  }

  private void run() {
    Scanner in = new Scanner(System.in);
    PrintWriter out = new PrintWriter(System.out);

    int tests = in.nextInt();
    for (int test = 0; test < tests; test++) {
      int c = in.nextInt(), d = in.nextInt();
      long v = in.nextLong();
      long[] denominations = new long[d];
      for (int i = 0; i < d; i++) {
        denominations[i] = in.nextLong();
      }
      long ans = solveSmall(c, denominations, (int) v);
      out.println(String.format("Case #%d: %s", test + 1, ans));
      out.flush();
    }

    in.close();
    out.close();
  }

  private boolean check(Set<Integer> denominations, int value) {
    List<Integer> denoms = new ArrayList<>(denominations);
    boolean[] values = new boolean[value + 1];
    for (int mask = 0; mask < (1 << denoms.size()); mask++) {
      int res = 0;
      for (int i = 0; i < denoms.size(); i++) {
        if (((mask >> i) & 1) == 1) {
          res += denoms.get(i);
        }
      }
      if (res <= value) {
        values[res] = true;
      }
    }
    for (boolean v : values) {
      if (!v) {
        return false;
      }
    }
    return true;
  }

  private static <T> int setDifference(Set<T> a, Set<T> b) {
    HashSet<T> tmp = new HashSet<T>(a);
    tmp.removeAll(b);
    return tmp.size();
  }

  private long solveSmall(long limit, long[] denominations, int value) {
    Set<Integer> initial = new HashSet<>();
    for (long d : denominations) {
      initial.add((int) d);
    }
    int min = 5;
    for (int i1 = 0; i1 <= value; i1++) {
      for (int i2 = 0; i2 <= value; i2++) {
        for (int i3 = 0; i3 <= value; i3++) {
          for (int i4 = 0; i4 <= value; i4++) {
            Set<Integer> ss = new HashSet<>(initial);
            ss.add(i1);
            ss.add(i2);
            ss.add(i3);
            ss.add(i4);
            ss.remove(0);
            if (check(ss, value)) {
              min = Math.min(min, setDifference(ss, initial));
            }
          }
        }
      }
    }
    return min;
  }
}
