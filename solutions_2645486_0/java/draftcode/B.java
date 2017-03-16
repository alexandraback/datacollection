import java.math.BigInteger;
import java.util.*;

public class B {
  static ArrayList<Integer> acts;
  static int E, R, N;

  private static int rec(int energy, int idx) {
    if (idx == N) return 0;
    int ans = 0;
    for (int e = 0; e <= energy; e++) {
      int gain = e * acts.get(idx) + rec(Math.min(energy - e + R, E), idx+1);
      ans = Math.max(ans, gain);
    }
    return ans;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt();
    for (int cs = 1; cs <= T; cs++) {
      E = sc.nextInt();
      R = sc.nextInt();
      N = sc.nextInt();

      acts = new ArrayList<Integer>();
      for (int i = 0; i < N; i++) {
        acts.add(sc.nextInt());
      }

      int ans = rec(E, 0);
      System.out.printf("Case #%d: %d\n", cs, ans);
    }
  }
}

