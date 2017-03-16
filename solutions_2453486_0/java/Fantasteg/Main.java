import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Dzmitry Paulenka
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task_A solver = new Task_A();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task_A {
    private static final int P = 0;
    private static final int X = 1;
    private static final int O = 2;
    private static final int T = 3;

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int b[][] = new int[4][4];
        for (int k = 1; k <= n; ++k) {
            boolean hasp = false;
            for (int r = 0; r < 4; ++r) {
                String row = in.next();
                for (int c = 0; c < 4; ++c) {
                    char ch = row.charAt(c);
                    if (ch == 'X') {
                        b[r][c] = X;
                    } else if (ch == 'O') {
                        b[r][c] = O;
                    } else if (ch == 'T') {
                        b[r][c] = T;
                    } else {
                        hasp = true;
                        b[r][c] = P;
                    }
                }
            }
            out.print("Case #" + k + ": ");
            if (wins(b, O)) {
                out.println("O won");
            } else if (wins(b, X)) {
                out.println("X won");
            } else if (!hasp) {
                out.println("Draw");
            } else {
                out.println("Game has not completed");
            }
//            in.next();
        }
    }

    private boolean wins(int[][] b, int t) {
        int d1 = 0;
        int d2 = 0;
        for (int i = 0; i < 4; ++i) {
            if (is(b, i, i, t)) ++d1;
            if (is(b, i, 3-i, t)) ++d2;

            int rc = 0;
            int cc = 0;
            for (int j = 0; j < 4; ++j) {
                if (is(b, i, j, t)) rc++;
                if (is(b, j, i, t)) cc++;
            }
            if (rc == 4 || cc == 4) {
                return true;
            }
        }
        return d1 == 4 || d2 == 4;
    }

    private boolean is(int[][] b, int r, int c, int t) {
        return b[r][c] == t || b[r][c] == T;
    }
}

