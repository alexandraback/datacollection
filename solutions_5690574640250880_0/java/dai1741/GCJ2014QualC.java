import java.util.Arrays;
import java.util.Scanner;


public class GCJ2014QualC {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d:%n%s", i, new GCJ2014QualC().solve(sc));
        }
    }

    int r, c;

    private String solve(Scanner sc) throws Exception {
        r = sc.nextInt();
        c = sc.nextInt();
        int m = sc.nextInt();

        boolean[][] board = new boolean[r][c];
        boolean[][] visited = new boolean[r][c];
        boolean[][] visitedOnce0 = new boolean[r][c];

        int comb = (1 << m) - 1;
        while (comb < 1 << r * c) {

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    board[i][j] = (comb & (1 << (i * c + j))) != 0;
                }
            }
            for (int i = 0; i < r; i++) {
                Arrays.fill(visitedOnce0[i], false);
            }
            for (int clickI = 0; clickI < r; clickI++) {
                for (int clickJ = 0; clickJ < c; clickJ++) {
                    if (board[clickI][clickJ] || visitedOnce0[clickI][clickJ]) continue;
                    for (int i = 0; i < r; i++) {
                        Arrays.fill(visited[i], false);
                    }
                    int reached = dfs(clickJ, clickI, board, visited, visitedOnce0);
                    if (reached + m == r * c) {
                        // ok possible
                        StringBuilder sb = new StringBuilder();
                        for (int i = 0; i < r; i++) {
                            for (int j = 0; j < c; j++) {
                                if (board[i][j]) sb.append('*');
                                else if (i == clickI && j == clickJ) sb.append('c');
                                else sb.append('.');
                            }
                            sb.append('\n');
                        }
                        return sb.toString();
                    }
                }
            }

            int x = comb & -comb;
            int y = comb + x;
            comb = ((comb & ~y) / x >> 1) | y;
        }
        return "Impossible\n";
    }

    static final int[] dx = { -1, 0, 1, 1, 1, 0, -1, -1 };
    static final int[] dy = { -1, -1, -1, 0, 1, 1, 1, 0 };

    private int dfs(int x, int y, boolean[][] board, boolean[][] visited,
            boolean[][] visitedOnce0) {

        visited[y][x] = true;
        int ret = 1;
        boolean is0 = true;
        for (int di = 0; di < 8; di++) {
            int nx = x + dx[di];
            int ny = y + dy[di];
            if (nx < 0 || c <= nx || ny < 0 || r <= ny) continue;
            if (board[ny][nx]) {
                is0 = false;
                break;
            }
        }
        if (!is0) return ret;
        visitedOnce0[y][x] = true;
        for (int di = 0; di < 8; di++) {
            int nx = x + dx[di];
            int ny = y + dy[di];
            if (nx < 0 || c <= nx || ny < 0 || r <= ny) continue;
            if (!visited[ny][nx]) {
                ret += dfs(nx, ny, board, visited, visitedOnce0);
            }
        }
        return ret;
    }
}
