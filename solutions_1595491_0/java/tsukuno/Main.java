import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  void solve() {

    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();

    for(int C=1; C<=T; ++C) {

      int N = cin.nextInt();
      int S = cin.nextInt();
      int P = cin.nextInt();

      int arr[] = new int[N];
      for(int i=0; i<N; ++i) { arr[i] = cin.nextInt(); }

      int dp[][] = new int[N+1][S+1];

      for(int i=0; i<=N; ++i) {
        for(int j=0; j<=S; ++j) {
          dp[i][j] = -1;
        }
      }

      dp[0][0] = 0;

      for(int i=0; i<N; ++i) {
        int V = arr[i];
        for(int j=0; j<=S; ++j) {
          if( dp[i][j] == -1 ) { continue; }
          for( int d = 0; d <= (j < S ? 2 : 1); ++d ) {
            for(int k=0; k<=10; ++k) {
              if( k + d > 10 ) { continue; }
              int rest = V - k - k - d;
              if( k <= rest && rest <= (k + d) ) {
                int gain = (k + d >= P) ? 1 : 0;
                int s = d == 2 ? 1 : 0;
                dp[i + 1][j + s] = Math.max(dp[i + 1][j + s], dp[i][j] + gain);
              }
            }
          }
        }
      }

      System.out.println("Case #" + C + ": " + dp[N][S]);

    }

  }

}
