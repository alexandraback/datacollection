import java.util.*;

public class A {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    for (int k = 1; k <= n; k++) {
      boolean hasDot = false;
      char[][] board = new char[4][4];
      for (int i = 0; i < 4; i++) {
        String line = in.next();
        for (int j = 0; j < 4; j++) {
          char c = line.charAt(j);
          if (c == '.') {
            hasDot = true;
          }
          board[i][j] = c;
        }
      }
      if (checkWin(copyBoard(board), 'X')) {
        System.out.printf("Case #%d: X won\n", k);
      } else if (checkWin(copyBoard(board), 'O')){
        System.out.printf("Case #%d: O won\n", k);
      } else if (hasDot) {
        System.out.printf("Case #%d: Game has not completed\n", k);
      } else {
        System.out.printf("Case #%d: Draw\n", k);
      }
    }
    in.close();
  }
  
  private static char[][] copyBoard(char[][] board) {
    char[][] newBoard = new char[4][4];
    for (int i = 0; i < 4; i++) {
      newBoard[i] = Arrays.copyOf(board[i], 4);
    }
    return newBoard;
  }
  
  private static boolean checkWin(char[][] board, char target) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (board[i][j] == 'T') {
          board[i][j] = target;
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      if (board[i][0] == target && board[i][1] == target &&
          board[i][2] == target && board[i][3] == target) {
        return true;
      }
    }
    for (int j = 0; j < 4; j++) {
      if (board[0][j] == target && board[1][j] == target &&
          board[2][j] == target && board[3][j] == target) {
        return true;
      }
    }
    if (board[0][0] == target && board[1][1] == target &&
        board[2][2] == target && board[3][3] == target) {
      return true;
    }
    if (board[0][3] == target && board[1][2] == target &&
        board[2][1] == target && board[3][0] == target) {
      return true;
    }
    return false;
  }
}