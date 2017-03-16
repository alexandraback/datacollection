/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 *
 * @author ndkoval
 */
public class CodeJam {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter("output.txt");

        int nTest = Integer.parseInt(br.readLine());
        for (int t = 1; t <= nTest; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            boolean b = true;
            int[][] a = new int[n][m];

            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < m; j++) {
                    a[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            int[][] map = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    map[i][j] = 100;
                }
            }

            for (int i = 0; i < n; i++) {
                int max = 0;
                for (int j = 0; j < m; j++) {
                    max = Math.max(max, a[i][j]);
                }
                for (int j = 0; j < m; j++) {
                    if (map[i][j] > max) {
                        map[i][j] = max;
                    }
                }
            }

            for (int j = 0; j < m; j++) {
                int max = 0;
                for (int i = 0; i < n; i++) {
                    max = Math.max(max, a[i][j]);
                }
                for (int i = 0; i < n; i++) {
                    if (map[i][j] > max) {
                        map[i][j] = max;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (map[i][j] != a[i][j]) {
                        b = false;
                        break;
                    }
                }
                if (!b) {
                    break;
                }
            }

            if (b) {
                pw.println("Case #" + t + ": YES");
            } else {
                pw.println("Case #" + t + ": NO");
            }
        }

        pw.close();
        br.close();
    }
}
