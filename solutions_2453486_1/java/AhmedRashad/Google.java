
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class Google {

    public static void main(String[] args) throws Exception {

        BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("A-large.out"));

        int N = Integer.parseInt(in.readLine());
        char[][] board = new char[4][4];
        for (int i = 1; i <= N; i++) {
            board[0] = in.readLine().toCharArray();
            board[1] = in.readLine().toCharArray();
            board[2] = in.readLine().toCharArray();
            board[3] = in.readLine().toCharArray();
            String status = Solve(board);
            out.write("Case #" + i + ": " + status);
            out.newLine();

            in.readLine();
        }
        out.close();

    }

    private static String Solve(char[][] b) {
        int TotalDot = 0;
        for (int i = 0; i < 4; i++) {
            int rX = 0, rY = 0, rT = 0;
            int cX = 0, cY = 0, cT = 0;

            for (int j = 0; j < 4; j++) {
                //roww
                if (b[i][j] == 'X') {
                    rX++;
                } else if (b[i][j] == 'O') {
                    rY++;
                } else if (b[i][j] == 'T') {
                    rT++;
                }
                //column
                if (b[j][i] == 'X') {
                    cX++;
                } else if (b[j][i] == 'O') {
                    cY++;
                } else if (b[j][i] == 'T') {
                    cT++;
                }

                //Total
                if (b[i][j] == '.') {
                    TotalDot++;
                } 
            }
            if (rX + rT == 4 || cX + cT == 4) {
                return "X won";
            } else if (rY + rT == 4 || cY + cT == 4) {
                return "O won";
            }
        }
        int dX = 0, dY = 0, dT = 0;
        int d2X = 0, d2Y = 0, d2T = 0;
        for (int i = 0; i < b.length; i++) {
            if (b[i][i] == 'X') {
                dX++;
            } else if (b[i][i] == 'O') {
                dY++;
            } else if (b[i][i] == 'T') {
                dT++;
            }
            if (b[i][3 - i] == 'X') {
                d2X++;
            } else if (b[i][3 - i] == 'O') {
                d2Y++;
            } else if (b[i][3 - i] == 'T') {
                d2T++;
            }
        }
        if (dX + dT == 4 || d2X + d2T == 4) {
            return "X won";
        } else if (dY + dT == 4 || d2Y + d2T == 4) {
            return "O won";
        }

        if (TotalDot==0) {
            return "Draw";
        }

        return "Game has not completed";
    }
}
