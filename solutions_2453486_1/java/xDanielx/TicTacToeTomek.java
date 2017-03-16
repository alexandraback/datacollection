import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class TicTacToeTomek {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = sc.nextInt(); sc.nextLine();
    for (int t = 1; t <= T; ++t) {
      List<String> board = new ArrayList<String>();
      for (;;) {
        String line = sc.nextLine();
        if (line.isEmpty()) break;
        board.add(line);
      }
      System.out.printf("Case #%d: %s\n", t, getResult(board));
    }
  }

  private static String getResult(List<String> board) {
    for (char player : new char[] {'X', 'O'})
      if (hasPlayerWon(player, board))
        return player + " won";
    return isBoardFull(board) ? "Draw" : "Game has not completed";
  }

  private static boolean isBoardFull(List<String> board) {
    for (String row : board)
      if (row.contains("."))
        return false;
    return true;
  }

  private static boolean hasPlayerWon(char player, List<String> board) {
    for (int r0 = 0; r0 < 4; ++r0)
      for (int c0 = 0; c0 < 4; ++c0) {
        for (int[] delta : new int[][] {{1, 0}, {0, 1}, {1, 1}, {1, -1}}) {
          try {
            boolean streak = true;
            for (int i = 0; i < 4; ++i) {
              int r = r0 + i * delta[0], c = c0 + i * delta[1];
              streak &= Arrays.asList(player, 'T').contains(board.get(r).charAt(c));
            }
            if (streak) return true;
          } catch (IndexOutOfBoundsException e) {}
        }
      }
    return false;
  }
}
