import java.io.*;
import java.util.Locale;
import java.util.Scanner;

//Problem A. Tic-Tac-Toe-Tomek
public class Main {

    // system
    public static String charset = "UTF-8";
    public static Locale locale = new Locale("en", "US");
    public static PrintWriter stdOut, fileOut;
    public static Scanner stdIn, fileIn;

    // task
    public static char[][] board;

    public static void main(String[] args) {
        setIO("A-small-attempt0.in", "output.out");
        Scanner input = fileIn;
        PrintWriter output = fileOut;

        board = new char[4][4];

        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            for (int j = 0; j < 4; j++) {
                String s = input.next();
                for (int k = 0; k < 4; k++) {
                    board[j][k] = s.charAt(k);
                }
            }
            input.nextLine();
            String resStr = "Case #" + i + ": " + solve();
            output.println(resStr);
            stdOut.println(resStr);
        }

        input.close();
        output.close();
    }

    // task
    public static String solve() {
        int x, o, empty;
        boolean isWin = false;
        x = o = empty = 0;

        // horizontally
        for (int i = 0; i < 4; i++) {
            x = o = 0;
            for (int j = 0; j < 4; j++) {
                char c = board[i][j];
                if      (c == 'X') x++;
                else if (c == 'O') o++;
                else if (c == 'T') {x++; o++;}
                else               empty++;
            }
            if (x == 4 || o == 4) {
                isWin = true;
                break;
            }
        }

        if (!isWin) {
            // vertically
            for (int i = 0; i < 4; i++) {
                x = o = 0;
                for (int j = 0; j < 4; j++) {
                    char c = board[j][i];
                    if      (c == 'X') x++;
                    else if (c == 'O') o++;
                    else if (c == 'T') {x++; o++;}
                    else               empty++;
                }
                if (x == 4 || o == 4) {
                    isWin = true;
                    break;
                }
            }
        }

        if (!isWin) {
            // diag 1
            x = o = 0;
            for (int i = 0; i < 4; i++) {
                char c = board[i][i];
                if      (c == 'X') x++;
                else if (c == 'O') o++;
                else if (c == 'T') {x++; o++;}
                else               empty++;
            }
            if (x == 4 || o == 4) {
                isWin = true;
            } else {
                // diag 2
                x = o = 0;
                for (int i = 0; i < 4; i++) {
                    char c = board[4-i-1][i];
                    if      (c == 'X') x++;
                    else if (c == 'O') o++;
                    else if (c == 'T') {x++; o++;}
                    else               empty++;
                }
                if (x == 4 || o == 4) {
                    isWin = true;
                }
            }
        }

        if (isWin) {
            if (x == 4) return "X won";
            else        return "O won";
        } else {
            if (empty == 0) return "Draw";
            else            return "Game has not completed";
        }
    }

    // system
    public static void setIO(String fileInName, String fileOutName) {
        // Standard input
        stdIn = new Scanner(new BufferedInputStream(System.in), charset);
        stdIn.useLocale(locale);

        // Standard output
        try {
            stdOut = new PrintWriter(new OutputStreamWriter(System.out, charset), true);
        }
        catch (UnsupportedEncodingException e) {
            System.err.println(e);
        }

        // File input
        if (fileInName != null) {
            try {
                File file = new File(fileInName);
                if (file.exists()) {
                    fileIn = new Scanner(file, charset);
                    fileIn.useLocale(locale);
                 }
            }
            catch (IOException ioe) {
                System.err.println("Could not open " + fileInName);
            }
        }

        // File output
        if (fileOutName != null) {
            try {
                OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream(fileOutName), charset);
                fileOut = new PrintWriter(osw, true);
            }
            catch (IOException e) {
                System.err.println(e);
            }
        }
    }
}
