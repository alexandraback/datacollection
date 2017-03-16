import java.io.File;
import java.util.Scanner;

public class cj1 {
  public static void main(String[] args) throws Exception {
    final Scanner scanner = new Scanner(new File("D:\\unsorted\\in.txt"));
    final int T = scanner.nextInt();
    for (int t = 1; t <= T; t++) {
      scanner.nextLine();
      final String[] lines = new String[4];
      for (int i = 0; i < lines.length; i++)
        lines[i] = scanner.nextLine();
      final char[][] board = new char[4][4];
      for (int i = 0; i < board.length; i++)
        for (int j = 0; j < board[i].length; j++)
          board[i][j] = lines[i].charAt(j);
      final boolean spacesOpen = lines[0].contains(".") || lines[1].contains(".") || lines[2].contains(".") || lines[3].contains(".");
      String result = getResult(board, spacesOpen);
      System.out.println("Case #" + t + ": " + result);
    }
  }

  public static String getResult(final char[][] board, final boolean spacesOpen) {
    if (check(board, 'X'))
      return "X won";
    if (check(board, 'O'))
      return "O won";
    return spacesOpen ? "Game has not completed" : "Draw";
  }

  public static boolean check(final char[][] board, final char player) {
    l1: for (int x = 0; x < board.length; x++) {
      for (int i = 0; i < board.length; i++)
        if (board[i][x] != player && board[i][x] != 'T')
          continue l1;
      return true;
    }
    l2: for (int x = 0; x < board.length; x++) {
      for (int i = 0; i < board.length; i++)
        if (board[x][i] != player && board[x][i] != 'T')
          continue l2;
      return true;
    }
    return check3(board, player) || check4(board, player);
  }

  public static boolean check3(final char[][] board, final char player) {
    for (int i = 0; i < board.length; i++)
      if (board[i][i] != player && board[i][i] != 'T')
        return false;
    return true;
  }

  public static boolean check4(final char[][] board, final char player) {
    for (int i = 0; i < board.length; i++)
      if (board[board.length - 1 - i][i] != player && board[board.length - 1 - i][i] != 'T')
        return false;
    return true;
  }
}
