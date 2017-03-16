import java.util.*;

class Interval {
  public long start, end, height;

  public boolean intersects(Interval other) {
    if (other.start < this.start) return other.intersects(this);
    return other.start < this.end;
  }

  public String toString() {
    return String.format("I[%d,%d]@%d", start, end, height);
  }
}

class Attack extends Interval {
  public long day;
}

class C {
  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    for (long tc = 1, tcc = sc.nextInt(); tc <= tcc; ++tc) {
      Map<Long,List<Attack>> attacks = new HashMap<Long,List<Attack>>();
      int n = sc.nextInt();
      for (int i = 0; i < n; ++i) {
        long d = sc.nextInt();
        int a = sc.nextInt();
        long w = sc.nextInt();
        long e = sc.nextInt();
        long s = sc.nextInt();
        long dd = sc.nextInt();
        long dp = sc.nextInt();
        long ds = sc.nextInt();
        while (a-->0 && s > 0) {
          Attack attack = new Attack();
          attack.day = d;
          attack.height = s;
          attack.start = w;
          attack.end = e;
          w += dp;
          e += dp;
          s += ds;
          d += dd;
          List<Attack> list = attacks.get(attack.day);
          if (list == null) attacks.put(attack.day, list = new ArrayList<Attack>());
          list.add(attack);
        }
      }
      List<Long> attackDays = new ArrayList<Long>();
      attackDays.addAll(attacks.keySet());
      Collections.sort(attackDays);

      List<Interval> intervals = new ArrayList<Interval>();
      {
        Interval iv = new Interval();
        iv.start = Long.MIN_VALUE;
        iv.end = Long.MAX_VALUE;
        iv.height = 0;
        intervals.add(iv);
      }

      long ans = 0;
      for (long day: attackDays) {
//        System.err.println("Day " + day);
        for (Attack attack: attacks.get(day)) {
//          System.err.println("Attack " + attack);
          boolean successful = false;
          for (Interval iv: intervals) {
            if (iv.intersects(attack)) {
//              System.err.println("Hits " + iv);
              if (attack.height > iv.height) {
                successful = true;
              }
            }
          }
          if (successful) {
            ++ans;
          }
        }
        for (Attack attack: attacks.get(day)) {
          List<Interval> newIntervals = new ArrayList<Interval>();
          for (Interval iv: intervals) {
            if (!iv.intersects(attack) || iv.height >= attack.height) {
              newIntervals.add(iv);
              continue;
            }
            if (iv.start < attack.start) {
              Interval tmp = new Interval();
              tmp.height = iv.height;
              tmp.start = iv.start;
              tmp.end = attack.start;
              newIntervals.add(tmp);
            }
            {
              Interval tmp = new Interval();
              tmp.height = attack.height;
              tmp.start = Math.max(iv.start, attack.start);
              tmp.end = Math.min(iv.end, attack.end);
              newIntervals.add(tmp);
            }
            if (iv.end > attack.end) {
              Interval tmp = new Interval();
              tmp.height = iv.height;
              tmp.start = attack.end;
              tmp.end = iv.end;
              newIntervals.add(tmp);
            }
          }
          intervals = newIntervals;
        }
//        System.err.println(intervals);
      }

      System.out.printf("Case #%d: %d%n", tc, ans);
    }
  }
}
