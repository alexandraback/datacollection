import java.io.*;
import java.util.*;

class C {

    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new Error();
            }
        }
    }

    static class ImpossibleException extends Exception {}

    Scanner in;
    PrintWriter out;

    char[][] transpose(char a[][]) {
        char b[][] = new char[a[0].length][a.length];
        for (int i = 0; i < a.length; i++) {
            Assert.check(a[i].length == b.length);
            for (int j = 0; j < b.length; j++) {
                b[j][i] = a[i][j];
            }
        }
        return b;
    }

    void fill(char a[][], char value) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                a[i][j] = value;
            }
        }
    }

    char[][] solveOne(int nLines, int nCols, int nMines) throws ImpossibleException {
        if (nLines > nCols) {
            return transpose(solveOne(nCols, nLines, nMines));
        }
        Assert.check(nLines <= nCols);
        char[][] answer = new char[nLines][nCols];
        if (nLines == 1) {
            fill(answer, '.');
            answer[0][0] = 'c';
            for (int j = nCols - nMines; j < nCols; j++) {
                answer[0][j] = '*';
            }
            return answer;
        }
        int nFree = nCols * nLines - nMines;
        if (nFree == 1) {
            fill(answer, '*');
            answer[0][0] = 'c';
            return answer;
        }
        if (nLines == 2) {
            fill(answer, '.');
            answer[0][0] = 'c';
            if (nMines % 2 != 0 || nFree == 2) {
                throw new ImpossibleException();
            }
            for (int i = 0; i < nLines; i++) {
                for (int j = nCols - nMines / 2; j < nCols; j++) {
                    answer[i][j] = '*';
                }
            }
            return answer;
        }
        Assert.check(nLines >= 3);
        if (nFree == 2 || nFree == 3 || nFree == 5 || nFree == 7) {
            throw new ImpossibleException();
        }
        if (nFree == 4) {
            fill(answer, '*');
            answer[0][0] = 'c';
            answer[0][1] = '.';
            answer[1][0] = '.';
            answer[1][1] = '.';
            return answer;
        }
        Assert.check(nFree == 6 || nFree >= 8);
        fill(answer, '.');
        answer[0][0] = 'c';
        int i = nLines - 1;
        int remMines = nMines;
        while (true) {
            if (remMines == 0) {
                return answer;
            }
            Assert.check(remMines > 0);
            if (i == 2) {
                break;
            }
            if (remMines >= nCols) {
                remMines -= nCols;
                Arrays.fill(answer[i], '*');
            } else if (remMines == nCols - 1) {
                remMines -= nCols - 2;
                Arrays.fill(answer[i], 2, nCols, '*');
            } else {
                Assert.check(remMines <= nCols - 2);
                Arrays.fill(answer[i], nCols - remMines, nCols, '*');
                remMines = 0;
            }
            i--;
        }
        Assert.check(i == 2);
        int j = nCols - 1;
        while (remMines >= 3) {
            answer[0][j] = '*';
            answer[1][j] = '*';
            answer[2][j] = '*';
            remMines -= 3;
            j--;
        }
        if (remMines == 0) {
            Assert.check(j >= 1);
            return answer;
        } else if (remMines == 1) {
            Assert.check(j >= 2);
            answer[2][j] = '*';
            return answer;
        } else {
            Assert.check(remMines == 2);
            Assert.check(j >= 3);
            answer[2][j] = '*';
            answer[2][j - 1] = '*';
            return answer;
        }
    }

    void println(char a[][]) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                out.print(a[i][j]);
            }
            out.println();
        }
    }

    void solve() {
        int nTests = in.nextInt();
        for (int i = 1; i <= nTests; i++) {
            out.printf("Case #%d:%n", i);
            try {
                println(solveOne(in.nextInt(), in.nextInt(), in.nextInt()));
            } catch (ImpossibleException e) {
                out.println("Impossible");
            }
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
        new C().run();
    }
}
