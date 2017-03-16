import java.util.*;

public class taskA {

    public static void main(String[] args) {
        new taskA().main();
    }

    boolean doTest() {
        int n = s.nextInt();
        int[][] matrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            int m = s.nextInt();
            for (int j = 0; j < m; j++) {
                int k = s.nextInt();
                matrix[i][k-1] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (dfs(i, matrix, new boolean[n])) {
                return true;
            }
        }
        return false;
    }

    boolean dfs(int v, int[][] m, boolean[] used) {
        if (used[v]) {
            return true;
        }
        used[v] = true;
        for (int i = 0; i < m[v].length; i++) {
            if (m[v][i]==1 && dfs(i, m, used)) {
                return true;
            }
        }
        return false;
    }

    Scanner s = new Scanner(System.in);

    void main() {
        int T = s.nextInt();
        for (int i = 0; i < T; i++) {
            boolean f = doTest();
            System.out.println("Case #"+(i+1)+": "+(f?"Yes":"No"));
        }
    }
}
