import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).solve();
  }

  String solve(int N, int M, int K, int arr[]) {

    if( N != 3 ) { throw new RuntimeException("3 != " + N); }

    for(int i=2; i<=M; ++i) {
      for(int j=i; j<=M; ++j) {
      LOOP:
        for(int k=j; k<=M; ++k) {
          for(int v : arr) {
            if( !valid(i, j, k, v) ) { continue LOOP; }
          }
          return "" + i + j + k;
        }
      }
    }

    return "222";

  }

  boolean valid(int i, int j, int k, int v) {
    return v == 1 || i * j * k == v || i * j == v || i * k == v || j * k == v || i == v || j == v || k == v;
  }

  void solve() {

    Scanner cin = new Scanner(System.in);

    int T = cin.nextInt();
    for(int C=1; C<=T; ++C) {

      int R = cin.nextInt();
      int N = cin.nextInt();
      int M = cin.nextInt();
      int K = cin.nextInt();

      System.out.println("Case #" + C + ":");

      for(int i=0; i<R; ++i) {
        int arr[] = new int[K];
        for(int j=0; j<K; ++j) {
          arr[j] = cin.nextInt();
        }
        System.out.println(solve(N, M, K, arr));
      }

    }

  }

}
