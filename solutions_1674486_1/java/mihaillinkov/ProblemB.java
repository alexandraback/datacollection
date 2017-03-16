import java.util.Scanner;

/**
 * @Author Mikhail Linkov
 * Date: 06.05.12
 */
public class ProblemB {
    private static int [] b;
    private static int [][] a;
    private static int n;
    private static boolean answer;

    private static void dfs(int v) {
        b[v] = 1;

        for (int i = 0; i < n; i++) {
            if (a[v][i] == 1) {
                if (b[i] == 1) {
                    answer = true;
                } else {
                    dfs(i);
                }
            }
        }
    }
    public static void main(String [] args) {


        Scanner scanner = new Scanner(System.in);

        int testCount = scanner.nextInt();

        for (int testNum = 1; testNum < testCount + 1; testNum++) {
            n = scanner.nextInt();
            a = new int[n][n];
            for (int i = 0; i < n; i++) {

                int m = scanner.nextInt();

                for (int j = 0; j < m; j++) {
                    int value = scanner.nextInt() - 1;
                    a[i][value] = 1;
                }
            }

            b = new int[n];
            answer = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    b[j] = 0;
                }
                dfs(i);
                if (answer) {
                    break;
                }
            }
            if (answer) {
                System.out.println("Case #" + testNum + ": Yes");
            } else {
                System.out.println("Case #" + testNum + ": No");
            }


        }
    }
}
