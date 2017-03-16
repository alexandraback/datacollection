package googlecodejam.tictac;

import java.util.ArrayList;

public class Tablero {

    public ArrayList<char[]> hor;

    public Tablero(ArrayList<String> lines) {
        hor = new ArrayList();
        for (String s : lines) {
            hor.add(s.toCharArray());
        }
    }

    public boolean isWinner(char c) {
        return isWinnerH(c) || isWinnerD(c) || isWinnerV(c);
    }

    public boolean isWinnerV(char c) {
        for (int i = 0; i < 4; i++) {
            if ((hor.get(0)[i] == c || hor.get(0)[i] == 'T')
                    && (hor.get(1)[i] == c || hor.get(1)[i] == 'T')
                    && (hor.get(2)[i] == c || hor.get(2)[i] == 'T')
                    && (hor.get(3)[i] == c || hor.get(3)[i] == 'T')) {
                return true;
            }
        }
        return false;
    }

    public boolean isWinnerH(char c) {
        for (int i = 0; i < 4; i++) {
            if ((hor.get(i)[0] == c || hor.get(i)[0] == 'T')
                    && (hor.get(i)[1] == c || hor.get(i)[1] == 'T')
                    && (hor.get(i)[2] == c || hor.get(i)[2] == 'T')
                    && (hor.get(i)[3] == c || hor.get(i)[3] == 'T')) {
                return true;
            }
        }
        return false;
    }

    public boolean isWinnerD(char c) {
        if ((hor.get(0)[0] == c || hor.get(0)[0] == 'T')
                && (hor.get(1)[1] == c || hor.get(1)[1] == 'T')
                && (hor.get(2)[2] == c || hor.get(2)[2] == 'T')
                && (hor.get(3)[3] == c || hor.get(3)[3] == 'T')) {
            return true;
        }
        if ((hor.get(0)[3] == c || hor.get(0)[3] == 'T')
                && (hor.get(1)[2] == c || hor.get(1)[2] == 'T')
                && (hor.get(2)[1] == c || hor.get(2)[1] == 'T')
                && (hor.get(3)[0] == c || hor.get(3)[0] == 'T')) {
            return true;
        }
        return false;
    }

    public boolean isFinished() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (hor.get(i)[j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }

    @Override
    public String toString() {
        if (isWinner('X')) {
            return "X won";
        }
        if (isWinner('O')) {
            return "O won";
        }
        if (isFinished()) {
            return "Draw";
        }
        return "Game has not completed";
    }
}
