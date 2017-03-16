import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class Enclosure {

    private void processInput() throws IOException {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int testCase = 1; testCase <= T; testCase++) {
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();

            long res = go(n, m, k);

            System.out.printf(Locale.ENGLISH, "Case #%d: %d\n", testCase, res);         
        }

        in.close();
    }

    private int go(int n, int m, int k) {

        int times = n * m;
        int res = 1000000000;
        this.n = n;
        this.m = m;
        
        board = new boolean[n+2][m+2];
        visited = new boolean[n+2][m+2];
        for (int mask = 1; mask < 1<<times; mask++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int val = i * m + j;
                    if (((1<<val) & mask) != 0) {
                        board[i+1][j+1] = true;
                    } else {
                        board[i+1][j+1] = false;
                    }
                }
                Arrays.fill(visited[i + 1], false);
            }
            Arrays.fill(visited[0], false);
            Arrays.fill(visited[n + 1], false);
            if (count() >= k) {
                res = Math.min(res, Integer.bitCount(mask));
            }
        }

        return res;
    }

    boolean[][] board;
    boolean[][] visited;
    int n;
    int m;
    private int count() {
        int res = 0;
        
        dfs(0, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!visited[i][j]) {
                    res++;
                }
            }
        }
        
        return res;
    }
    int[] drow = {-1, 0, 1, 0};
    int[] dcol = {0, 1, 0, -1};
    private void dfs(int row, int col) {
        
        visited[row][col] = true;
        for (int i = 0; i < drow.length; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n + 2 && ncol < m + 2 && !board[nrow][ncol] && !visited[nrow][ncol]) {
                dfs(nrow, ncol);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        Enclosure main = new Enclosure();
        main.processInput();
    }
}
