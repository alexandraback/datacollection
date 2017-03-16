/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 * @author ndkoval
 */
public class CodeJam {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter("output.txt");

        int[][] map = new int[4][4];

        int nTest = Integer.parseInt(br.readLine());
        for (int t = 1; t <= nTest; t++) {
            int count = 0;
            for (int i = 0; i < 4; i++) {
                String str = br.readLine();
                for (int j = 0; j < 4; j++) {
                    switch (str.charAt(j)) {
                        case 'X':
                            map[i][j] = 2;
                            break;
                        case 'O':
                            map[i][j] = 3;
                            break;
                        case 'T':
                            map[i][j] = 6;
                            break;
                        case '.':
                            map[i][j] = 7;
                            count++;
                            break;
                    }
                }
            }

            int win = 0;
            if (map[0][0] % 2 == 0 && map[0][1] % 2 == 0 && map[0][2] % 2 == 0 && map[0][3] % 2 == 0) {
                win = 1;
            }
            if (map[0][0] % 3 == 0 && map[0][1] % 3 == 0 && map[0][2] % 3 == 0 && map[0][3] % 3 == 0) {
                win = 2;
            }

            for (int i = 0; i < 4; i++) {
                if (map[i][0] % 2 == 0 && map[i][1] % 2 == 0 && map[i][2] % 2 == 0 && map[i][3] % 2 == 0) {
                    win = 1;
                }
                if (map[i][0] % 3 == 0 && map[i][1] % 3 == 0 && map[i][2] % 3 == 0 && map[i][3] % 3 == 0) {
                    win = 2;
                }

                if (map[0][i] % 2 == 0 && map[1][i] % 2 == 0 && map[2][i] % 2 == 0 && map[3][i] % 2 == 0) {
                    win = 1;
                }
                if (map[0][i] % 3 == 0 && map[1][i] % 3 == 0 && map[2][i] % 3 == 0 && map[3][i] % 3 == 0) {
                    win = 2;
                }
            }
            if (map[0][0] % 2 == 0 && map[1][1] % 2 == 0 && map[2][2] % 2 == 0 && map[3][3] % 2 == 0) {
                win = 1;
            }
            if (map[0][0] % 3 == 0 && map[1][1] % 3 == 0 && map[2][2] % 3 == 0 && map[3][3] % 3 == 0) {
                win = 2;
            }

            if (map[0][3] % 2 == 0 && map[1][2] % 2 == 0 && map[2][1] % 2 == 0 && map[3][0] % 2 == 0) {
                win = 1;
            }
            if (map[0][3] % 3 == 0 && map[1][2] % 3 == 0 && map[2][1] % 3 == 0 && map[3][0] % 3 == 0) {
                win = 2;
            }

            switch (win) {
                case 1:
                    pw.println("Case #" + t + ": X won");
                    break;
                case 2:
                    pw.println("Case #" + t + ": O won");
                    break;
                case 0:
                    if (count == 0) {
                        pw.println("Case #" + t + ": Draw");
                    } else {
                        pw.println("Case #" + t + ": Game has not completed");
                    }
            }

            br.readLine();
        }

        pw.close();
        br.close();
    }
}
