import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * Created by jianghaiting on 15/4/8.
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        List<Integer> p = new ArrayList<>();
        for (int c = 1; c <= t; c++) {
            int n = sc.nextInt();
            p.clear();
            for (int i = 0; i < n; i++) {
                p.add(sc.nextInt());
            }
            System.out.printf("Case #%d: %d\n", c, solve(n, p));
        }
    }

    private static int solve(int n, List<Integer> p) {
        int max = Collections.max(p);
        int[][] f = new int[2][max];
        int r = 0;
        for (int i = 0; i < n; i++) {
            r = 1 - r;
            for (int j = 0; j < max; j++) {
                f[r][j] = f[1 - r][j] + (p.get(i) - 1) / (j + 1);
            }
        }
        int result = Integer.MAX_VALUE;
        for (int j = 0; j < max; j++) {
            result = Math.min(f[r][j] + j + 1, result);
        }
        return result;
    }
}
