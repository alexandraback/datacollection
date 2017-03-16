import java.util.*;
import java.io.*;

public class Main {
  public static void main(String[] args) throws Exception {
    Main p = new Main();
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
      N = fin.nextInt();
      M = fin.nextInt();
      int[][] board = new int[N][M];
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          board[i][j] = fin.nextInt();
        }
      }

      //run
      result = "YES";
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
          if (board[i][j] == 100) continue;
          boolean rowOkay = true;
          for (int k = 0; k < M; ++k) {
            if (board[i][k] > board[i][j]) rowOkay = false;
          }
          boolean colOkay = true;
          for (int k = 0; k < N; ++k) {
            if (board[k][j] > board[i][j]) colOkay = false;
          }
          if ((!rowOkay) && (!colOkay)) result = "NO";
        }
      }

      //output
      fout.printf("Case #%d: %s\n", tt, result);
    }

    fin.close();
    fout.close();
  }

  private int T;
  private int N, M;
}
