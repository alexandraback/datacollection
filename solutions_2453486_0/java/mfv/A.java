import java.io.*;
import java.util.*;

public class A {

    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new Error();
            }
        }
    }

    Scanner in;
    PrintWriter out;

    boolean wins(char winner, char c[][], int iBegin, int jBegin, int di, int dj) {
        int i = iBegin;
        int j = jBegin;
        for (int cnt = 0; cnt < 4; cnt++) {
            if (c[i][j] != winner && c[i][j] != 'T') {
                return false;
            }
            i += di;
            j += dj;
        }
        return true;
    }

    boolean wins(char winner, char c[][]) {
        for (int i = 0; i < 4; i++) {
            if (wins(winner, c, i, 0, 0, 1)) {
                return true;
            }
        }
        for (int j = 0; j < 4; j++) {
            if (wins(winner, c, 0, j, 1, 0)) {
                return true;
            }
        }
        if (wins(winner, c, 0, 0, 1, 1)) {
            return true;
        }
        if (wins(winner, c, 3, 0, -1, 1)) {
            return true;
        }
        return false;
    }

    void solve() {
        int nCases = in.nextInt();
        for (int iCase = 1; iCase <= nCases; iCase++) {
            char c[][] = new char[4][];
            int xCount = 0;
            int oCount = 0;
            int tCount = 0;
            for (int i = 0; i < 4; i++) {
                c[i] = in.next().toCharArray();
                Assert.check(c[i].length == 4);
                for (int j = 0; j < 4; j++) {
                    if (c[i][j] == 'X') {
                        xCount++;
                    } else if (c[i][j] == 'O') {
                        oCount++;
                    } else if (c[i][j] == 'T') {
                        tCount++;
                    } else {
                        Assert.check(c[i][j] == '.');
                    }
                }
            }
            Assert.check(tCount == 0 || tCount == 1);
            boolean xWins = wins('X', c);
            boolean oWins = wins('O', c);
            String message;
            if (xWins) {
                Assert.check(!oWins);
                Assert.check(xCount == oCount + 1);
                message = "X won";
            } else if (oWins) {
                Assert.check(!xWins);
                Assert.check(oCount == xCount);
                message = "O won";
            } else if (xCount + oCount + tCount == 16) {
                Assert.check(xCount == oCount || xCount == oCount + 1);
                message = "Draw";
            } else {
                Assert.check(xCount == oCount || xCount == oCount + 1);
                message = "Game has not completed";
            }
            out.println("Case #" + iCase + ": " + message);
        }
    }

    void run() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);
        try {
            solve();
        } finally {
            out.close();
        }
    }

    public static void main(String args[]) {
        new A().run();
    }
}
