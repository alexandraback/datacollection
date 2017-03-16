import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class TicTacToe {

  public static int[] mx = { 1, -1, 1, -1, 1, -1, 0, 0 };
  public static int[] my = { 1, -1, -1, 1, 0, 0, 1, -1 };

  public BufferedReader br;
  public char[][] grid;
  public boolean winX, winO;
  public int t, filled;

  public int get(char c, int x, int y, int d) {
    int ret = 1;
    for (int i = 1; grid[x+i*mx[d]][y+i*my[d]] == c || grid[x+i*mx[d]][y+i*my[d]] == 'T'; i++)
      ret++;
    for (int i = 1; grid[x+i*mx[d^1]][y+i*my[d^1]] == c || grid[x+i*mx[d^1]][y+i*my[d^1]] == 'T'; i++)
      ret++;
    return ret;
  }

  public void go() throws Throwable {
    br = new BufferedReader(new InputStreamReader(System.in));
    t = Integer.parseInt(br.readLine());
    grid = new char[6][6];
    for (int i = 0; i < 6; i++)
      Arrays.fill(grid[i], '.');
    for (int caseNo = 1; caseNo <= t; caseNo++) {
      filled = 0;
      for (int i = 1; i <= 4; i++) {
        String s = br.readLine();
        for (int j = 1; j <= 4; j++) {
          grid[i][j] = s.charAt(j - 1);
          if (grid[i][j] != '.')
            filled++;
        }
      }
      br.readLine();
      winX = winO = false;
      for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
          if (grid[i][j] == 'X') {
            int maxLen = 1;
            for (int k = 0; k < 8; k += 2)
              maxLen = max(maxLen, get('X', i, j, k));
            if (maxLen == 4)
              winX = true;
          }
      		else if (grid[i][j] == 'O') {
            int maxLen = 1;
            for (int k = 0; k < 8; k += 2)
              maxLen = max(maxLen, get('O', i, j, k));
            if (maxLen == 4)
              winO = true;
          }
      if (winX && winO)
        throw new RuntimeException();
      else if (winX)
        System.out.println("Case #" + caseNo + ": X won");
      else if (winO)
        System.out.println("Case #" + caseNo + ": O won");
      else if (filled == 16)
        System.out.println("Case #" + caseNo + ": Draw");
      else
        System.out.println("Case #" + caseNo + ": Game has not completed");
    }
  }

  public static void main(String[] args) throws Throwable {
    new TicTacToe().go();
  }

}
