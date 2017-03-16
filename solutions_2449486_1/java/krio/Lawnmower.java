import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Lawnmower {
  public static void main(String[] args){
    FastScanner sc = new FastScanner();
    int T = sc.nextInt();

    for(int i = 1; i <= T; i++) {
      int N = sc.nextInt();
      int M = sc.nextInt();
      int[][] lawn = new int[N][M];
      for(int n = 0; n < N; n++) {
        for(int m = 0; m < M; m++) {
          lawn[n][m] = sc.nextInt();
        }
      }
      solve(lawn, N, M, i);
    }
  }

  private static void solve(int[][] lawn, int N, int M, int testNum) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(!isValid(lawn, N, M, i, j)) {
          printCase("NO", testNum);
          return;
        }
      }
    }
    printCase("YES", testNum);
  }

  private static boolean isValid(int[][] lawn, int N, int M, int i, int j) {
    boolean iValid = true, jValid = true;
    int a = lawn[i][j];
    for(int k = 0; k < N; k++) {
      if(lawn[k][j] > a) {
        iValid = false;
        break;
      }
    }

    for(int k = 0; k < M; k++) {
      if(lawn[i][k] > a) {
        jValid = false;
        break;
      }
    }

    return iValid || jValid;
  }

  private static void printCase(String result, int testNum) {
    System.out.println("Case #" + testNum + ": " + result);
  }

  private static class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    public FastScanner(String s) {
      try {
        br = new BufferedReader(new FileReader(s));
      } catch (FileNotFoundException e) {
        e.printStackTrace();
      }
    }

    public FastScanner() {
      br = new BufferedReader(new InputStreamReader(System.in));
    }

    String nextToken() {
      while (st == null || !st.hasMoreElements()) try {
        st = new StringTokenizer(br.readLine());
      } catch (IOException e) {
        e.printStackTrace();
      }
      return st.nextToken();
    }

    int nextInt() {
      return Integer.parseInt(nextToken());
    }

    long nextLong() {
      return Long.parseLong(nextToken());
    }

    double nextDouble() {
      return Double.parseDouble(nextToken());
    }
  }
}
