import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(System.in);
    Map<Long, Integer> map = new HashMap<Long, Integer>();
    List<Long> q = new ArrayList<Long>();
    int k = 0;
    q.add(1L);
    map.put(1L, 1);
    while (k < q.size()) {
      long cur = q.get(k++);
      int cost = map.get(cur);
      long add = cur + 1, rev = reverse(cur);
      if (add <= MAX && !map.containsKey(add)) {
        map.put(add, cost + 1);
        q.add(add);
      }
      if (rev <= MAX && !map.containsKey(rev)) {
        map.put(rev, cost + 1);
        q.add(rev);
      }
    }
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {
      long n = s.nextLong();
      
      System.out.println(String.format("Case #%d: %d", t, map.get(n)));
    }
  }

  public static long reverse(long k) {
    long ret = 0;
    while (k != 0) {
      ret = ret * 10 + k % 10;
      k /= 10;
    }
    return ret;
  }

  public static final long MAX = 1000000;
}