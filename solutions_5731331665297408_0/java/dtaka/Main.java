import java.io.*;
import java.util.*;

public class Main{
  static final String ANSWER = "Case #%d: %s\n";
  static String ans = "";
  public static void main(String args[]) throws Exception {
    BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    String line;
    String[] prms;
    int T = Integer.parseInt(stdin.readLine());
    for (int t = 1; t <= T; t++) {
      line = stdin.readLine();
      prms = line.split(" ");
      int N = Integer.parseInt(prms[0]);
      int M = Integer.parseInt(prms[1]);
      
      int start = -1;
      String minzip = "99999";
      String[] zips = new String[N];
      for (int i = 0; i < N; i++) {
        zips[i] = stdin.readLine();
        if (minzip.compareTo(zips[i]) > 0) {
          minzip = zips[i];
          start = i;
        }
      }
      
      boolean[][] g = new boolean[N][N];
      for (int i = 0; i < M; i++) {
        line = stdin.readLine();
        prms = line.split(" ");
        int c1 = Integer.parseInt(prms[0])-1;
        int c2 = Integer.parseInt(prms[1])-1;
        g[c1][c2] = true;
        g[c2][c1] = true;
      }
      
      boolean[] flag = new boolean[N];
      StringBuffer buf = new StringBuffer();
      dfs(N, zips, g, flag, start, buf);
      
      System.out.printf(ANSWER, t, ans);
    }
  }
  static void dfs(int N, String[] zips, boolean[][] g, boolean[] flag, int parent, StringBuffer buf) {
    flag[parent] = true;
    buf.append(zips[parent]);
    if (buf.length() == N*5) {
      ans = buf.toString();
      return;
    }
    while (true) {
      String zip = null;
      int index = -1;
      for (int i = 0; i < N; i++) {
        if (g[parent][i] && !flag[i]) {
          if (zip == null || zip.compareTo(zips[i]) > 0) {
            zip = zips[i];
            index = i;
          }
        }
      }
      if (zip == null) break;
      dfs(N, zips, g, flag, index, buf);
    }
  }
}
