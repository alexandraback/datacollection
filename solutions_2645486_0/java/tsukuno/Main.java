import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  long solve(int FULL, int REC, int N, int arr[]) {

    long score[] = new long[FULL + 1];

    for(int i=0; i<N; ++i) {
      long next[] = new long[FULL + 1];
      for(int j=0; j<=FULL; ++j) {
        for(int k=0; k<=j; ++k) {
          int pos = Math.min(FULL, k + REC);
          next[pos] = Math.max(next[pos], score[j] + (j - k) * arr[i]);
        }
      }
      score = next;
    }

    long ret = 0;
    for(int i=0; i<=FULL; ++i) { ret = Math.max(ret, score[i]); }

    return ret;

  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      int FULL = cin.nextInt();
      int REC = cin.nextInt();
      int N = cin.nextInt();

      int arr[] = new int[N];
      for(int i=0; i<N; ++i) { arr[i] = cin.nextInt(); }

      System.out.println("Case #" + C + ": " + solve(FULL, REC, N, arr));

    }

  }

}
