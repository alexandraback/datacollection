// @gilesgardam
import java.util.*;
import static java.lang.Math.*;

public class ProblemB {

    void run() {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            int[][] grid = new int[N][M];
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    grid[i][j] = sc.nextInt();
                }
            }
            System.out.printf("Case #%d: %s\n", caseNum, solve(grid));
        }
    }

    String solve(int[][] grid) {
        int N = grid.length;
        int M = grid[0].length;
        int[] rows = new int[N];
        int[] cols = new int[M];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                rows[i] = max(rows[i], grid[i][j]);
                cols[j] = max(cols[j], grid[i][j]);
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] != min(rows[i], cols[j])) {
                    return "NO";
                }
            }
        }
        return "YES";
    }

    boolean debug = false;
    void p(String f, Object...params) {
        System.out.printf(f, params);
    }
    void d(Object...params) {
        if (debug) {
            p("DEBUG: %s\n", Arrays.deepToString(params));
        }
    }
    void die() {
        throw new RuntimeException();
    }
    public ProblemB(String[] args) {
        if (args.length > 0 && args[0].equals("debug")) {
            debug = true;
        }
    }
    public static void main(String[] args) {
        new ProblemB(args).run();
    }
}
