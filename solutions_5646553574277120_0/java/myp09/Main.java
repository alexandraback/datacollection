import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception {
    Scanner s = new Scanner(System.in);
    int T = s.nextInt();
    for (int t = 1; t <= T; t++) {
      int C = s.nextInt(), D = s.nextInt(), V = s.nextInt();
      List<Integer> c = new ArrayList<Integer>();
      List<Integer> a = new ArrayList<Integer>(), b = new ArrayList<Integer>();
      for (int i = 0; i < D; i++) {
        int k = s.nextInt();
        a.add(k);
        b.add(k);
        c.add(k);
      }
      Collections.sort(a);
      int ans = 0;
      // System.out.println(V);
      for (int i = 1; i <= V; i++) {
        int j = i, k = a.size() - 1;
        while (j != 0 && k != -1) {
          if (j >= a.get(k)) {
            j -= a.get(k);
          }
          k--;
        }
        if (j != 0) {
          // System.out.println(a);
          // System.out.println(i);
          a.add(get(i));
          ans++;
          Collections.sort(a);
        }
      }

      int ans1 = 0;
      // System.out.println(V);
      for (int i = 1; i <= V; i++) {
        int j = i, k = b.size() - 1;
        while (j != 0 && k != -1) {
          if (j >= b.get(k)) {
            j -= b.get(k);
          }
          k--;
        }
        if (j != 0) {
          // System.out.println(a);
          // System.out.println(i);
          b.add(i);
          ans1++;
          Collections.sort(b);
        }
      }
      System.out.println(String.format("Case #%d: %d", t, Math.min(ans1, ans)));  
    }
  }

  public static int get(int k) {
    int k0 = k;
    int prev = k;
    while (k != 0) {
      prev = k;
      k = k & (k - 1);
    }
    // System.out.println(k0 + " " + prev);
    return prev;
  }
}