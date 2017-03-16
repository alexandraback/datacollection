import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Lawnmower {
  public static void main(String[] args) throws IOException {
    Scanner in = new Scanner(new File("lawn.in"));
    PrintWriter out = new PrintWriter(new File("lawnbig.out"));
    
    int cases = in.nextInt();
    for (int caseOn = 1; caseOn <= cases; caseOn++) {
      int n = in.nextInt();
      int m = in.nextInt();
      
      boolean[][] good = new boolean[n][m];
      int[][] g = new int[n][m];
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          g[i][j] = in.nextInt();
        }
      }
      
      boolean works = true;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (!validRow(g, i, j) && !validCol(g, i, j)) {
            works = false;
          }
        }
      }
      
      if (works) {
        out.printf("Case #%d: YES\n", caseOn);
      } else {
        out.printf("Case #%d: NO\n", caseOn);
      }
    }
    
    out.close();
  }
  
  public static boolean validRow(int[][] g, int r, int c) {
    for (int i = 0; i < g[0].length; i++) {
      if (g[r][i] > g[r][c]) return false;
    }
    return true;
  }
  
  public static boolean validCol(int[][] g, int r, int c) {
    for (int i = 0; i < g.length; i++) {
      if (g[i][c] > g[r][c]) return false;
    }
    return true;
  }
}
