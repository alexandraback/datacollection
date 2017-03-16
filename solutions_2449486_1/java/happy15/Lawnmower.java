import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Lawnmower {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int numTests = Integer.parseInt(reader.readLine());
        for (int testId = 1; testId <= numTests; ++testId) {
            String[] tmp = reader.readLine().split(" ");
            int N = Integer.parseInt(tmp[0]);
            int M = Integer.parseInt(tmp[1]);
            int[][] targetHeight = new int[N][M];
            int[][] height = new int[N][M];
            boolean[][] cut = new boolean[N][M];
            for (int i = 0; i < N; ++i) {
                Arrays.fill(height[i], 100);
                Arrays.fill(cut[i], false);
                tmp = reader.readLine().split(" ");
                for (int j = 0; j < M; ++j) {
                    targetHeight[i][j] = Integer.parseInt(tmp[j]);
                }
            }

            int numDone = 0;
            while (true) {
                int minHeight = Integer.MAX_VALUE;
                int minI = -1, minJ = -1;
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < M; ++j) {
                        if (!cut[i][j] && targetHeight[i][j] < minHeight) {
                            minHeight = targetHeight[i][j];
                            minI = i;
                            minJ = j;
                        }
                    }
                }
                if (minHeight == Integer.MAX_VALUE) {
                    break;
                }

                cut[minI][minJ] = true;
                ++numDone;
                boolean possible1 = true;
                for (int i = 0; i < N; ++i) {
                    if (minHeight < targetHeight[i][minJ]) {
                        possible1 = false;
                        break;
                    }
                }
                if (possible1) {
                    for (int i = 0; i < N; ++i) {
                        if (minHeight == targetHeight[i][minJ] && !cut[i][minJ]) {
                            cut[i][minJ] = true;
                            ++numDone;
                        }
                    }
                    continue;
                }

                boolean possible2 = true;
                for (int j = 0; j < M; ++j) {
                    if (minHeight < targetHeight[minI][j]) {
                        possible2 = false;
                        break;
                    }
                }
                if (possible2) {
                    for (int j = 0; j < M; ++j) {
                        if (minHeight == targetHeight[minI][j] && !cut[minI][j]) {
                            cut[minI][j] = true;
                            ++numDone;
                        }

                    }
                    continue;
                }
                if (!possible1 && !possible2) {
                    break;
                }

            }

            System.out.println("Case #" + testId + ": " + (numDone == N * M ? "YES" : "NO"));
        }
    }
}
