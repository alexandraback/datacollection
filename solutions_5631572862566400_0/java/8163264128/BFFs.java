import java.util.*;

public class BFFs {
  public static void main(String []args) {
    Scanner in = new Scanner(System.in);
    final int T = in.nextInt();
    for (int i = 1; i <= T; i++) {
      final int N = in.nextInt();
      int []F = new int[N];
      for (int j = 0; j < N; j++)
        F[j] = in.nextInt() - 1;
      
      int [][]r = new int[N][N];
      
      int []c = new int[N];
      int g = 1;
      int max = 0;
      for (int j = 0; j < N; j++) {
        int l = 1;
        int prev = j;
        int cur = F[j];
        c[prev] = g;
        while (c[cur] != g) {
          c[cur] = g;
          l++;
          prev = cur;
          cur = F[cur];
        }
        if (F[cur] == prev) {
          if (l > r[cur][prev]) r[cur][prev] = l;
          if (r[prev][cur] > 0) l += r[prev][cur] - 2;
          if (l > max) max = l;
        }
        if (cur == j) if (l > max) max = l;
        g++;
      }

      System.out.println("Case #" + i + ": " + max);
    }
  }
}