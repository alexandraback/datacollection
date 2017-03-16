import java.io.PrintStream;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

public class B extends Worker {

  class Level {
    int s1;
    int s2;
    @Override
    public String toString() {
      return s1 + ", " + s2;
    }
  }

  int n;
  Set<Level> levels1;
  Set<Level> levels2;
  int total;

  @Override
  void read(Input in) throws Exception {
    n = in.readint();
    Comparator<Level> byS1 = new Comparator<Level>() {
      @Override
      public int compare(Level o1, Level o2) {
        //return o1 == o2 ? 0 : o1.s1 > o2.s1 ? 1 : -1;
        if (o1 == o2) return 0;
        if (o1.s1 > o2.s1) return 1;
        if (o1.s1 < o2.s1) return -1;
        if (o1.s2 > o2.s2) return 1;
        return -1;
      }
    };
    Comparator<Level> byS2 = new Comparator<Level>() {
      @Override
      public int compare(Level o1, Level o2) {
        if (o1 == o2) return 0;
        if (o1.s2 > o2.s2) return 1;
        if (o1.s2 < o2.s2) return -1;
        if (o1.s1 > o2.s1) return 1;
        return -1;
      }
    };
    levels1 = new TreeSet<B.Level>(byS1);
    levels2 = new TreeSet<B.Level>(byS2);
    for (int i = 0; i < n; i++) {
      Level l = new Level();
      int[] v = in.readints();
      l.s1 = v[0];
      l.s2 = v[1];
      levels1.add(l);
      levels2.add(l);
    }
//    System.out.println();
//    for (Level l : levels2) {
//      System.out.println(l);
//    }

  }

  @Override
  void solve() {

    int p = 0;

    boolean metagood = true;
    while (metagood) {

      metagood = false;
      boolean good = true;
      while (good) {
        good = false;
        for (Iterator<Level> it = levels2.iterator(); it.hasNext(); ) {
          Level l = it.next();
          if (l.s2 > p) {
            break;
          }
          p += levels1.contains(l) ? 2 : 1;
          it.remove();
          levels1.remove(l);
          good = true;
          metagood = true;
          total++;
        }
      }

      if (levels2.isEmpty()) {
        break;
      }

      Level best = null;
      for (Iterator<Level> it = levels1.iterator(); it.hasNext(); ) {
        Level l = it.next();
        if (l.s1 > p) {
          break;
        }
        if (best == null) {
          best = l;
        } else {
          if (l.s2 > best.s2) {
            best = l;
          }
        }
      }
      if (best != null) {
        p += 1;
        levels1.remove(best);
        metagood = true;
        total++;
      }
    }

  }

  @Override
  void write(PrintStream out) {
    if (levels2.isEmpty()) {
      System.out.printf("Case #%d: %d\n", id, total);
    } else {
      System.out.printf("Case #%d: Too Bad\n", id);
    }
  }

  public static void main(String[] args) throws Exception {
    Master master = new Master(B.class);
    master.main(args[0]);
  }

}
