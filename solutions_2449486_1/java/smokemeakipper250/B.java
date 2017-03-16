//package Qualification;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import java.io.File;
import java.util.*;
import java.math.*;
import java.util.regex.*;

/**
 *
 * @author Jurek
 */
public class B {

    public static void main(String[] args) {
        long start = System.currentTimeMillis();

        // =====================================================================
        // Operation
        // =====================================================================       

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int kase = 1; kase <= T; kase++) {
            int n = in.nextInt();
            int m = in.nextInt();

            int[][] grid = new int[n][m];
            boolean[][] check = new boolean[n][m];
            int[] maxN = new int[n];
            Arrays.fill(maxN, -1);
            int[] maxM = new int[m];
            Arrays.fill(maxM, -1);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = in.nextInt();
                    maxN[i] = Math.max(maxN[i], grid[i][j]);
                    maxM[j] = Math.max(maxM[j], grid[i][j]);
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == maxN[i] || grid[i][j] == maxM[j]) {
                        check[i][j] = true;
                    }
                }
            }

            boolean works = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!check[i][j]) {
                        works = false;
                        break;
                    }
                }
            }

            //for (int i = 0; i < n; i++) {
            //    pl(Arrays.toString(grid[i]));
            //}
            
            pr("Case #" + kase + ": ");
            if(works) {
                pl("YES");
            } else {
                pl("NO");
            }
        }

        // =====================================================================
        // Output
        // =====================================================================
        long end = System.currentTimeMillis();

        //pl("============" + (end - start) + " ms");
        //pl("");
    }

    public static void pf(String s, Object... o) {
        System.out.printf(s, o);
    }

    public static void pl() {
        System.out.println("");
    }

    public static void pl(ArrayList<Object> i) {
        System.out.println(Arrays.toString(i.toArray()));
    }

    public static void pl(Object o) {
        System.out.println(o);
    }

    public static void pr(Object o) {
        System.out.print(o);
    }
}
