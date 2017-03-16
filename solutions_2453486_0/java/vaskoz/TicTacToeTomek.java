package qual2013;

import java.io.File;
import java.io.FileReader;
import java.util.Scanner;

public class TicTacToeTomek {

    private final char[][] board = new char[4][4];

    public TicTacToeTomek(String[] board) {
        for (int i = 0; i < 4; i++) {
            this.board[i] = board[i].toCharArray();
        }
    }

    public String status() {
        boolean fullBoard = true;

        // horizontal
        for (int i = 0; i < 4; i++) {
            int wildcard = 0;
            int xc = 0;
            int oc = 0;
            for (int j = 0; j < 4; j++) {
                char target = this.board[i][j];
                if (target == 'X') xc++;
                else if (target == 'O') oc++;
                else if (target == '.') fullBoard = false;
                else if (target == 'T') wildcard = 1;
            }
            if (xc + wildcard == 4) return "X won";
            if (oc + wildcard == 4) return "O won";
        }

        // vertical
        for (int i = 0; i < 4; i++) {
            int wildcard = 0;
            int xc = 0;
            int oc = 0;
            for (int j = 0; j < 4; j++) {
                char target = this.board[j][i];
                if (target == 'X') xc++;
                else if (target == 'O') oc++;
                else if (target == '.') fullBoard = false;
                else if (target == 'T') wildcard = 1;
            }
            if (xc + wildcard == 4) return "X won";
            if (oc + wildcard == 4) return "O won";
        }

        // diagonals
        int wildcard = 0;
        int xc = 0;
        int oc = 0;
        for (int i = 0; i < 4; i++) {
            char target = this.board[i][i];
            if (target == 'X') xc++;
            else if (target == 'O') oc++;
            else if (target == '.') fullBoard = false;
            else if (target == 'T') wildcard = 1;
            if (xc + wildcard == 4) return "X won";
            if (oc + wildcard == 4) return "O won";
        }
        wildcard = 0;
        xc = 0;
        oc = 0;
        for (int i = 0; i < 4; i++) {
            char target = this.board[i][3-i];
            if (target == 'X') xc++;
            else if (target == 'O') oc++;
            else if (target == '.') fullBoard = false;
            else if (target == 'T') wildcard = 1;
            if (xc + wildcard == 4) return "X won";
            if (oc + wildcard == 4) return "O won";
        }

        // if all full, but no winners, then draw.
        if (fullBoard)
            return "Draw";
        else
            return "Game has not completed";
    }

    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(new FileReader(new File(args[0])));
        int N = input.nextInt();
        input.nextLine();

        for (int i = 1; i <= N; i++) {
            String[] board = new String[4];
            for (int j = 0; j < board.length; j++) {
                board[j] = input.nextLine();
            }
            TicTacToeTomek tic = new TicTacToeTomek(board);
            System.out.println("Case #" + i + ": " + tic.status());
            if (input.hasNextLine()) input.nextLine();
        }
    }
}