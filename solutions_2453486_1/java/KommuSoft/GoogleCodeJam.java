/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.util.Scanner;

/**
 *
 * @author kommusoft
 */
public class GoogleCodeJam {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        for (int i = 1; i <= t; i++) {
            resolve(sc, i);
            if (i != t) {
                sc.nextLine();
            }
        }
    }

    private static void resolve(Scanner sc, int c) {
        char[][] val = new char[4][4];
        boolean empty = false;
        for (int i = 0; i < 4; i++) {
            String ln = sc.nextLine();
            for (int j = 0; j < 4; j++) {
                char cij = ln.charAt(j);
                if (cij == '.') {
                    empty = true;
                }
                val[i][j] = cij;
            }

        }
        char res;
        for (int i = 0; i < 4; i++) {
            res = searchHorizontal(val, i);
            if (res != 'T') {
                System.out.println(String.format("Case #%s: %s won", c, res));
                return;
            }
            res = searchVertical(val, i);
            if (res != 'T') {
                System.out.println(String.format("Case #%s: %s won", c, res));
                return;
            }
        }
        res = searchDiagonal(val, 0, 1);
        if (res != 'T') {
            System.out.println(String.format("Case #%s: %s won", c, res));
            return;
        }
        res = searchDiagonal(val, 3, -1);
        if (res != 'T') {
            System.out.println(String.format("Case #%s: %s won", c, res));
            return;
        }
        if (empty) {
            System.out.println(String.format("Case #%s: Game has not completed", c));
        } else {
            System.out.println(String.format("Case #%s: Draw", c));
        }
    }

    private static char searchHorizontal(char[][] val, int i) {
        int o = 0, t = 0, x = 0;
        for (int j = 0; j < 4; j++) {
            switch (val[i][j]) {
                case 'T':
                    t++;
                    break;
                case 'O':
                    o++;
                    break;
                case 'X':
                    x++;
                    break;
            }
        }
        if (o + t + x == 4) {
            if (o == 0) {
                return 'X';
            } else if (x == 0) {
                return 'O';
            } else {
                return 'T';
            }
        } else {
            return 'T';
        }
    }

    private static char searchDiagonal(char[][] val, int offset, int d) {
        int o = 0, t = 0, x = 0;
        int j = offset;
        for (int i = 0; i < 4; i++) {
            switch (val[i][j]) {
                case 'T':
                    t++;
                    break;
                case 'O':
                    o++;
                    break;
                case 'X':
                    x++;
                    break;
            }
            j += d;
        }
        if (o + t + x == 4) {
            if (o == 0) {
                return 'X';
            } else if (x == 0) {
                return 'O';
            } else {
                return 'T';
            }
        } else {
            return 'T';
        }
    }

    private static char searchVertical(char[][] val, int i) {
        int o = 0, t = 0, x = 0;
        for (int j = 0; j < 4; j++) {
            switch (val[j][i]) {
                case 'T':
                    t++;
                    break;
                case 'O':
                    o++;
                    break;
                case 'X':
                    x++;
                    break;
            }
        }
        if (o + t + x == 4) {
            if (o == 0) {
                return 'X';
            } else if (x == 0) {
                return 'O';
            } else {
                return 'T';
            }
        } else {
            return 'T';
        }
    }
}
