package topcoder;

import java.io.PrintWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int T = sc.nextInt();
        for (int t = 1; t <= T; ++t) {
            String ret = "";
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] field = new int[n][m];
            Set<Integer> s = new TreeSet<Integer>();
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    field[i][j] = sc.nextInt();
                    if (!s.contains(field[i][j])) {
                        s.add(field[i][j]);
                    }
                }
            }
            boolean[][] blocked = new boolean[n][m];
            int[][] temp = new int[n][m];
            int max = (Integer) s.toArray()[s.toArray().length - 1];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    temp[i][j] = max;
                    if (field[i][j] == max) {
                        blocked[i][j] = true;
                    }
                }
            }
            Integer[] val;
            val = s.toArray(new Integer[0]);
            for (int i = val.length - 2; i >= 0; --i) {
                boolean[][] tempBlocked = new boolean[n][m];
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < m; ++k) {
                        tempBlocked[j][k] = blocked[j][k];
                    }
                }
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < m; ++k) {
                        if (field[j][k] == val[i]) {
                            boolean fail = true;
                            // check row j
                            int l;
                            for (l = 0; l < m && !blocked[j][l]; ++l);
                            if (l == m) {
                                fail = false;
                            }
                            // check column k
                            for (l = 0; l < n && !blocked[l][k]; ++l);
                            if (l == n) {
                                fail = false;
                            }
                            if (fail) {
                                ret = "NO";
                            } else {
                                tempBlocked[j][k] = true;
                            }
                        }
                    }
                }
            }
            if (!"NO".equalsIgnoreCase(ret)) {
                ret = "YES";
            }
            out.println("Case #" + t + ": " + ret);
            out.flush();
        }
        out.close();
    }
}
