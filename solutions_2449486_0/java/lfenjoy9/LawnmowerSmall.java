/**
 * Created with IntelliJ IDEA.
 * User: jsu
 * Date: 12/04/13
 * Time: 11:37 PM
 * To change this template use File | Settings | File Templates.
 */

/**
 * Google Code Jam
 * User: jsu
 */

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class LawnmowerSmall {
    private static boolean f(int[][] a, int n, int m) {
        int[] rowMax = new int[n];
        Arrays.fill(rowMax, 1);

        int[] colMax = new int[m];
        Arrays.fill(colMax, 1);

        for(int row = 0; row < n; ++row) {
            for(int col = 0; col < m; ++col) {
                if(a[row][col] == 2) {
                    rowMax[row] = 2;
                    colMax[col] = 2;
                }
            }
        }

        for(int row = 0; row < n; ++row) {
            for(int col = 0; col < m; ++col) {
                if(a[row][col] == 1) {
                    if(rowMax[row] == 2 && colMax[col] == 2)
                        return false;
                }
            }
        }

        return true;
    }

    private static void solve(String input, String output) throws Exception {
        BufferedReader in = new BufferedReader(new FileReader(input));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(output)));

        int t = Integer.parseInt(in.readLine());
        for (int i = 1; i <= t; ++i) {
            StringTokenizer st;
            st = new StringTokenizer(in.readLine());
            int rows = Integer.parseInt(st.nextToken());
            int cols = Integer.parseInt(st.nextToken());

            int[][] a = new int[rows][cols];

            for(int j = 0; j < rows; ++j) {
                st = new StringTokenizer(in.readLine());
                for(int k = 0; k < cols; ++k) {
                    a[j][k] = Integer.parseInt(st.nextToken());
                }
            }

            boolean r = f(a, rows, cols);

            out.print("Case #" + i + ": ");

            if (r) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }

        out.close();
    }

    public static void main(String[] args) throws Exception {
//        solve("test/B-sample.in", "test/B-sample.out");
//        solve("test/B-small-attempt0.in", "test/B-small-attempt0.out");
//        solve("test/B-small-attempt1.in", "test/B-small-attempt1.out");
//        solve("test/B-small-attempt2.in", "test/B-small-attempt2.out");
//        solve("test/B-small-attempt3.in", "test/B-small-attempt3.out");
//        solve("test/B-small-attempt4.in", "test/B-small-attempt4.out");
        solve("test/B-small-attempt5.in", "test/B-small-attempt5.out");

    }
}