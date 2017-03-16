package ru.abishev.qual;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    public static String O_WON = "O won";
    public static String X_WON = "X won";
    public static String DRAW = "Draw";
    public static String NOT_COMPLETED = "Game has not completed";

    public static void run(Scanner input, PrintWriter output) {
        int t = input.nextInt();
        input.nextLine();
        for (int _t = 0; _t < t; _t++) {
            char[][] field = new char[4][4];
            for (int i = 0; i < 4; i++) {
                String line = input.nextLine();
                for (int j = 0; j < 4; j++) {
                    field[i][j] = line.charAt(j);
                }
            }
            input.nextLine();
            output.println("Case #" + (_t + 1) + ": " + solve(field));
        }
        output.flush();
    }

    private static boolean xWin(char winC, char c1, char c2, char c3, char c4) {
        int c = 0;

        if (c1 == winC) c++;
        if (c2 == winC) c++;
        if (c3 == winC) c++;
        if (c4 == winC) c++;

        if (c1 == 'T') c++;
        if (c2 == 'T') c++;
        if (c3 == 'T') c++;
        if (c4 == 'T') c++;

        return c == 4;
    }

    private static String solve(char[][] field) {
        // if X or O win?
        for (int i = 0; i < 4; i++) {
            if (xWin('O', field[i][0], field[i][1], field[i][2], field[i][3]) ||
                    xWin('O', field[0][i], field[1][i], field[2][i], field[3][i])) {
                return O_WON;
            }
            if (xWin('X', field[i][0], field[i][1], field[i][2], field[i][3]) ||
                    xWin('X', field[0][i], field[1][i], field[2][i], field[3][i])) {
                return X_WON;
            }
        }

        if (xWin('O', field[0][0], field[1][1], field[2][2], field[3][3]) ||
                xWin('O', field[0][3], field[1][2], field[2][1], field[3][0])) {
            return "O won";
        }

        if (xWin('X', field[0][0], field[1][1], field[2][2], field[3][3]) ||
                xWin('X', field[0][3], field[1][2], field[2][1], field[3][0])) {
            return "X won";
        }

        // not completed?
        int c = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (field[i][j] == '.') {
                    return NOT_COMPLETED;
                }
            }
        }

        // draw...
        return DRAW;
    }

    public static void main(String[] args) throws FileNotFoundException {
//        run(new Scanner(System.in), new PrintWriter(System.out));

        PrintWriter output = new PrintWriter(new FileOutputStream("./A-large.out"));
        run(new Scanner(new FileInputStream("./A-large.in")), output);
        output.close();
    }
}
