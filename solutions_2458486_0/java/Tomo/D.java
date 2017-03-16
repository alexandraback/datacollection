import java.util.Scanner;

public class D {
  private static final int MAXN = 20;
  private static final int MAXK = 208;
  private static final int MAXS = 1 << MAXN;

  public void solve(Scanner in) {
    int K = in.nextInt();
    int N = in.nextInt();

    int[][] rooms  = new int[MAXN][MAXK];
    int[]   unlock = new int[MAXN];
    int[]   keys   = new int[MAXK];

    for (int i = 0; i < K; ++i) {
      ++keys[in.nextInt()];
    }

    for (int i = 0; i < N; ++i) {
      int t = in.nextInt();
      int k = in.nextInt();

      unlock[i] = t;
      for (int j = 0; j < k; ++j) {
        int x = in.nextInt();
        ++rooms[i][x];
      }
    }

    final int all = (1<<N) - 1;

    boolean[] dp = new boolean[MAXS];
    byte[]    pi = new byte[MAXS];

    dp[all] = true;
    for (int s = all-1; s >= 0; --s) {
      for (int r = 0; r < N; ++r) {
        if (((s >> r) & 1) != 0) continue;

        int key = unlock[r];
        int cnt = keys[key];

        for (int i = 0; i < N; ++i) {
          if (((s >> i) & 1) == 0) continue;
          cnt += rooms[i][key];

          if (unlock[i] == key) --cnt;
        }

        if (cnt > 0 && dp[s | (1 << r)]) {
          pi[s] = (byte)r; dp[s] = true;
          break;
        }
      }
    }

    if (!dp[0]) {
      System.out.print(" IMPOSSIBLE");
      return;
    }
    
    int p = 0;
    for (int s = 0; s != all; ++p, s |= (1 << pi[s])) {
      System.out.print(" " + (pi[s]+1));
    }
  }

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    int T = in.nextInt();
    for (int tc = 1; tc <= T; ++tc) {
      System.out.print("Case #" + tc + ":");
      new D().solve(in);

      System.out.println();
      System.out.flush();
    }
  }
}