import java.io.*;
import java.util.*;

public class b {
  public static void main (String[] args) {
    MyScanner s = new MyScanner();
    int t, T = s.nextInt();
    int[][] Pre = new int[1001][1001];

    for (int i = 1; i <= 1000; i++) {
      for (int j = 1; j <= 1000; j++) {
        int k = 1;
        while ((j + k - 1) / k > i)
          k++;

        Pre[i][j] = k;
      }
    }

    for (t = 1; t <= T; t++) {
      int D = s.nextInt(), mx = 0;
      int[] P = new int[D];

      for (int i = 0; i < D; i++) {
        P[i] = s.nextInt();
        mx = Math.max(P[i], mx);
      }

      int best = mx;
      
      for (int i = 2; i <= mx; i++) {
        int local_best = 0;

        for (int j = 0; j < D; j++) {
          int k = Pre[i][P[j]];

          local_best += k - 1;
        }
        
        best = Math.min(best, local_best + i);
      }

      System.out.println("Case #" + t + ": " + best);
    }
  }

  public static class MyScanner {
    BufferedReader br;
    StringTokenizer st;
  
    public MyScanner() {
      br = new BufferedReader(new InputStreamReader(System.in));
    }
  
    String next() {
      while (st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }
  
    int nextInt() {
      return Integer.parseInt(next());
    }
  
    long nextLong() {
      return Long.parseLong(next());
    }
  
    double nextDouble() {
      return Double.parseDouble(next());
    }
  
    String nextLine(){
      String str = "";
      try {
        str = br.readLine();
      } catch (IOException e) {
        e.printStackTrace();
      }
      return str;
    }
 
  }
}
