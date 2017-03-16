package gcj2013.qual;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2013/qual/A-large";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        // out = new PrintWriter(System.out);
        for (int i = 1; i <= count; i++) {
            out.print("Case #" + i + ": ");
            
            int[][] board = new int[4][4];
            for(int j=0; j<4; j++) {
                String line = s.next();
                for(int k=0; k<4; k++) {
                    switch(line.charAt(k)) {
                        case 'X':
                            board[j][k] = 1;
                            break;
                        case 'O':
                            board[j][k] = 2;
                            break;
                        case 'T':
                            board[j][k] = 3;
                            break;
                    }
                }
            }
            String res = solve(board);
            out.print(res);
            out.println();          
        }
        out.close();
    }

    static String solve(int[][] b) {
        if(win(b, 1)) return "X won";
        if(win(b, 2)) return "O won";
        if(draw(b)) return "Draw";
        return "Game has not completed";
    }
    
    static boolean draw(int[][] b) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if(b[i][j] == 0) return false;
            }
        }
        return true;
    }
    static boolean win(int[][] b, int o) {
        boolean win;
        for(int i=0; i<4; i++) {
            win = true;
            for(int j=0; j<4; j++) {
                win &= (b[i][j] & o) != 0; 
            }
            if(win) return true;
            win = true;
            for(int j=0; j<4; j++) {
                win &= (b[j][i] & o) != 0; 
            }
            if(win) return true;
        }
        win = true;
        for(int i=0; i<4; i++) {
            win &= (b[i][i] & o) != 0;             
        }
        if(win) return true;
        win = true;
        for(int i=0; i<4; i++) {
            win &= (b[i][3-i] & o) != 0;             
        }
        return win;
    }

}
