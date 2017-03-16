package codejam.y2013.q;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Prob2 {
    
    public static void main(String[] args) throws IOException {
//        Scanner scanner = new Scanner(new File("/Users/octavian/codejam/p2.in"));
//        FileWriter writer = new FileWriter(new File("/Users/octavian/codejam/p2.out"));
        Scanner scanner = new Scanner(new File("/Users/octavian/codejam/B-small-attempt1.in.txt"));
        FileWriter writer = new FileWriter(new File("/Users/octavian/codejam/B-small-attempt1.out.txt"));
        int[][] t = new int[100][100];
        int[] mini = new int[100];
        int[] maxi = new int[100];
//        int[] minj = new int[100];
        int[] maxj = new int[100];
        int cn = scanner.nextInt();
        for (int c = 0; c < cn; c++) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            for (int i = 0; i < 100; i++) {
//                mini[i] = minj[i] = 101;
                maxi[i] = maxj[i] = 0;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    t[i][j] = scanner.nextInt();
//                    mini[i] = Math.min(mini[i], t[i][j]);
//                    minj[j] = Math.min(minj[j], t[i][j]);
                    maxi[i] = Math.max(maxi[i], t[i][j]);
                    maxj[j] = Math.max(maxj[j], t[i][j]);
                }
            }
            boolean ok = true;
            
            for (int i = 0; i < n && ok; i++) {
                for (int j = 0; j < m && ok; j++) {
                    if (t[i][j] < maxi[i] && t[i][j] < maxj[j]) {
                       ok = false; 
                    }
                    
                    
//                    if ((t[i][j] < t[i][0] || t[i][j] < t[i][m-1]) &&
//                            (t[i][j] < t[0][j] || t[i][j] < t[n-1][j])) {
//                        ok = false;
//                    }
                }
            }
            
            writer.write("Case #" + (c+1) + ": " + (ok ? "YES" : "NO") + "\n");
        }
        writer.close();
        scanner.close();
    }
}
