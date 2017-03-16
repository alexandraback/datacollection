import java.io.PrintWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int T = sc.nextInt();
        for (int i = 1; i <= T; ++i) {
            sc.nextLine();
            char[][] field = new char[4][4];
            for (int j = 0; j < 4; ++j) {
                char[] toCharArray = sc.nextLine().toCharArray();
                for (int k = 0; k < 4; ++k) {
                    field[j][k] = toCharArray[k];
                }
            }
            String ret = "";
            int countEmpty = 0;
            // test rows
            for (int j = 0; j < 4; ++j) {
                int countX = 0;
                int countO = 0;
                int countT = 0;
                for (int k = 0; k < 4; ++k) {
                    switch (field[k][j]) {
                        case 'X': {
                            ++countX;
                            break;
                        }
                        case 'O': {
                            ++countO;
                            break;
                        }
                        case 'T': {
                            ++countT;
                            break;
                        }
                        case '.': {
                            ++countEmpty;
                            break;
                        }
                    }
                }
                ret = solveWon(countX, countT, ret, countO);
            }
            //test columns
            for (int j = 0; j < 4; ++j) {
                int countX = 0;
                int countO = 0;
                int countT = 0;
                for (int k = 0; k < 4; ++k) {
                    switch (field[j][k]) {
                        case 'X': {
                            ++countX;
                            break;
                        }
                        case 'O': {
                            ++countO;
                            break;
                        }
                        case 'T': {
                            ++countT;
                            break;
                        }
                        case '.': {
                            ++countEmpty;
                            break;
                        }
                    }
                }
                ret = solveWon(countX, countT, ret, countO);
            }

            // test diagonals
            int countX = 0;
            int countO = 0;
            int countT = 0;
            for (int j = 0; j < 4; ++j) {

                switch (field[j][j]) {
                    case 'X': {
                        ++countX;
                        break;
                    }
                    case 'O': {
                        ++countO;
                        break;
                    }
                    case 'T': {
                        ++countT;
                        break;
                    }
                    case '.': {
                        ++countEmpty;
                        break;
                    }
                }
            }
            ret = solveWon(countX, countT, ret, countO);
            countX = 0;
            countO = 0;
            countT = 0;
            for (int j = 0; j < 4; ++j) {
                switch (field[3 - j][j]) {
                    case 'X': {
                        ++countX;
                        break;
                    }
                    case 'O': {
                        ++countO;
                        break;
                    }
                    case 'T': {
                        ++countT;
                        break;
                    }
                    case '.': {
                        ++countEmpty;
                        break;
                    }
                }
            }
            ret = solveWon(countX, countT, ret, countO);
            if (ret.equalsIgnoreCase("")) {
                if (countEmpty == 0) {
                    ret = "Draw";
                } else {
                    ret = "Game has not completed";
                }
            }
            out.println("Case #" + i + ": " + ret);
            out.flush();
        }
        out.close();
    }

    private static String solveWon(int countX, int countT, String ret, int countO) {
        if (countX + countT == 4) {
            ret = "X won";
        } else if (countO + countT == 4) {
            ret = "O won";
        }
        return ret;
    }
}
