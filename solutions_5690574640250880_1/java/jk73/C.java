import java.io.BufferedReader;
import java.nio.file.Files;
import java.nio.file.Paths;

public class C {

    public static void main(String[] args) throws Throwable {
        try (BufferedReader reader = Files.newBufferedReader(Paths
                .get("/Users/jk/C.in"))) {
            int numCases = Integer.parseInt(reader.readLine());

            for (int c = 1; c <= numCases; c++) {
                String[] split = reader.readLine().split(" ");
                solve(c, Integer.parseInt(split[0]),
                         Integer.parseInt(split[1]),
                         Integer.parseInt(split[2]));
            }
        }
    }

    private static void solve(int caseNum, int R, int C, int M) {
        System.out.format("Case #%d:%n", caseNum);
        byte[][] fields = new byte[R][C];
        if (R * C <= M) {
            System.out.println("Impossible");
            return;
        }
        fillBoard(fields, R, C, M);
        // System.out.format("Case #%d: %.7f%n", caseNum, timeToX);

    }

    private static void fillBoard(byte[][] fields, int R, int C, int M) {
        int m = 0;
        int r = R;
        int c = C;

        boolean solvable = true;
        while (m < M && r >= 0 && c >= 0) {
            if (r >= c) {
                int i = c;
                while (--i >= 0 && m < M) {
                    fields[r - 1][i] = -1;
                    m++;
                }
                if (m == M && i == 0) {
                    if (c <= 0 || C == 2) {
                        solvable = false;
                    } else {
                        fields[r - 1][i + 1] = 0;
                        fields[r - 2][c - 1] = -1;
                        solvable = r != 3;
                    }
                }
                r--;
            } else {
                int i = r;
                while (--i >= 0 && m < M) {
                    fields[i][c - 1] = -1;
                    m++;
                }
                if (m == M && i == 0) {
                    if (r <= 0 || R == 2) {
                        solvable = false;
                    } else {
                        fields[i + 1][c - 1] = 0;
                        fields[r - 1][c - 2] = -1;
                        solvable = c != 3;
                    }
                }
                c--;
            }
        }
        if (R * C - 1 != M &&
            (!solvable ||
             R > 1 && (fields[1][0] == -1 || C > 1 && fields[1][1] == -1) ||
             C > 1 && fields[0][1] == -1)) {
            System.out.println("Impossible");
            //printBoard(fields, R, C);
            return;
        }
        printBoard(fields, R, C);
    }

    private static void printBoard(byte[][] fields, int r, int c) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print(i == 0 && j == 0 ? "c" : fields[i][j] == -1 ? "*" : ".");
            }
            System.out.println();
        }
    }
}
