import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by IntelliJ IDEA.
 * User: skortzy
 * Date: 13.04.2013
 * Time: 11:11
 * To change this template use File | Settings | File Templates.
 */
public class CodeJam2 {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String line = br.readLine();
            int K = Integer.parseInt(line);
            for (int i = 1; i <= K; i++) {
                String[] size = br.readLine().split(" ");
                int M = Integer.parseInt(size[0]);
                int N = Integer.parseInt(size[1]);
                int[][] A = new int[M][N];
                for (int j = 0; j < M; j++) {
                    line = br.readLine();
                    String[] values = line.split(" ");
                    for (int k = 0; k < N; k++) {
                        A[j][k] = Integer.parseInt(values[k]);
                    }
                }
                solve(i, A, M, N);
            }
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static void solve(int k, int[][] A, int M, int N) {
        int[] maxLines = new int[M];
        int[] maxCols = new int[N];
        for (int i = 0; i < M; i++) {
            maxLines[i] = A[i][0];
        }
        for (int i = 0; i < N; i++) {
            maxCols[i] = A[0][i];
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] > maxLines[i]) {
                    maxLines[i] = A[i][j];
                }
                if (A[i][j] > maxCols[j]) {
                    maxCols[j] = A[i][j];
                }
            }
        }
        boolean result = check(A, maxLines, maxCols, M, N);
        System.out.println("Case #" + k + ": " + (result ? "YES" : "NO"));
    }

    private static boolean check(int[][] A, int[] maxLines, int[] maxCols, int M, int N) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (A[i][j] != maxLines[i] && A[i][j] != maxCols[j]) {
                    return false;
                }
            }
        }
        return true;
    }
}
