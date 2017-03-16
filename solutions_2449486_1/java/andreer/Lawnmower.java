import java.util.Scanner;

public class Lawnmower {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int T = sc.nextInt();

        for (int i = 1; i <= T; i++) {
            int N = sc.nextInt(), M = sc.nextInt();
            int[][] lawn = new int[N][M];
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    lawn[j][k] = sc.nextInt();
                }
            }

            System.out.println("Case #" + i + ": " + (possible(lawn) ? "YES" : "NO"));
        }
    }

    private static boolean possible(int[][] lawn) {
        for (int y = 0; y < lawn.length; y++) {
            for (int x = 0; x < lawn[0].length; x++) {

                boolean b = true;

                // horizontal
                for (int i = 0; i < lawn[0].length; i++) {
                    if (lawn[y][i] > lawn[y][x])
                        b = false;
                }

                // vertical
                if (!b) {
                    for (int i = 0; i < lawn.length; i++) {
                        if (lawn[i][x] > lawn[y][x])
                            return false;
                    }
                }
            }
        }

        return true;
    }
}
