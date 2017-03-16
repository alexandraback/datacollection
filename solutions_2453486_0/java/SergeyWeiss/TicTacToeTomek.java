package gcj2013.qualification;
import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class TicTacToeTomek {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

    public TicTacToeTomek() throws IOException {
        reader = new BufferedReader(new FileReader("input.txt"));
        writer = new PrintWriter(new FileWriter("output.txt"));
    }

    int[] readInts() throws IOException {
        String[] strings = reader.readLine().split(" ");
        int[] ints = new int[strings.length];
        for(int i = 0; i < ints.length; i++) {
            ints[i] = Integer.parseInt(strings[i]);
        }
        return ints;
    }

    void solve(int test) throws IOException {
        writer.printf("Case #%d: ", test);
        String[] input = new String[5];
        for(int i = 0; i < 5; i++) input[i] = reader.readLine();
        final char[][] board = new char[4][];
        for(int i = 0; i < 4; i++) board[i] = input[i].toCharArray();

        class BoardChecker {
            boolean match(char a, char b) {
                return a == b || a == 'T' || b == 'T';
            }
            boolean checkSymbolWin(char a) {
                boolean d1 = true, d2 = true;
                for(int i = 0; i < 4; i++) {
                    boolean okRow = true;
                    boolean okColumn = true;
                    for(int j = 0; j < 4; j++) {
                        okRow = okRow && match(a, board[i][j]);
                        okColumn = okColumn && match(a, board[j][i]);
                    }
                    if(okRow || okColumn) return true;
                    d1 = d1 && match(a, board[i][i]);
                    d2 = d2 && match(a, board[i][3 - i]);
                }
                return d1 || d2;
            }
            void checkBoard() {
                String xo = "XO";
                for(char ch : xo.toCharArray()) {
                    if(checkSymbolWin(ch)) {
                        writer.printf("%c won\n", ch);
                        return;
                    }
                }
                for(char[] chs : board) {
                    for(char ch : chs) {
                        if(ch == '.') {
                            writer.println("Game has not completed");
                            return;
                        }
                    }
                }
                writer.println("Draw");
            }
        }
        new BoardChecker().checkBoard();
        writer.flush();
    }

    void multiSolve() throws IOException {
        int n = readInts()[0];
        for(int i = 0; i < n; i++) {
            solve(i + 1);
        }
    }

    public static void main(String[] args) throws IOException{
        new TicTacToeTomek().multiSolve();
    }
}
