package gcj;

/*
 * Problem A. Tic-Tac-Toe-Tomek
Confused? Read the quick-start guide.
Small input
10 points 
Solve A-small
You may try multiple times, with penalties for wrong submissions.
Large input
20 points 
You must solve the small input first.
You will have 8 minutes to solve 1 input file. (Judged after contest.)
Problem

Tic-Tac-Toe-Tomek is a game played on a 4 x 4 square board. The board starts empty, except that a single 'T' symbol may appear in one of the 16 squares. There are two players: X and O. They take turns to make moves, with X starting. In each move a player puts her symbol in one of the empty squares. Player X's symbol is 'X', and player O's symbol is 'O'.

After a player's move, if there is a row, column or a diagonal containing 4 of that player's symbols, or containing 3 of her symbols and the 'T' symbol, she wins and the game ends. Otherwise the game continues with the other player's move. If all of the fields are filled with symbols and nobody won, the game ends in a draw. See the sample input for examples of various winning positions.

Given an 4 x 4 board description containing 'X', 'O', 'T' and '.' characters (where '.' represents an empty square), describing the current state of a game, determine the status of the Tic-Tac-Toe-Tomek game going on. The statuses to choose from are:

"X won" (the game is over, and X won)
"O won" (the game is over, and O won)
"Draw" (the game is over, and it ended in a draw)
"Game has not completed" (the game is not over yet)
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of 4 lines with 4 characters each, with each character being 'X', 'O', '.' or 'T' (quotes for clarity only). Each test case is followed by an empty line.

Output

For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is one of the statuses given above. Make sure to get the statuses exactly right. When you run your code on the sample input, it should create the sample output exactly, including the "Case #1: ", the capital letter "O" rather than the number "0", and so on.

Limits

The game board provided will represent a valid state that was reached through play of the game Tic-Tac-Toe-Tomek as described above.

Small dataset

1 ² T ² 10.

Large dataset

1 ² T ² 1000.

Sample


Input 
  
Output 
 
6
XXXT
....
OO..
....

XOXT
XXOO
OXOX
XXOO

XOX.
OX..
....
....

OOXX
OXXX
OX.T
O..O

XXXO
..O.
.O..
T...

OXXX
XO..
..O.
...O

Case #1: X won
Case #2: Draw
Case #3: Game has not completed
Case #4: O won
Case #5: O won
Case #6: O won

Note

Although your browser might not render an empty line after the last test case in the sample input, in a real input file there would be one.
 */
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class GCJ2013RQA {
  public static void main(String[] args) throws Exception {
    final String FILE_DIR = "/Users/jhorwitz/Downloads/";
    File inFile = new File(FILE_DIR + "A-large.in");
    File outFile = new File(FILE_DIR + "gcj2013-rq-A-l.txt");
    Writer w = new FileWriter(outFile);
    Scanner s = new Scanner(inFile);

    int T = s.nextInt();
    for (int t = 1; t <= T; ++t) {
      char[][] board = new char[4][4];
      for (int row = 0; row < 4; ++row) {
        board[row] = s.next().toCharArray();
      }
      output(w, t, getStatus(board));
    }
    s.close();
    w.close();
  }

  private static String getStatus(char[][] board) {
    // check for an across win
    for (int row = 0; row < 4; ++row) {
      if ( (board[row][0] == 'T' || board[row][0] == 'X')  &&  (board[row][1] == 'T' || board[row][1] == 'X')  &&  (board[row][2] == 'T' || board[row][2] == 'X')  &&  (board[row][3] == 'T' || board[row][3] == 'X') ) {
        return ("X won");
      }
      if ( (board[row][0] == 'T' || board[row][0] == 'O')  &&  (board[row][1] == 'T' || board[row][1] == 'O')  &&  (board[row][2] == 'T' || board[row][2] == 'O')  &&  (board[row][3] == 'T' || board[row][3] == 'O') ) {
        return ("O won");
      }
    }

    // check for a down win
    for (int col = 0; col < 4; ++col) {
      if ( (board[0][col] == 'T' || board[0][col] == 'X')  &&  (board[1][col] == 'T' || board[1][col] == 'X')  &&  (board[2][col] == 'T' || board[2][col] == 'X')  &&  (board[3][col] == 'T' || board[3][col] == 'X') ) {
        return ("X won");
      }
      if ( (board[0][col] == 'T' || board[0][col] == 'O')  &&  (board[1][col] == 'T' || board[1][col] == 'O')  &&  (board[2][col] == 'T' || board[2][col] == 'O')  &&  (board[3][col] == 'T' || board[3][col] == 'O') ) {
        return ("O won");
      }
    }

    // check for a diagonal win
    if ( (board[0][0] == 'T' || board[0][0] == 'X')  &&  (board[1][1] == 'T' || board[1][1] == 'X')  &&  (board[2][2] == 'T' || board[2][2] == 'X')  &&  (board[3][3] == 'T' || board[3][3] == 'X') ) {
      return ("X won");
    }
    if ( (board[0][0] == 'T' || board[0][0] == 'O')  &&  (board[1][1] == 'T' || board[1][1] == 'O')  &&  (board[2][2] == 'T' || board[2][2] == 'O')  &&  (board[3][3] == 'T' || board[3][3] == 'O') ) {
      return ("O won");
    }
    if ( (board[0][3] == 'T' || board[0][3] == 'X')  &&  (board[1][2] == 'T' || board[1][2] == 'X')  &&  (board[2][1] == 'T' || board[2][1] == 'X')  &&  (board[3][0] == 'T' || board[3][0] == 'X') ) {
      return ("X won");
    }
    if ( (board[0][3] == 'T' || board[0][3] == 'O')  &&  (board[1][2] == 'T' || board[1][2] == 'O')  &&  (board[2][1] == 'T' || board[2][1] == 'O')  &&  (board[3][0] == 'T' || board[3][0] == 'O') ) {
      return ("O won");
    }

    for (int row = 0; row < 4; ++row) {
      if (board[row][0] == '.' || board[row][1] == '.' || board[row][2] == '.' || board[row][3] == '.') {
        return ("Game has not completed");
      }
    }
    
    return ("Draw");
  }

  public static void output(Writer w, int t, String s) throws IOException {
    w.write("Case #" + t + ": " + s + "\n");
    System.out.println("Case #" + t + ": " + s);
  }
}