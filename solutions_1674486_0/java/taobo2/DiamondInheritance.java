package the2012.round1c;

import java.io.*;
import java.util.Scanner;

public class DiamondInheritance {

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(new BufferedInputStream(new FileInputStream("/Users/taobo2/Downloads/A-small-attempt0 (1).in")));
        int T = scanner.nextInt();

        Writer out = new BufferedWriter(new FileWriter("A-small-attempt0round3sol.txt"));

        for (int i = 1; i <= T; ++i) {
            int len = scanner.nextInt();
            int[][] g = new int[len][len];
            for (int j = 0; j < len; ++j) {
                int ins = scanner.nextInt();
                for (int k = 0; k < ins; ++k) {
                    g[j][scanner.nextInt() - 1] = 1;
                }
            }

            out.write("Case #" + i + ": " + new DiamondInheritance().solve_(g, g.length));
            out.write("\n");
        }

        out.close();

    }

//    public String solve(int[][] g) {
//        int[][] solve = solve_(g, g.length);
//
//        for (int[] sa : solve)
//            for (int sae : sa)
//                if (sae > 1)
//                    return "Yes";
//
//        return "No";
//
//    }

    private String solve_(int[][] g, int l) {
        int[][] paths = new int[l][l];

        for (int i = 0; i < g.length; ++i)
            for (int j = 0; j < g[i].length; ++j)
                if (g[i][j] == 1)
                    paths[i][j] = 1;
//        int[][] half = solve_(g, l / 2);
//        int[][] ret = multiple(half, half);
//        if (l % 2 == 0) {
//            return ret;
//        } else
//            return multiple(ret, g);

        int[][] temp = g;
        for (int x = 0; x < l; ++x) {
            temp = multiple(temp, g);

            for (int i = 0; i < g.length; ++i)
                for (int j = 0; j < g[i].length; ++j) {
                    paths[i][j] += temp[i][j];
                    if (paths[i][j] > 1) {
                        return "Yes";
                    }
                }
        }

        return "No";
    }

    private int[][] multiple(int[][] a, int[][] b) {
        int len = a.length;
        int[][] ret = new int[len][len];
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < len; ++j) {
                int temp = 0;
                for (int k = 0; k < len; ++k)
                    temp += a[i][k] * b[k][j];

                ret[i][j] = temp;
            }

        return ret;

    }


}
