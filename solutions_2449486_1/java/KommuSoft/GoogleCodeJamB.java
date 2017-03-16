package googlecodejamb;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author kommusoft
 */
public class GoogleCodeJamB {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int c = 1; c <= t; c++) {
            solveInstance(sc, c);
        }
    }

    private static void solveInstance(Scanner sc, int c) {
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] grid = new int[m][n];
        int[] maxh = new int[m];
        int[] maxv = new int[n];
        int max, k;
        for (int i = 0; i < m; i++) {
            max = 0;
            for (int j = 0; j < n; j++) {
                k = sc.nextInt();
                grid[i][j] = k;
                max = Math.max(k, max);
                maxv[j] = Math.max(maxv[j], k);
            }
            maxh[i] = max;
        }
        if(check(n, m, grid, maxh, maxv)) {
            System.out.println(String.format("Case #%s: YES", c,m,n));
            //System.out.println(String.format("Case #%s: YES (%s,%s)", c,m,n));
        }
        else {
            System.out.println(String.format("Case #%s: NO", c,m,n));
            //System.out.println(String.format("Case #%s: NO (%s,%s)", c,m,n));
        }
        //System.out.println(Arrays.toString(maxh));
        //System.out.println(Arrays.toString(maxv));
    }

    public static boolean check(int n, int m, int[][] grid, int[] maxh, int[] maxv) {
        int k;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                k = grid[i][j];
                if(k < maxh[i] && k < maxv[j]) {
                    return false;
                }
            }
        }
        return true;
    }
}
