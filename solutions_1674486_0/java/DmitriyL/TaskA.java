import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class TaskA {
    private static int n;
    private static List<Integer>[] a;
    private static boolean[] used;
    private static boolean[][] hasPath;

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int tests = scanner.nextInt();
        for (int test = 1; test <= tests; test++) {
            n = scanner.nextInt();
            a = new List[n];

            for (int i = 0; i < n; i++) {
                int m = scanner.nextInt();
                a[i] = new ArrayList<Integer>(m);

                for (int j = 0; j < m; j++) {
                    a[i].add(scanner.nextInt() - 1);
                }
            }

            buildHasPath();

            boolean result = findDiamondInheritance();

            System.out.printf("Case #%d: %s", test, result ? "Yes" : "No");
            System.out.println();
        }

        scanner.close();
    }

    private static void buildHasPath() {
        hasPath = new boolean[n][n];
        used = new boolean[n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(used, false);
            dfs(i);
            System.arraycopy(used, 0, hasPath[i], 0, n);
        }
    }

    private static void dfs(int v) {
        used[v] = true;

        for (int next : a[v]) {
            if (!used[next]) {
                dfs(next);
            }
        }
    }

    private static boolean findDiamondInheritance() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || !hasPath[i][j]) {
                    continue;
                }

                int count = 0;
                for (int next : a[i]) {
                    if (hasPath[next][j]) {
                        count++;
                    }
                    if (count == 2) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}
