import java.math.BigInteger;
import java.util.*;

public class C {
  static ArrayList<Integer> prods;
  static ArrayList<Integer> ans;
  static int R, N, M, K;

  private static boolean rec(int idx) {
    if (idx == N) {
      ArrayList<Integer> ps = new ArrayList<Integer>();
      ps.add(1);
      for (int i = 0; i < (1 << N); i++) {
        int p = 1;
        for (int k = 0; k < N; k++) {
          if ((i & (1 << k)) != 0) {
            p *= ans.get(k);
          }
        }
        ps.add(p);
      }

      if (ps.containsAll(prods)) {
        for (int i : ans) System.out.printf("%d", i);
        System.out.printf("\n");
        return true;
      } else {
        return false;
      }
    } else {
      for (int i = 2; i <= M; i++) {
        ans.add(i);
        if (rec(idx+1)) {
          ans.remove(ans.size()-1);
          return true;
        }
        ans.remove(ans.size()-1);
      }
      return false;
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    sc.nextInt();
    System.out.printf("Case #1:\n");
    R = sc.nextInt();
    N = sc.nextInt();
    M = sc.nextInt();
    K = sc.nextInt();

    for (int r = 0; r < R; r++) {
      prods = new ArrayList<Integer>();
      for (int i = 0; i < N; i++) {
        prods.add(sc.nextInt());
      }

      ans = new ArrayList<Integer>();
      if (!rec(0)) {
        for (int i = 0; i < N; i++) System.out.printf("2");
        System.out.printf("\n");
      }
    }
  }
}


