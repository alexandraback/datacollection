import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class C_Masking {

  static String inputFile = "C-small-attempt8.in";
  static String outputFile = "C-small-attempt8.out";
  
  public static void main(String[] args) throws FileNotFoundException {
    Scanner in = new Scanner(new File(inputFile));
    out = new PrintWriter(new File(outputFile));
    
    int T = in.nextInt();
    for (int t = 1; t <= T; t++) {
      n = in.nextInt();
      m = in.nextInt();
      mines = in.nextInt();
      out.println("Case #" + t + ":");
//      out.println("Case #" + t + ": " + n + " " + m + " " + mines);
      System.out.println(t);
      solve(n, m, mines);
    }
    out.close();
  }


  private static void solve(int n, int m, int mines) {
    
    if(mines == n*m - 1){
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if(i + j == 0){
            out.print('c');
          }
          else {
            out.print('*');
          }
        }
        out.println();
      }
      return ;
    }
    
    int rows[] = new int[n];
    map = new int[n][m];
    found = false;
    dfs(rows, 0, 0);
    if(!found)
      out.println("Impossible");
  }

  static int n;
  static int m;
  static int mines;
  
  static PrintWriter out;
  
  static int di[] = new int[]{-1,-1,-1,0,1,1,1,0};
  static int dj[] = new int[]{-1,0,1,1,1,0,-1,-1};
  static int map[][];
  static int MINE = 9;
  
  static boolean found;
  private static void dfs(int[] rows, int row, int currentMines) {
    if(found || currentMines > mines) {
      return ;
    }
    if(row == n) {
      if(currentMines == mines) {
        int si = -1;
        int sj = -1;
        
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            if((rows[i] & (1 << j)) == 0){
              map[i][j] = 0;
            }
            else {
              map[i][j] = MINE;
            }
          }     
        }
        
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            if(map[i][j] == MINE) continue;
            for (int k = 0; k < di.length; k++) {
              int ni = i + di[k];
              int nj = j + dj[k];
              if(ni >= 0 && ni < n && nj >= 0 && nj < m && map[ni][nj] == MINE){
                map[i][j]++;
              }
            }
          }
        }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            if(map[i][j] == 0){
              si = i;
              sj = j;
              break;
            }
          }
        }
        if(si == -1) return ;
        int done[][] = new int[n][m];
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(si);
        q.add(sj);
        done[si][sj] = 1;
        while(!q.isEmpty()) {
          int ii = q.poll();
          int jj = q.poll();
          for (int i = 0; i < di.length; i++) {
            int ni = ii + di[i];
            int nj = jj + dj[i];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && done[ni][nj] == 0) {
              if(map[ni][nj] == 0){
                done[ni][nj] = 1;
                q.add(ni);
                q.add(nj);
              }
              else if(map[ni][nj] < MINE) {
                done[ni][nj] = 1;
              }
            }
          }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
            count += done[i][j];
          }
        }
        if(count == n*m - mines){
          found = true;
          int ok = 0;
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
              if(map[i][j] == MINE){
                out.print('*');
              }
              else if(map[i][j] == 0 && ok == 0){
                ok = 1;
                out.print('c');
              }else {
                out.print('.');
              }
            }
            out.println();
          }
        }
      }
      return ;
    }
    
    for (int mask = 0; mask < 1 << m; mask++) {
      rows[row] = mask;
      dfs(rows, row + 1, currentMines + Integer.bitCount(mask));
    }
  }


}
