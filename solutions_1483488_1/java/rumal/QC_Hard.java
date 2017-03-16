/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam2012;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;

/**
 *
 * @author Rumal
 */
public class QC_Hard {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        int R = 2000000;
        ArrayList<Integer> full = new ArrayList<Integer>();
        int[] head = new int[R + 1];
        for (int i = 1; i <= R; i++) {
            if (i < 10) {
                head[i] = full.size();
                continue;
            }
            String h = (i + "");
            int N = h.length();
            TreeSet<Integer> pos = new TreeSet<Integer>();
            for (int j = 1; j < N; j++) {
                int y = shift(i, j, N);
                pos.add(y);
            }
            head[i] = full.size();
            for (int y : pos) {
                if (y <= R && i < y) {
                    full.add(y);
                }
            }
        }
        int T = s.nextInt();
        for (int t = 1; t <= T; t++) {
            int A = s.nextInt();
            int B = s.nextInt();
            long count = 0;
            p:
            for (int i = head[A]; i < head[B]; i++) {
                if (full.get(i) <= B && full.get(i) >= A) {
                    count++;
                }
            }
            System.out.println("Case #" + t + ": " + count);
        }
    }
    
    private static int shift(int i, int j, int n) {
        String s = i + "";
        int N = s.length();
        if (n != N) {
            return -1;
        }
        int y = Integer.parseInt(s.substring(N - j) + s.substring(0, N - j));
        if ((y + "").length() != N) {
            return -1;
        }
        return y;
    }
}
