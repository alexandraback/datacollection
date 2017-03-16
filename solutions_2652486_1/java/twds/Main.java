import java.util.*;
import java.math.*;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author wd
 */
public class Main {
    
    static int R, N, M, K;
    static int[] g2, g3, g5, g7;
    static int[] res;
    
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
            R = scan.nextInt();
            N = scan.nextInt();
            M = scan.nextInt();
            K = scan.nextInt();
            System.out.println(String.format("Case #%d:", taskIndex));
            
            g2 = new int[K];
            g3 = new int[K];
            g5 = new int[K];
            g7 = new int[K];
            res = new int[N];
            for (int i = 0; i < R; i++) {
                int r5 = 0;
                int r7 = 0;
                int r3 = 0;
                for (int j = 0; j < K; j++) {
                    g2[j] = g3[j] = g5[j] = g7[j] = 0;
                    long temp = scan.nextLong();
                    while (temp % 2 == 0) {
                        temp /= 2;
                        g2[j]++;
                    }
                    while (temp % 3 == 0) {
                        temp /= 3;
                        g3[j]++;
                    }
                    while (temp % 5 == 0) {
                        temp /= 5;
                        g5[j]++;
                    }
                    while (temp % 7 == 0) {
                        temp /= 7;
                        g7[j]++;
                    }
                    r5 = Math.max(r5, g5[j]);
                    r7 = Math.max(r7, g7[j]);
                    r3 = Math.max(r3, Math.max(0, g3[j] - g2[j]));
                }
                
                int r6 = 0;
                for (int j = 0; j < K; j++) {
                    int left = Math.max(g3[j] - r3, 0);
                    int temp = Math.min(left, g2[j]);
                    r6 = Math.max(r6, temp);
                }
                
                int r2 = 0;
                int r4 = 0;
                int r8 = 0;
                for (int j = 0; j < K; j++) {
                    int common = Math.min(g2[j], g3[j]);
                    common = Math.min(common, r6);
                    g2[j] -= common;
                    r8 = Math.max(r8, g2[j] / 3);
                    if (g2[j] % 3 == 2) {
                        r4 = 1;
                    } else if (g2[j] % 3 == 1) {
                        r2 = 1;
                    }
                }
                int index = 0;
                //System.out.println(r2 + " " + r3 + " " + r4 + " " + r5 + " " + r6 + " " + r7 + " " + r8);
                for (int j = 0; j < r2 && index < N; j++) {
                    res[index++] = 2;
                }
                for (int j = 0; j < r3 && index < N; j++) {
                    res[index++] = 3;
                }
                for (int j = 0; j < r4 && index < N; j++) {
                    res[index++] = 4;
                }
                for (int j = 0; j < r5 && index < N; j++) {
                    res[index++] = 5;
                }
                for (int j = 0; j < r6 && index < N; j++) {
                    res[index++] = 6;
                }
                for (int j = 0; j < r7 && index < N; j++) {
                    res[index++] = 7;
                }
                for (int j = 0; j < r8 && index < N; j++) {
                    res[index++] = 8;
                }
                Random rand = new Random();
                while (index < N) {
                    res[index++] = rand.nextInt(M - 1) + 2;
                }
                for (int j = 0; j < N; j++) {
                    System.out.print(res[j]);
                }
                System.out.println();
            }
        }
    }
}
