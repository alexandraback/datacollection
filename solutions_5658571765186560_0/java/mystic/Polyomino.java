import java.util.*;
import java.io.*;
import java.math.*;

public class Polyomino {
    final static String PROBLEM_NAME = "polyomino";
    final static String WORK_DIR = "D:\\GCJ\\" + PROBLEM_NAME + "\\";

    static final long[][] FIGURE_CODES = new long[][] {
            {},
            {100l},
            {301l},
            {702l, 711l},
            {1511l, 2321l, 1521l, 1503l, 3012l},
            {3131l, 18622l, 7922l, 3112l, 6231l, 4721l, 12122l, 12222l, 9422l, 4731l, 3104l, 12422l},
            {6331l, 12322l, 12522l, 49832l, 75623l, 50032l, 11122l, 6312l, 73932l, 57432l, 12641l, 50432l, 28732l,
                    11131l, 9541l, 75632l, 6305l, 75432l, 15941l, 9531l, 31832l, 55932l, 18922l, 18722l, 15931l, 63632l, 49732l,
                    9522l, 12613l, 63623l, 25241l, 38032l, 6341l, 12313l, 12622l}
    };

    static final int MAXK = 10;

    class Figure {
        char[][] data;

        public Figure(char[][] data) {
            this.data = new char[data.length][];
            for (int i=0; i < data.length; i++) {
                this.data[i] = data[i].clone();
            }
        }

        public Figure(String[] data) {
            this.data = new char[data.length][];
            for (int i=0; i < data.length; i++) {
                this.data[i] = data[i].toCharArray();
            }
        }

        public Figure(Figure other) {
            this(other.data);
        }

        public Figure(long code) {
            int N = (int)(code % MAXK) + 1;
            code /= MAXK;

            int M = (int)(code % MAXK) + 1;
            code /= MAXK;

            this.data = new char[N][M];
            for (int i=0; i < N; i++) {
                for (int j=0; j < M; j++) {
                    int value = (int)(code % 2);
                    code /= 2;

                    data[i][j] = (value == 1 ? 'X' : '.');
                }
            }
        }

        public String[] toStringArray() {
            String[] res = new String[data.length];
            for (int i=0; i < data.length; i++) {
                res[i] = new String(data[i]);
            }
            return res;
        }

        public Figure denormalize(Random rnd) {
            Figure res = new Figure(this);

            int rotationCnt = rnd.nextInt(4);
            for (int i=0; i < rotationCnt; i++) {
                res = res.rotate();
            }

            if (rnd.nextBoolean()) {
                res = res.reflectV();
            }

            if (rnd.nextBoolean()) {
                res = res.reflectH();
            }

            return res;
        }

        public Figure rotate() {
            char[][] newData = new char[data[0].length][data.length];
            for (int i=0; i < data.length; i++) {
                for (int j=0; j < data[i].length; j++) {
                    newData[j][data.length - i - 1] = data[i][j];
                }
            }
            return new Figure(newData);
        }

        public Figure reflectV() {
            char[][] newData = new char[data.length][data[0].length];
            for (int i=0; i < data.length; i++) {
                for (int j=0; j < data[i].length; j++) {
                    newData[data.length - i - 1][j] = data[i][j];
                }
            }
            return new Figure(newData);
        }

        public Figure reflectH() {
            char[][] newData = new char[data.length][data[0].length];
            for (int i=0; i < data.length; i++) {
                for (int j=0; j < data[i].length; j++) {
                    newData[i][data[i].length - j - 1] = data[i][j];
                }
            }
            return new Figure(newData);
        }
    }

    void dfs(char[][] A, boolean[][] used, int r, int c) {
        if (r < 0 || r >= A.length || c < 0 || c >= A[r].length || used[r][c] || A[r][c] == 'X') {
            return;
        }
        used[r][c] = true;
        dfs(A, used, r+1, c);
        dfs(A, used, r-1, c);
        dfs(A, used, r, c+1);
        dfs(A, used, r, c-1);
    }

    boolean connected(char[][] A) {
        int compCnt = 0;
        int R = A.length, C = A[0].length;
        boolean[][] used = new boolean[R][C];
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (A[i][j] == '.' && !used[i][j]) {
                    compCnt++;
                    dfs(A, used, i, j);
                }
            }
        }
        return compCnt <= 1;
    }

    void solve(Scanner sc, PrintWriter pw) {
        int X = sc.nextInt();
        int R = sc.nextInt();
        int C = sc.nextInt();

        if ((R * C) % X != 0) {
            pw.println("RICHARD");
            return;
        }

        for (long code : FIGURE_CODES[X]) {
            Figure f = new Figure(code);

            boolean can = false;
            for (int i = 0; i < 2 && !can; i++, f = f.reflectH()) {
                for (int j = 0; j < 2 && !can; j++, f = f.reflectV()) {
                    for (int k = 0; k < 4 && !can; k++, f = f.rotate()) {
                        int r = f.data.length;
                        int c = f.data[0].length;
                        for (int a = 0; a + r <= R && !can; a++) {
                            for (int b = 0; b + c <= C && !can; b++) {
                                char[][] map = new char[R][C];
                                for (int t = 0; t < R; t++) {
                                    Arrays.fill(map[t], '.');
                                }
                                for (int A = a; A < a + r; A++) {
                                    for (int B = b; B < b + c; B++) {
                                        map[A][B] = f.data[A-a][B-b];
                                    }
                                }
                                if (connected(map)) {
                                    can = true;
                                }
                            }
                        }
                    }
                }
            }

            if (!can) {
                pw.println("RICHARD");
                return;
            }
        }

        pw.println("GABRIEL");
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new Polyomino().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
