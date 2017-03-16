import java.util.Scanner;

public class CNaive {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            System.out.println("Case #" + t + ":");
            solve(in);
        }

    }

    public static void solve(Scanner in) {

        int R = in.nextInt();
        int C = in.nextInt();
        int M = in.nextInt();

        // If the answer is a single 'c'...
        if (R * C - M == 1) {
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    if (i == 0 && j == 0)
                        System.out.print('c');
                    else
                        System.out.print('*');
                }
                System.out.println();
            }
            return;
        }

        if (!backtrack(new boolean[R][C], 0, 0, M, R * C)) {
            System.out.println("Impossible");
        }

    }

    public static boolean backtrack(boolean[][] mine, int i, int j, int M,
            int spaces) {

        int n = mine.length;
        int m = mine[0].length;

        if (M == 0) {

            if (!valid(mine, spaces)) { return false; }

            boolean needC = true;

            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (mine[x][y]) {
                        System.out.print("*");
                        continue;
                    }

                    if (needC && numMines(mine, x, y) == 0) {
                        needC = false;
                        System.out.print('c');
                    }
                    else {
                        System.out.print(".");
                    }
                }
                System.out.println();
            }
            return true;
        }
        if (i == n) return false;

        int nextJ = (j + 1) % m;
        int nextI = nextJ == 0 ? i + 1 : i;

        mine[i][j] = true;
        if (backtrack(mine, nextI, nextJ, M - 1, spaces - 1)) return true;
        mine[i][j] = false;

        return backtrack(mine, nextI, nextJ, M, spaces);
    }

    public static boolean valid(boolean[][] mine, int howMany) {

        boolean[][] seen = new boolean[mine.length][mine[0].length];

        for (int i = 0; i < mine.length; i++) {
            for (int j = 0; j < mine[0].length; j++) {
                if (!mine[i][j] && numMines(mine, i, j) == 0)
                    return howMany == dfs(mine, seen, i, j);
            }
        }

        return false;
    }

    public static int numMines(boolean[][] mine, int i, int j) {
        int n = mine.length;
        int m = mine[0].length;

        int ans = 0;

        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (x == 0 && y == 0) continue;
                if (inBounds(i + x, y + j, n, m) && mine[i + x][j + y]) ans++;
            }
        }
        return ans;
    }

    public static int dfs(boolean[][] mine, boolean[][] seen, int i, int j) {

        int n = seen.length;
        int m = seen[0].length;

        if (!inBounds(i, j, n, m)) return 0;
        if (seen[i][j] || mine[i][j]) return 0;

        seen[i][j] = true;

        // If bomb adjacent, don't recurse
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (inBounds(i + x, j + y, n, m) && mine[i + x][j + y])
                    return 1;
            }
        }

        int res = 1;

        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                res += dfs(mine, seen, i + x, j + y);
            }
        }

        return res;
    }

    public static boolean inBounds(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) return false;
        return true;
    }

    public static void printTests() {
        System.out.println("225");
        for (int r = 1; r <= 5; r++) {
            for (int c = 1; c <= 5; c++) {
                for (int k = 0; k < r * c; k++) {
                    System.out.println(r + " " + c + " " + k);
                }
            }
        }

    }

}
