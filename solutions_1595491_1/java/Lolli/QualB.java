package com.google.codejam;

import java.io.*;
import java.util.StringTokenizer;

/**
 * User: svasilinets
 * Date: 14.04.12
 * Time: 11:11
 */
public class QualB {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("b.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("b.out"));
        int tests = Integer.parseInt(reader.readLine());
        for (int i = 1; i <= tests; i++) {
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
            int n = Integer.parseInt(tokenizer.nextToken());
            int s = Integer.parseInt(tokenizer.nextToken());
            int p = Integer.parseInt(tokenizer.nextToken());
            int result = 0;
            int enough = 3 * p - 2;
            int surpriselyEnough = 3 * p - 4;
            for (int j = 0; j < n; j++){
                int k = Integer.parseInt(tokenizer.nextToken());
                if (k >= enough){
                    result++;
                    continue;
                }
                if (k > 1 && k >= surpriselyEnough && s > 0){
                    s--;
                    result++;
                    continue;
                }

            }

            writer.write("Case #" + i + ": " + result);
            writer.newLine();
        }
        writer.close();

    }
}
