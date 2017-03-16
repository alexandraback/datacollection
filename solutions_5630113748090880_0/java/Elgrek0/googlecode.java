/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

/**
 *
 * @author Paris
 */
public class googlecode {

    public static void main(String args[]) throws FileNotFoundException, IOException {

        BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
        int T = Integer.parseInt(in.readLine());

        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(in.readLine());
            int listcount = 2 * N - 1;
            int[][] ints = new int[listcount][N];
            for (int k = 0; k < listcount; k++) {
                String[] nums = in.readLine().split(" ");
                for (int j = 0; j < N; j++) {
                    ints[k][j] = Integer.parseInt(nums[j]);

                }
            }
            int max = Integer.MIN_VALUE;
            for (int k = 0; k < listcount; k++) {
                for (int m = 0; m < N; m++) {
                    if (ints[k][m] > max) {
                        max = ints[k][m];

                    }
                }
            }
            int[] countsort = new int[max + 1];
            for (int k = 0; k < max + 1; k++) {
                countsort[k] = 0;
            }
            for (int k = 0; k < listcount; k++) {
                for (int m = 0; m < N; m++) {
                    countsort[ints[k][m]]++;
                }
            }
            int[] missing = new int[N];
            int pos = 0;
            for (int k = 0; k < max + 1; k++) {
                if (countsort[k] % 2 != 0) {
                    missing[pos++] = k;
                }
            }
            String s = "";

            Arrays.sort(missing);
            for (int j = 0; j < N; j++) {
                s=s+" "+missing[j];
            }
            out.append("Case #" + (i + 1) + ": "+s);
            out.append("\n");

        }
        out.close();

    }
}
