package codejam;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class B {

    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 1; t <= T; t++) {
            System.out.print("Case #" + t + ": ");
            String solution = new B().solve(scanner);
        }
    }

    int B, M, N, P;



    private String solve(Scanner scanner) {
        B = scanner.nextInt();
        M = scanner.nextInt();

        N = (B * (B - 1)) / 2;
        P = 1 << (B - 2);

        for (int i = 0; i < (1 << N); i++) {
            int[][] matrix = matrix(i);
            int pathCount = 0;
            path:
            for (int p = 0; p < P; p++) {
                List<Integer> path = path(p);
                int from = 0;
                int to;
                for (Integer b : path) {
                    to = b;
                    if (matrix[from][to] == 0) break path;
                    from = to;
                }
                to = B - 1;
                if (matrix[from][to] == 0) break path;
                pathCount++;
            }
            //printMatrix(matrix);
            if (pathCount == M) return printMatrix(matrix);
        }

        System.out.println("IMPOSSIBLE");
        return null;
    }

    private String printMatrix(int[][] matrix) {
        System.out.println("POSSIBLE");
        for (int x = 0; x < B; x++) {
            for (int y = 0; y < B; y++) {
                System.out.print(matrix[x][y]);
            }
            System.out.println("");
        }
        return null;
    }

    private int[][] matrix(int m) {
        int[][] matrix = new int[B][B];
        int i = N - 1;
        for (int x = 0; x < B; x++) {
            for (int y = x + 1; y < B; y++) {
                matrix[x][y] = ((m & (1 << i--)) == 0) ? 0 : 1;
            }
        }
        return matrix;
    }

    private List<Integer> path(int p) {
        List<Integer> path = new ArrayList<>();
        for (int i = 0; i < B - 2; i++) {
            if ((p & (1 << i)) > 0)
                path.add(i + 1);
        }
        return path;
    }

}
