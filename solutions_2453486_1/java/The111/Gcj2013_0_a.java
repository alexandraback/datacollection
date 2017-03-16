package Gcj2013_0;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Gcj2013_0_a {
    final static String WORK_DIR = "C:\\eclipse\\workspace\\GoogleCodeJam\\IO\\2013_0\\";

    void solve(Scanner sc, PrintWriter pw) {

        char[][] grid = new char[4][4];
        
        for (int i = 0; i < 4; i++) {
            String s = sc.next();
            for (int j = 0; j < 4; j++) {
                grid[i][j] = s.charAt(j);
            }
        }
        
        // check if X or O won
        boolean X, O;
        
        // check horizontal
        for (int i = 0; i < 4; i++) {
            X = O = true;
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] != 'X' && grid[i][j] != 'T') {
                    X = false;
                }
                if (grid[i][j] != 'O' && grid[i][j] != 'T') {
                    O = false;
                }
            }
            if (O) {
                pw.println("O won");
                return;
            }
            if (X) {
                pw.println("X won");
                return;
            }
        }
        
        // check vertical
        for (int i = 0; i < 4; i++) {
            X = O = true;
            for (int j = 0; j < 4; j++) {
                if (grid[j][i] != 'X' && grid[j][i] != 'T') {
                    X = false;
                }
                if (grid[j][i] != 'O' && grid[j][i] != 'T') {
                    O = false;
                }
            }
            if (O) {
                pw.println("O won");
                return;
            }
            if (X) {
                pw.println("X won");
                return;
            }
        }
        
        // check diagonals
        
        X = O = true;
        for (int i = 0; i < 4; i++) {
            if (grid[i][i] != 'X' && grid[i][i] != 'T') {
                X = false;
            }
            if (grid[i][i] != 'O' && grid[i][i] != 'T') {
                O = false;
            }
        }
        if (O) {
            pw.println("O won");
            return;
        }
        if (X) {
            pw.println("X won");
            return;
        }
        
        X = O = true;
        for (int i = 0; i < 4; i++) {
            if (grid[i][3 - i] != 'X' && grid[i][3 - i] != 'T') {
                X = false;
            }
            if (grid[i][3 - i] != 'O' && grid[i][3 - i] != 'T') {
                O = false;
            }
        }
        if (O) {
            pw.println("O won");
            return;
        }
        if (X) {
            pw.println("X won");
            return;
        }
        
        // check if empty or full
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (grid[i][j] == '.') {
                    pw.println("Game has not completed");
                    return;
                }
            }
        }
        pw.println("Draw");
        return;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "A-large.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "A-large.out"));
        int T = sc.nextInt();
        for (int t=0; t<T; t++) {
            System.out.println("Processing test case " + (t + 1) + " of " + T);
            pw.print("Case #" + (t+1) + ": ");
            new Gcj2013_0_a().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
