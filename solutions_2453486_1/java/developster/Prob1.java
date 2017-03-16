package codejam.y2013.q;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Prob1 {
    
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("/Users/octavian/codejam/A-large.in.txt"));
        FileWriter writer = new FileWriter(new File("/Users/octavian/codejam/A-large.out.txt"));
        char[][] t = new char[4][4];
        int n = scanner.nextInt();
        int c = 1;
        for (int i = 0; i < n; i++) {
            scanner.nextLine();
            for (int j = 0; j < 4; j++) {
                String l = scanner.nextLine();
                t[j][0] = l.charAt(0);
                t[j][1] = l.charAt(1);
                t[j][2] = l.charAt(2);
                t[j][3] = l.charAt(3);
            }
            
            boolean xwon, owon;
            xwon = won(t, 'X', 0, 0, 1, 1, 2, 2, 3, 3);
            owon = won(t, 'O', 0, 0, 1, 1, 2, 2, 3, 3);
            xwon |= won(t, 'X', 0, 3, 1, 2, 2, 1, 3, 0);
            owon |= won(t, 'O', 0, 3, 1, 2, 2, 1, 3, 0);
            for (int j = 0; j < 4; j++) {
                xwon |= won(t, 'X', j, 0, j, 1, j, 2, j, 3);
                owon |= won(t, 'O', j, 0, j, 1, j, 2, j, 3);
                xwon |= won(t, 'X', 0, j, 1, j, 2, j, 3, j);
                owon |= won(t, 'O', 0, j, 1, j, 2, j, 3, j);
            }
            
            boolean hasMoves = false;
            for (int a = 0; a < 4; a++) {
                for (int b = 0; b < 4; b++) {
                    if (t[a][b] == '.') {
                        hasMoves = true;
                    }
                }
            }
            
            writer.write("Case #" + (c++) + ": ");
            if (xwon) {
                if (owon) {
                    writer.write("Draw\n");
                } else {
                    writer.write("X won\n");
                }
            } else {
                if (owon) {
                    writer.write("O won\n");
                } else {
                    if (hasMoves) {
                        writer.write("Game has not completed\n");
                    } else {
                        writer.write("Draw\n");
                    }
                }
            }
        }
        writer.close();
        scanner.close();
    }
    
    private static boolean won(char[][] t, char c, int i0, int j0, int i1, int j1, int i2, int j2, int i3, int j3) {
        return (t[i0][j0] == c || t[i0][j0] == 'T')
                && (t[i1][j1] == c || t[i1][j1] == 'T')
                && (t[i2][j2] == c || t[i2][j2] == 'T')
                && (t[i3][j3] == c || t[i3][j3] == 'T');
    }
    
}
