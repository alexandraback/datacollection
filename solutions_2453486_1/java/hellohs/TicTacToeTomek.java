package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Scanner;

public class TicTacToeTomek {

  private static String getResultString(int caseNo, int result) {
    String[] info = { "X won", "O won", "Draw", "Game has not completed" };
    return "Case #" + caseNo + ": " + info[result - 1];
  }

  private static int X = 1;
  private static int O = -1;
  private static int T = 1000;

  private static int X_WIN_VALUE = 1 + 1 + 1 + 1000;
  private static int O_WIN_VALUE = -1 - 1 - 1 + 1000;
  private static int X_WIN_VALUE_T = 1 + 1 + 1 + 1;
  private static int O_WIN_VALUE_T = -1 - 1 - 1 - 1;

  private static int determine(int[][] status, boolean hasBlank) {
    // diagonal
    int diagonal = status[0][0] + status[1][1] + status[2][2] + status[3][3];
    if (diagonal == X_WIN_VALUE || diagonal == X_WIN_VALUE_T) return 1;
    else if (diagonal == O_WIN_VALUE || diagonal == O_WIN_VALUE_T) return 2;

    diagonal = status[0][3] + status[1][2] + status[2][1] + status[3][0];
    if (diagonal == X_WIN_VALUE || diagonal == X_WIN_VALUE_T) return 1;
    else if (diagonal == O_WIN_VALUE || diagonal == O_WIN_VALUE_T) return 2;

    // row
    for (int i = 0; i < 4; i++) {
      int row = 0;
      for (int j = 0; j < 4; j++)
        row += status[i][j];
      if (row == X_WIN_VALUE || row == X_WIN_VALUE_T) return 1;
      else if (row == O_WIN_VALUE || row == O_WIN_VALUE_T) return 2;

    }

    // column
    for (int i = 0; i < 4; i++) {
      int col = 0;
      for (int j = 0; j < 4; j++)
        col += status[j][i];
      if (col == X_WIN_VALUE || col == X_WIN_VALUE_T) return 1;
      else if (col == O_WIN_VALUE || col == O_WIN_VALUE_T) return 2;

    }
    // no winner found
    return hasBlank ? 4 : 3;
  }

  public static void main(String[] args) throws Exception {
    String file = "D:\\A-large.in";
    Scanner cin = new Scanner(new File(file));
    Writer writer = new FileWriter(new File("D:\\t1-out.dat"));
    int n = Integer.parseInt(cin.nextLine());
    for (int caseNum = 1; caseNum <= n; caseNum++) {
      // one case
      boolean hasBlank = false;
      int[][] status = new int[4][4];
      for (int k = 0; k < 4; k++) {
        String line = cin.nextLine();
        // System.out.println(line);
        for (int j = 0; j < 4; j++) {
          char c = line.charAt(j);
          if (c == 'X') status[k][j] = X;
          else if (c == 'O') status[k][j] = O;
          else if (c == 'T') status[k][j] = T;
          else hasBlank = true;
        }
      }
      cin.nextLine();
      // process
      int result = determine(status, hasBlank);
      writer.append(getResultString(caseNum, result) + "\n");
    }
    writer.close();
    cin.close();
    System.out.println("Finished.");
  }
}
