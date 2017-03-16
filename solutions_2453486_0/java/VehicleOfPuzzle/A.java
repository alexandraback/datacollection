import java.util.*;

class A {
  private final static int SIZE = 4;
  private static char[][] grid = new char[SIZE][];

  private static int[][] da = {
    {0, 1},
    {1, 0},
    {1, 1},
    {1, -1}
  };

  public static void main(String[] arg) {
    Scanner sc = new Scanner(System.in);
    int tcc = Integer.parseInt(sc.nextLine());
    for (int tc = 1; tc <= tcc; ++tc) {
      for (int i = 0; i < SIZE; ++i) grid[i] = sc.nextLine().toCharArray();
      sc.nextLine();

      String winner = null;
      boolean hasEmpty = false;
      for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
          for (int[] d: da) if (winner == null) winner = score(i, j, d);
          if (grid[i][j] == '.') {
            hasEmpty = true;
            continue;
          }
        }
      }

      System.out.printf("Case #%d: ", tc);
      if (winner == null) {
        System.out.println(hasEmpty ? "Game has not completed" : "Draw");
      } else {
        System.out.print(winner);
        System.out.println(" won");
      }
    }
  }

  private static String score(int r, int c, int[] d) {
    int x = 0, o = 0;
    for (int pos = 0; pos < SIZE; ++pos) {
      int nr = r + pos * d[0];
      int nc = c + pos * d[1];
      if (nr >= 0 && nr < SIZE && nc >= 0 && nc < SIZE) {
        switch (grid[nr][nc]) {
          case 'X': ++x; break;
          case 'O': ++o; break;
          case 'T': ++x; ++o; break;
        }          
      }
    }

    if (x == SIZE) return "X";
    if (o == SIZE) return "O";
    return null;
  }
}
