import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemB {

    public static void main(String[] args) throws Exception {
        //Scanner scanner = new Scanner(System.in);
        Scanner scanner = new Scanner(new File("/home/cata/Downloads/B-large.in"));
        PrintStream out = new PrintStream("output.txt");
        int T = scanner.nextInt();
        for (int test = 1; test <= T; test++) {
            ProblemB instance = new ProblemB();
            instance.read(scanner);
            boolean possible = instance.isPossible();
            String message = possible ? "YES" : "NO";
            out.println("Case #" + test + ": " + message);
            System.out.println("Case #" + test + ": " + message);
        }
    }

    int n, m;

    int[][] a;

    private void read(Scanner scanner) {
        n = scanner.nextInt();
        m = scanner.nextInt();
        a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = scanner.nextInt();
            }
        }
    }

    private boolean isPossible() {
        int[] max = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (max[i] < a[i][j]) {
                    max[i] = a[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] < max[i]) {
                    for (int k = 0; k < n; k++) {
                        if (a[i][j] < a[k][j]) {
                            return false;
                        }
                    }
                }
            }
        }

        max = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (max[j] < a[i][j]) {
                    max[j] = a[i][j];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] < max[j]) {
                    for (int k = 0; k < m; k++) {
                        if (a[i][j] < a[i][k]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

}
