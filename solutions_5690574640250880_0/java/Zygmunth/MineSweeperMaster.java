import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.Writer;
import java.util.*;

public class MineSweeperMaster {
    private static class Se extends Exception {
    }

    private class Fe extends Exception {
    }

    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        InputStream resourceAsStream = MineSweeperMaster.class.getClassLoader().getResourceAsStream("in.txt");
        Scanner scanner = new Scanner(resourceAsStream);
        Writer out = new FileWriter("c:\\temp\\2014.txt");

        int tcc = scanner.nextInt();
        for (int ci = 0; ci < tcc; ci++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int m = scanner.nextInt();
            List<Integer> s1 = prepareStrategy(r, c);
            List<Integer> s2 = prepareStrategy(c, r);
            List<Integer> s3 = prepareStrategy2(c, r);
            List<Integer> s4 = prepareStrategy2(r, c);
            List<Integer> s5 = prepareStrategy3(r, c);
            List<Integer> s6 = prepareStrategy3(r, c);
            int req = r * c - m;
            String call = null;
            if (r == 1) {
                call = "c";
                for (int i = 1; i < c; i++) {
                    call += i < req ? "." : "*";
                }
                call += "\n";
            } else if (c == 1) {
                call = "c\n";
                for (int i = 1; i < r; i++) {
                    call += i < req ? ".\n" : "*\n";
                }
            } else if (s1.contains(req)) {
                call = printBoard(prepareBoard(r, c, req));
            } else if (s2.contains(req)) {
                call = printBoardT(prepareBoard(c, r, req));
            } else if (s3.contains(req)) {
                call = printBoard(prepareBoard2(r, c, req));
            } else if (s4.contains(req)) {
                call = printBoardT(prepareBoard2(c, r, req));
            } else if (s5.contains(req)) {
                call = printBoard(prepareBoard3(r, c, req));
            } else if (s6.contains(req)) {
                call = printBoardT(prepareBoard3(c, r, req));
            } else {
                call = "Impossible\n";
            }
            String res = String.format("Case #%d:\n%s", ci + 1, call);
            out.write(res);

        }
        out.close();
        return;
    }

    private static List<Integer> prepareStrategy(int r, int c) {
        List<Integer> s1 = new ArrayList<>();
        s1.add(1);
        s1.add(4);
        int last = 4;
        for (int i = 2; i < c; i++) {
            s1.add(last += 2);
        }
        for (int i = 2; i < r; i++) {
            s1.add(last += 2);
            for (int j = 2; j < c; j++) {
                s1.add(++last);
            }
        }
        return s1;
    }

    private static List<Integer> prepareStrategy3(int r, int c) {

        List<Integer> s1 = new ArrayList<>();
        if (r<3 || c<3) {
            return s1;
        }
        s1.add(1);
        s1.add(9);
        int last = 9;
        for (int i = 3; i < c; i++) {
            s1.add(last += 2);
        }
        for (int i = 3; i < c; i++) {
            s1.add(last += 1);
        }
        for (int i = 3; i < r; i++) {
            s1.add(last += 2);
            for (int j = 2; j < c; j++) {
                s1.add(++last);
            }
        }
        return s1;
    }

    private static List<Integer> prepareStrategy2(int r, int c) {
        List<Integer> s1 = new ArrayList<>();
        s1.add(1);
        s1.add(4);
        int last = 4;
        for (int i = 2; i < c; i++) {
            s1.add(last += 2);
        }
        for (int i = 2; i < r; i++) {
            s1.add(last += 2);
        }
        for (int i = 2; i < r; i++) {
            //s1.add(last += 2);
            for (int j = 2; j < c; j++) {
                s1.add(++last);
            }
        }
        return s1;
    }



    private static char[][] prepareBoard(int r, int c, int req) {
        char[][] board = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[i][j] = '*';
            }
        }
        List<Integer> s1 = new ArrayList<>();
        s1.add(1);
        board[0][0] = 'c';
        if (req == 1) {
            return board;
        }
        if (req < 4) {
            return null;
        }
        board[1][0] = '.';
        board[0][1] = '.';
        board[1][1] = '.';
        if (req == 4) {
            return board;
        }
        int last = 4;
        for (int i = 2; i < c; i++) {
            board[0][i] = '.';
            board[1][i] = '.';
            last += 2;
            if (req == last) {
                return board;
            }
        }
        for (int i = 2; i < r; i++) {
            board[i][0] = '.';
            board[i][1] = '.';
            last += 2;
            if (req == last) {
                return board;
            }
            for (int j = 2; j < c; j++) {
                board[i][j] = '.';
                last++;
                if (req == last) {
                    return board;
                }
            }
        }
        return null;
    }

    private static char[][] prepareBoard2(int r, int c, int req) {
        char[][] board = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[i][j] = '*';
            }
        }
        List<Integer> s1 = new ArrayList<>();
        s1.add(1);
        board[0][0] = 'c';
        if (req == 1) {
            return board;
        }
        if (req < 4) {
            return null;
        }
        board[1][0] = '.';
        board[0][1] = '.';
        board[1][1] = '.';
        if (req == 4) {
            return board;
        }
        int last = 4;
        for (int i = 2; i < c; i++) {
            board[0][i] = '.';
            board[1][i] = '.';
            last += 2;
            if (req == last) {
                return board;
            }
        }
        for (int i = 2; i < r; i++) {
            board[i][0] = '.';
            board[i][1] = '.';
            last += 2;
            if (req == last) {
                return board;
            }
        }
        for (int i = 2; i < r; i++) {
            for (int j = 2; j < c; j++) {
                board[i][j] = '.';
                last++;
                if (req == last) {
                    return board;
                }
            }
        }
        return null;
    }

    private static char[][] prepareBoard3(int r, int c, int req) {
        char[][] board = new char[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[i][j] = '*';
            }
        }
        List<Integer> s1 = new ArrayList<>();
        s1.add(1);
        board[0][0] = 'c';
        if (req == 1) {
            return board;
        }
        if (req < 9) {
            return null;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i==0 && j== 0) {
                    continue;
                }
                board[i][j] = '.';
            }
        }
        if (req == 9) {
            return board;
        }
        int last = 9;
        for (int i = 3; i < c; i++) {
            board[0][i] = '.';
            board[1][i] = '.';
            last += 2;
            if (req == last) {
                return board;
            }
        }
        for (int i = 3; i < c; i++) {
            board[2][i] = '.';
            last += 1;
            if (req == last) {
                return board;
            }
        }
        for (int i = 3; i < r; i++) {
            board[i][0] = '.';
            board[i][1] = '.';
            last += 2;
            if (req == last) {
                return board;
            }
            for (int j = 2; j < c; j++) {
                board[i][j] = '.';
                last++;
                if (req == last) {
                    return board;
                }
            }
        }
        return null;
    }

    private static String printBoard(char[][] board) {
        StringBuilder sb = new StringBuilder();
        int r = board.length;
        int c = board[0].length;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                sb.append(board[i][j]);
            }
            sb.append("\n");
        }
        return sb.toString();
    }

    private static String printBoardT(char[][] board) {
        StringBuilder sb = new StringBuilder();
        int r = board.length;
        int c = board[0].length;
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                sb.append(board[j][i]);
            }
            sb.append("\n");
        }
        return sb.toString();
    }
}
