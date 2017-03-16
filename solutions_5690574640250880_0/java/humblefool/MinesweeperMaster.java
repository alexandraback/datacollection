import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class MinesweeperMaster {
    static Scanner input;
    static PrintWriter out;

    public static void main(String[] args) throws Exception {
        input = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        out = new PrintWriter(System.out);

        input = new Scanner(new BufferedReader(new FileReader("C-small-attempt0.in")));
        out = new PrintWriter(new FileWriter("C-small-attempt0.out"));

        int testCases = input.nextInt();
        for(int testCase = 1; testCase <= testCases; testCase++) {
            out.println("Case #" + testCase + ":");
            solveCase();
        }
        out.close();
    }
    
    static void solveCase() {
        int rows = input.nextInt(), cols = input.nextInt(), mines = input.nextInt();
        int empty = rows * cols  - mines;
        
        boolean rotated = false, possible = false;
        if (rows < cols) {
            rotated = true;
            int temp = rows; rows = cols; cols = temp;
        }
        
        char[][] board = new char[rows][cols];
        for(char[] row: board)
            Arrays.fill(row, '*');
                
        if(empty == 1) {
            possible = true;
        } else if (cols == 1) {
            possible = true;
            for(int i=0;i<empty;i++)
                board[i][0] = '.';
        } else if (cols == 2) {
            if(empty % 2 == 0 && empty >= 4) {
                possible = true;
                for(int i=0;i*2<empty;i++)
                    board[i][0] = board[i][1] = '.';
            }
        } else {
            if(empty >= 8 || empty == 6 || empty == 4) {
                possible = true;
                if(empty == 4) {
                    board[0][0] = board[0][1] =
                            board[1][0] = board[1][1] = '.';
                } else if (empty <= 3 * rows) {
                    empty -= 6;
                    fill3(board[0]);
                    fill3(board[1]);
                    
                    for(int row = 2;empty > 0;row++) {
                        if(empty == 2) {
                            board[row][0] = board[row][1] = '.';
                            empty -= 2;
                        } else if (empty == 4) {
                            board[row][0] = board[row][1] = '.';
                            board[row+1][0] = board[row+1][1] = '.';
                            empty -= 4;
                        } else {
                            fill3(board[row]);
                            empty -= 3;
                        }
                    }
                } else {
                    int filledCols = (empty + rows - 1) / rows;
                    for(int i=0;i<rows;i++)
                        for(int j=0;j+2<filledCols;j++)
                            board[i][j] = '.';
                    empty -= (filledCols - 2) * rows;
                    
                    int col = filledCols - 2;
                    empty -= 4;
                    board[0][col] = board[0][col+1] =
                            board[1][col] = board[1][col+1] = '.';
                    
                    for(int row = 2;empty>0;row++)
                        for(int index = 0; index < 2 && empty>0;index++,empty--)
                            board[row][col+index] = '.';

                }
            }
        }
        

        if(rotated) {
            char[][] rotBoard = new char[cols][rows];
            for(int i=0;i<rows;i++)
                for(int j=0;j<cols;j++)
                    rotBoard[j][i] = board[i][j];
            board = rotBoard;
            int temp = rows; rows = cols; cols = temp;
        }
        if (!possible)
            out.println("Impossible");
        else {
            board[0][0] = 'c';
            for(int i=0;i<rows;i++)
                out.println(board[i]);
        }
    }
    
    static void fill3(char[] row) {
        row[0] = row[1] = row[2] = '.';
    }
}
