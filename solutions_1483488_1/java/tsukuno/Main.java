import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();

    for(int C=1; C<=T; ++C) {

      int A = cin.nextInt();
      int B = cin.nextInt();

      int n = ("" + A).length();
      int base = 1;
      for(int i=1; i<n; ++i) { base *= 10; }

      int count = 0;
      for(int i=A; i<=B; ++i) {
        count += solve(n, base, i, B);
      }

      System.out.println("Case #" + C + ": " + count);

    }

  }

  int solve(int n, int base, int v, int max) {

    Set<Integer> set = new HashSet<Integer>();

    int min = v + 1;
    for(int i=0; i<n; ++i) {
      int next = (v / 10) + (v % 10) * base;
      v = next;
      if( min <= next && next <= max ) { set.add(v); }
    }

    return set.size();

  }

}
