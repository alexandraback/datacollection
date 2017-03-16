import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class TicTacToeTomek {
  public static void main(String[] args) throws IOException {
    PrintWriter out = new PrintWriter(new File("TicTacToeTomek.out"));
    Scanner in = new Scanner(new File("TicTacToeTomek.in"));
    int cases = in.nextInt();

    for (int caseOn = 1; caseOn <= cases; caseOn++) {
      g = new char[4][4];
      for (int i = 0; i < 4; i++) {
        g[i] = in.next().toCharArray();
      }

      int[] dy = {-1, -1, 0, 1, 1, 1, 0, -1};
      int[] dx = {0, 1, 1, 1, 0, -1, -1, -1};

      char winner = ' ';
      boolean full = true;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          if (g[i][j] == '.') {
            full = false;
            continue;
          }
          if (g[i][j] == 'T') continue;
          for (int d = 0; d < dx.length; d++) {
            int cnt = count(g[i][j], i, j, dy[d], dx[d]);
            if (cnt == 4) {
              winner = g[i][j];
            }
          }
        }
      }


      out.printf("Case #%d: ", caseOn);
      if (winner == ' ') {
        if (full) {
          out.printf("Draw");
        } else {
          out.printf("Game has not completed");
        }
      } else {
        out.printf("%c won", winner);
      }
      out.println();
    }
    out.close();
  }

  static char[][] g;

  public static int count(char l, int y, int x, int dy, int dx) {
    if (y < 0 || x < 0 || y >= 4 || x >= 4) return 0;
    if (g[y][x] == 'T' || g[y][x] == l) return 1 + count(l, y + dy, x + dx, dy, dx);
    return 0;
  }
}
