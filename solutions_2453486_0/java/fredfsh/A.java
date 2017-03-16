import java.util.*;
import java.io.*;

public class A {
  public static void main(String[] args) throws Exception {
    A p = new A();
    p.run(args[0]);
  }

  private void run(String inputFileName) throws Exception {
    Scanner fin = new Scanner(new BufferedInputStream(
          new FileInputStream(inputFileName)));
    PrintWriter fout = new PrintWriter(new BufferedWriter(
          new FileWriter(inputFileName + ".out")));

    T = fin.nextInt();
    fin.nextLine();
    for (int tt = 1; tt <= T; ++tt) {
      String result = "";

      //input
      char[][] board = new char[4][4];
      boolean complete = true;
      for (int i = 0; i < 4; ++i) {
        String line = fin.nextLine();
        for (int j = 0; j < 4; ++j) {
          board[i][j] = line.charAt(j);
          if (board[i][j] == '.') complete = false;
        }
      }
      fin.nextLine();

      //run
      boolean xNotLose = true;
      boolean oNotLose = true;
      // check row
      if (result.equals("")) {
        for (int i = 0; i < 4; ++i) {
          xNotLose = true;
          oNotLose = true;
          for (int j = 0; j < 4; ++j) {
            switch (board[i][j]) {
              case 'T':
                break;
              case '.':
                xNotLose = false;
                oNotLose = false;
                break;
              case 'X':
                oNotLose = false;
                break;
              case 'O':
                xNotLose = false;
                break;
              default:
                break;
            }
          }
          if (xNotLose) result = "X won";
          if (oNotLose) result = "O won";
        }
      }
      // check column
      if (result.equals("")) {
        for (int i = 0; i < 4; ++i) {
          xNotLose = true;
          oNotLose = true;
          for (int j = 0; j < 4; ++j) {
            switch (board[j][i]) {
              case 'T':
                break;
              case '.':
                xNotLose = false;
                oNotLose = false;
                break;
              case 'X':
                oNotLose = false;
                break;
              case 'O':
                xNotLose = false;
                break;
              default:
                break;
            }
          }
          if (xNotLose) result = "X won";
          if (oNotLose) result = "O won";
        }
      }
      // check diagnal
      if (result.equals("")) {
        xNotLose = true;
        oNotLose = true;
        for (int i = 0; i < 4; ++i) {
          switch (board[i][i]) {
            case 'T':
              break;
            case '.':
              xNotLose = false;
              oNotLose = false;
              break;
            case 'X':
              oNotLose = false;
              break;
            case 'O':
              xNotLose = false;
              break;
            default:
              break;
          }
        }
        if (xNotLose) result = "X won";
        if (oNotLose) result = "O won";

        xNotLose = true;
        oNotLose = true;
        for (int i = 0; i < 4; ++i) {
          switch (board[3 - i][i]) {
            case 'T':
              break;
            case '.':
              xNotLose = false;
              oNotLose = false;
              break;
            case 'X':
              oNotLose = false;
              break;
            case 'O':
              xNotLose = false;
              break;
            default:
              break;
          }
        }
        if (xNotLose) result = "X won";
        if (oNotLose) result = "O won";
      }

      if (result.equals("")) {
        result = complete ? "Draw" : "Game has not completed";
      }

      //output
      System.out.printf("Case #%d: %s\n", tt, result);
    }

  }

  private int T;
  private int N, M;
}
