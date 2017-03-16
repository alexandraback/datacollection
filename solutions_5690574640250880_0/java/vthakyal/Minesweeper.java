import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by vivek on 12/04/14.
 */
public class Minesweeper {
   private static boolean FOUND = false;

   private static class Board {
      char[][] board;
      int nonMines;
      int rows;
      int columns;

      public Board(int r, int c) {
         this.rows = r;
         this.columns = c;
         this.board = new char[r][c];

         for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
               board[i][j] = '*';
            }
         }
         this.nonMines = 0;
      }
   }

   private static class Pair {
      int r;
      int c;

      public Pair(int row, int col) {
         r = row;
         c = col;
      }
   }

   public static void main(String[] args) throws IOException {
      BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

      int tests = Integer.parseInt(reader.readLine().trim());
      for (int test = 1; test <= tests; test++) {
         String[] inputs = reader.readLine().trim().split(" ");
         int r = Integer.parseInt(inputs[0]);
         int c = Integer.parseInt(inputs[1]);
         int m = Integer.parseInt(inputs[2]);
         out.println("Case #" + test + ":");
         Board board = getBoard(r, c, r * c - m);
         printBoard(board, out);
      }
      out.flush();
      out.close();
   }

   private static Board getBoard(int r, int c, int m) {
      FOUND = false;
      Board board = new Board(r, c);
      if (m == 1) {
         board.board[0][0] = 'c';
         return board;
      }

      backtrack(board, m);

      if (!FOUND) {
         return null;
      } else {
         return board;
      }
   }

   private static void backtrack(Board board, int m) {
      if (FOUND || board.nonMines > m) return;
      if (isSolution(board, m)) {
         FOUND = true;
         processSol(board, m);
      } else {
         List<Pair> candidates = constructCandidates(board, m);
         for (Pair candidate : candidates) {
            int nonMines = board.nonMines;
            preProcess(board, candidate);
            if (board.nonMines > nonMines) {
               backtrack(board, m);
            }
            if (FOUND) return;
            postProcess(board, candidate);
         }
      }
   }

   private static List<Pair> constructCandidates(Board board, int m) {
      List<Pair> candidates = new ArrayList<Pair>();
      if (board.nonMines == 0) {
         for (int i = 0; i < board.rows; i++) {
            for (int j = 0; j < board.columns; j++) {
               candidates.add(new Pair(i, j));
            }
         }
      } else {
         for (int i = 0; i < board.rows; i++) {
            for (int j = 0; j < board.columns; j++) {
               if (idDot(board, i, j)) {
                  candidates.add(new Pair(i, j));
               }
            }
         }
      }
      return candidates;
   }

   private static boolean idDot(Board board, int i, int j) {
      return board.board[i][j] == '.';
   }

   private static void preProcess(Board board, Pair pair) {
      board.board[pair.r][pair.c] = '0';
      if (board.nonMines == 0) {
         board.nonMines++;
      }
      mark(board, pair.r, pair.c - 1);
      mark(board, pair.r, pair.c + 1);
      mark(board, pair.r - 1, pair.c - 1);
      mark(board, pair.r - 1, pair.c);
      mark(board, pair.r - 1, pair.c + 1);
      mark(board, pair.r + 1, pair.c - 1);
      mark(board, pair.r + 1, pair.c);
      mark(board, pair.r + 1, pair.c + 1);
   }

   private static void mark(Board board, int r, int c) {
      if (r >= 0 && r < board.rows && c >= 0 && c < board.columns && board.board[r][c] == '*') {
         board.board[r][c] = '.';
         board.nonMines++;
      }
   }

   private static void postProcess(Board board, Pair pair) {
      board.board[pair.r][pair.c] = '.';
      unMark(board, pair.r, pair.c - 1);
      unMark(board, pair.r, pair.c + 1);
      unMark(board, pair.r - 1, pair.c - 1);
      unMark(board, pair.r - 1, pair.c);
      unMark(board, pair.r - 1, pair.c + 1);
      unMark(board, pair.r + 1, pair.c - 1);
      unMark(board, pair.r + 1, pair.c);
      unMark(board, pair.r + 1, pair.c + 1);
      if (board.nonMines == 1) {
         board.nonMines = 0;
         board.board[pair.r][pair.c] = '*';
      }
   }

   private static void unMark(Board board, int r, int c) {
      if (r >= 0 && r < board.rows && c >= 0 && c < board.columns && !isConnected(board, r, c)) {
         board.board[r][c] = '*';
         board.nonMines--;
      }
   }

   private static boolean isConnected(Board board, int r, int c) {
      return isZero(board, r, c) ||
            isZero(board, r, c - 1) ||
            isZero(board, r, c + 1) ||
            isZero(board, r - 1, c - 1) ||
            isZero(board, r - 1, c) ||
            isZero(board, r - 1, c + 1) ||
            isZero(board, r + 1, c - 1) ||
            isZero(board, r + 1, c) ||
            isZero(board, r + 1, c + 1);
   }

   private static boolean isZero(Board board, int r, int c) {
      return r >= 0 && r < board.rows && c >= 0 && c < board.columns && board.board[r][c] == '0';
   }

   private static void processSol(Board board, int m) {
      int r = -1;
      int c = -1;
      for (int i = 0; i < board.rows; i++) {
         for (int j = 0; j < board.columns; j++) {
            if (board.board[i][j] == '0') {
               r = i;
               c = j;
               board.board[i][j] = '.';
            }
         }
      }

      if (r != -1 && c != -1) {
         board.board[r][c] = 'c';
      }
   }

   private static boolean isSolution(Board board, int m) {
      return board.nonMines == m;
   }

   private static void printBoard(Board board, PrintWriter out) {
      if (board == null) {
         out.println("Impossible");
      } else {
         for (char[] row : board.board) {
            for (char cell : row) {
               out.print(cell);
            }
            out.println();
         }
      }
   }

}
