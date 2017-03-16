import java.io.BufferedReader;
import java.io.FileReader;

public class Slides {

    public void go(String file) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(file));
        int T = Integer.parseInt(reader.readLine());
        for (int i = 1; i <= T; i++) {
            String[] parts = reader.readLine().split(" ");
            int B = Integer.parseInt(parts[0]);
            int M = Integer.parseInt(parts[1]);

            System.out.print("Case #" + i + ": ");
            if (Math.ceil(((float) B * (B - 1)) / 4) >= M) {
                System.out.println("POSSIBLE");
                print(B, M);
            } else {
                System.out.println("IMPOSSIBLE");
            }
        }
    }

    private void print(int B, int M) {
        int[][] matrix = new int[B][B];

        int paths = 0;
        for (int i = 0; i < B && paths < M; i++) {
            paths = dfs(matrix, i, B, M, 0);
        }

        for (int i = 0; i < B; i++) {
            for (int j = 0; j < B; j++) {
                System.out.print(matrix[i][j]);
            }
            System.out.println();
        }
    }

    private int dfs(int[][] matrix, int i, int B, int M, int paths) {
        if (i == M) {
            paths++;
        }
        for (int j = i + 1; j < B; j++) {
            if (paths <= M) {
                paths += dfs(matrix, j, B, M, paths);
                matrix[i][j] = 1;
            }
        }
        return paths;
    }

    public static void main(String[] args) throws Exception {
        new Slides().go(args[0]);
    }
}
