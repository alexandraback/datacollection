import java.util.*;

public class Tic {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int numTests = in.nextInt();
    StringBuilder out = new StringBuilder();
    for (int testNum = 1; testNum <= numTests; ++testNum) {
      out.append(String.format("Case #%d: ", testNum));
      char[][] grid = new char[4][];
      for (int i = 0; i < 4; ++i)
        grid[i] = (in.next()).toCharArray();
      if (isWon(grid, 'X')) {
        out.append("X won\n");
      } else if (isWon(grid, 'O')) {
        out.append("O won\n");
      } else if (!isOver(grid)) {
        out.append("Game has not completed\n");
      } else {
        out.append("Draw\n");
      }
    }
    System.out.print(out);
  }
  
  public static boolean isOver(char[][] game) {
    int dotCount = 0;
    for (char[] cc: game)
      for (char c: cc) {
        if (c == '.')
          ++dotCount;
      }
    return dotCount == 0;
  }
  
  public static boolean isWon(char[][] game, char c) {
    // horizontal
    for (int r = 0; r < game.length; ++r) {
      int tCount = 0;
      int cCount = 0;
      for (int col = 0; col < game[r].length; ++col) {
        if (game[r][col] == 'T')
          ++tCount;
        else if (game[r][col] == c)
          ++cCount;
      }
      if ( (cCount == 3 && tCount == 1) || cCount == 4)
        return true;
    }
    // vertical
    for (int col = 0; col < game[0].length; ++col) {
      int tCount = 0;
      int cCount = 0;
      for (int r = 0; r < game.length; ++r) {
        if (game[r][col] == 'T')
          ++tCount;
        else if (game[r][col] == c)
          ++cCount;
      }
      if ( (cCount == 3 && tCount == 1) || cCount == 4)
        return true;
    }
    
    // downright diagonal
    int tCount = 0;
    int cCount = 0;
    for (int d = 0; d < game.length; ++d) {
      if (game[d][d] == 'T')
        ++tCount;
      else if (game[d][d] == c)
        ++cCount;
    }
    if ( (cCount == 3 && tCount == 1) || cCount == 4)
      return true;
    
    //upright diagonal
    tCount = 0;
    cCount = 0;
    for (int d = 0; d < game.length; ++d) {
      if (game[d][game[d].length-d-1] == 'T')
        ++tCount;
      else if (game[d][game[d].length-d-1] == c)
        ++cCount;
    }
    if ( (cCount == 3 && tCount == 1) || cCount == 4)
        return true;
    return false;
  }
}