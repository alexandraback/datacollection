import java.util.*;

class Hiker implements Comparable<Hiker> {
  int d;
  long m;

  public long when() {
    return (360 - d) * m;
  }

  public int compareTo(Hiker h) {
    return Long.valueOf(when()).compareTo(h.when());
  }
}

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int tcc = sc.nextInt();
    for (int tc = 1; tc <= tcc; ++tc) {
      int n = sc.nextInt();
      List<Hiker> hikers = new ArrayList<Hiker>();
      for (int i = 0; i < n; ++i) {
        int d = sc.nextInt();
        int h = sc.nextInt();
        long m = sc.nextLong();
        for (int j = 0; j < h; ++j) {
          Hiker hiker = new Hiker();
          hiker.d = d;
          hiker.m = m;
          hikers.add(hiker);
        }
      }
      Collections.sort(hikers);
      long ans = Long.MAX_VALUE;
      for (int hi = 0; hi < hikers.size(); ++hi) {
        long cur = 0;
        Hiker follow = hikers.get(hi);
        for (int hj = 0; hj < hikers.size(); ++hj) {
          if (hj == hi) continue;
          Hiker other = hikers.get(hj);
          if (hi < hj) {
            if (other.when() > follow.when()) ++cur;
            else {
              cur = Long.MAX_VALUE;
              break;
            }
          } else {
            long wd = follow.when() - other.when() + 1;
            cur += wd / (360 * other.m);
          }
        }
        ans = Math.min(ans, cur);
      }
      System.out.printf("Case #%d: %d%n", tc, ans);
    }
  }
}
