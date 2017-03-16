
import java.io.*;
import java.util.*;

public class TicTacToeTomek {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    char[][] board = new char[4][];
    
    public void doCase(int caseNumber) throws Exception {
        for(int i = 0; i < 4; i++) {
            String line = in.readLine();
            board[i] = line.toCharArray();
        }
        in.readLine();
        
        for(int i = 0; i < 4; i++) {
            if((board[i][0]=='X' || board[i][0]=='T') &&
                    (board[i][1]=='X' || board[i][1]=='T') &&
                    (board[i][2]=='X' || board[i][2]=='T') &&
                    (board[i][3]=='X' || board[i][3]=='T')) {
                System.out.println("X won");
                return;
            }
            if((board[i][0]=='O' || board[i][0]=='T') &&
                    (board[i][1]=='O' || board[i][1]=='T') &&
                    (board[i][2]=='O' || board[i][2]=='T') &&
                    (board[i][3]=='O' || board[i][3]=='T')) {
                System.out.println("O won");
                return;
            }
            if((board[0][i]=='X' || board[0][i]=='T') &&
                    (board[1][i]=='X' || board[1][i]=='T') &&
                    (board[2][i]=='X' || board[2][i]=='T') &&
                    (board[3][i]=='X' || board[3][i]=='T')) {
                System.out.println("X won");
                return;
            }
            if((board[0][i]=='O' || board[0][i]=='T') &&
                    (board[1][i]=='O' || board[1][i]=='T') &&
                    (board[2][i]=='O' || board[2][i]=='T') &&
                    (board[3][i]=='O' || board[3][i]=='T')) {
                System.out.println("O won");
                return;
            }
        }
        if((board[0][0]=='X' || board[0][0]=='T') &&
                (board[1][1]=='X' || board[1][1]=='T') &&
                (board[2][2]=='X' || board[2][2]=='T') &&
                (board[3][3]=='X' || board[3][3]=='T')) {
            System.out.println("X won");
            return;
        }
        if((board[0][0]=='O' || board[0][0]=='T') &&
                (board[1][1]=='O' || board[1][1]=='T') &&
                (board[2][2]=='O' || board[2][2]=='T') &&
                (board[3][3]=='O' || board[3][3]=='T')) {
            System.out.println("O won");
            return;
        } 
        if((board[3][0]=='X' || board[3][0]=='T') &&
                (board[2][1]=='X' || board[2][1]=='T') &&
                (board[1][2]=='X' || board[1][2]=='T') &&
                (board[0][3]=='X' || board[0][3]=='T')) {
            System.out.println("X won");
            return;
        }
        if((board[3][0]=='O' || board[3][0]=='T') &&
                (board[2][1]=='O' || board[2][1]=='T') &&
                (board[1][2]=='O' || board[1][2]=='T') &&
                (board[0][3]=='O' || board[0][3]=='T')) {
            System.out.println("O won");
            return;
        } 
        
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(board[i][j]=='.') {
                    System.out.println("Game has not completed");
                    return;
                }
            }
        }
        System.out.println("Draw");
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    public static void main(String[] args) throws Exception {
        new TicTacToeTomek().run();
    }

}
