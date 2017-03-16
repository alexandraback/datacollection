import java.util.*;

class C {

  static int N, M;
  static String[] zip;
  static int[][] ok;
  static String sol = "";
  static HashSet<String> vis;

  static void solve(int x, int now, int mask, int returnLeft, String code) {
    if (x == N && returnLeft == 0) {
      if ("".equals(sol) || code.compareTo(sol) < 0) {
        sol = code;
      }
      return;
    }
    for (int i = 0; i < N; i++) {
      if (x < N && ok[now][i] == 1 && ((1 << i) & mask) == 0) {
        ok[now][i] = 0;
        ok[i][now] = -1;
        solve(x + 1, i, mask | (1 << i), returnLeft+1, code + zip[i]);
        ok[now][i] = 1;
        ok[i][now] = 1;
      } else if (ok[now][i] == -1) {
        ok[now][i] = 0;
        solve(x, i, mask, returnLeft-1, code);
        ok[now][i] = -1;
      }
    }
  }

  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int T = input.nextInt();
    for (int t = 1; t <= T; t++) {
      System.out.print("Case #" + t + ": ");
      N = input.nextInt();
      M = input.nextInt();
      zip = new String[N];
      sol = "";
      for (int i = 0; i < N; i++) {
        zip[i] = input.next();
      }
      ok = new int[N][N];
      vis = new HashSet<String>();
      for (int i = 0; i < M; i++) {
        int a = input.nextInt();
        int b = input.nextInt();
        a--;
        b--;
        ok[a][b] = ok[b][a] = 1;
      }

      for (int i = 0; i < N; i++) {
        solve(1, i, 1<<i, 0, zip[i]);
      }
      System.out.println(sol);
    }
  }
}
