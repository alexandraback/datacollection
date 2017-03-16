package Gcj2013_0;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Gcj2013_0_b {
    final static String WORK_DIR = "C:\\eclipse\\workspace\\GoogleCodeJam\\IO\\2013_0\\";

    void solve(Scanner sc, PrintWriter pw) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        
        int[][] lawn = new int[N][M];
        boolean[][] risk = new boolean[N][M];
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                lawn[i][j] = sc.nextInt();
                risk[i][j] = false;
            }
        }
        
        int max;
        
        // check each row for risk
        for (int i = 0; i < N; i++) {
            max = 0;
            for (int j = 0; j < M; j++) {
                max = Math.max(max, lawn[i][j]);
            }
            for (int j = 0; j < M; j++) {
                if (lawn[i][j] < max) {
                    risk[i][j] = true;
                }
            }
        }
        
        // check each col for risk
        for (int i = 0; i < M; i++) {
            max = 0;
            for (int j = 0; j < N; j++) {
                max = Math.max(max, lawn[j][i]);
            }
            for (int j = 0; j < N; j++) {
                if (lawn[j][i] < max) {
                    if (risk[j][i]) {
                        pw.println("NO");
                        return;
                    }
                }
            }
        }
        
        pw.println("YES");
        return;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "B-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "B-small-attempt0.out"));
        int T = sc.nextInt();
        for (int t=0; t<T; t++) {
            System.out.println("Processing test case " + (t + 1) + " of " + T);
            pw.print("Case #" + (t+1) + ": ");
            new Gcj2013_0_b().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
