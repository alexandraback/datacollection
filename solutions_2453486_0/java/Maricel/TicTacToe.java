package A;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class TicTacToe {

    Scanner in;
    BufferedWriter out;
    private int ty;
    private int tx;
    private boolean canBeDraw;

    TicTacToe(String input, String output) throws Exception {
        in = new Scanner(new File(input));
        FileWriter fstream = new FileWriter(output);
        out = new BufferedWriter(fstream);
    }

    public static void main(String[] args) throws Exception {
        TicTacToe tictactoe = new TicTacToe("src/A/in", "src/A/out");
        tictactoe.solve();
        tictactoe.close();
    }

    public void solve() throws IOException {
        int n = in.nextInt();

        for (int i = 1; i <= n; i++) {
            canBeDraw = true;
            tx = ty = -1;
            in.nextLine();
            char[][] table = readTable();

            if (tx >= 0) {
                table[tx][ty] = 'X';
            }
            if (didPlayerWin(table, 'X')) {
                print(playerWon(i, 'X'));
                continue;
            }

            if (tx >= 0) {
                table[tx][ty] = 'O';
            }
            if (didPlayerWin(table, 'O')) {
                print(playerWon(i, 'O'));
                continue;
            }

            if (canBeDraw) {
                print(draw(i));
            } else {
                print(gameNotCompleted(i));
            }
        }
    }

    private char[][] readTable() {
        char[][] table = new char[4][4];
        for (int i = 0; i < 4; i++) {
            String line = in.nextLine();
            for (int j = 0; j < 4; j++) {
                table[i][j] = line.charAt(j);

                if (table[i][j] == 'T') {
                    tx = i;
                    ty = j;
                }

                if (table[i][j] == '.') {
                    canBeDraw = false;
                }
            }
        }
        return table;
    }

    private void print(String s) throws IOException {
        out.write(s);
    }

    private String playerWon(int test, char player) {
        return "Case #" + test + ": " + player + " won\n";
    }

    public String draw(int test) {
        return "Case #" + test + ": Draw\n";
    }

    public String gameNotCompleted(int test) {
        return "Case #" + test + ": Game has not completed\n";
    }

    private boolean didPlayerWin(char[][] t, char c) {
        for (int i = 0; i < 4; i++) {
            if ((t[i][0] == t[i][1])
                    && (t[i][0] == t[i][2])
                    && (t[i][0] == t[i][3])
                    && (t[i][0] == c)) {
                return true;
            }

            if ((t[0][i] == t[1][i])
                    && (t[0][i] == t[2][i])
                    && (t[0][i] == t[3][i])
                    && (t[0][i] == c)) {
                return true;
            }
        }

        if ((t[0][0] == t[1][1])
                && (t[0][0] == t[2][2])
                && (t[0][0] == t[3][3])
                && (t[0][0] == c)) {
            return true;
        }


        if ((t[0][3] == t[1][2])
                && (t[0][3] == t[2][1])
                && (t[0][3] == t[3][0])
                && (t[0][3] == c)) {
            return true;
        }

        return false;

    }

    private void close() throws IOException {
        this.in.close();
        this.out.close();
    }
}