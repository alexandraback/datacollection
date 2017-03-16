package com.google.codejam;

import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;

/**
 * User: svasilinets
 * Date: 14.04.12
 * Time: 11:58
 */
public class QualC {


    private static int getDigitCount(int k) {
        int r = 0;
        while (k != 0) {
            k /= 10;
            r++;
        }

        return r;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("c.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("c.out"));
        int tests = Integer.parseInt(reader.readLine());
        for (int t = 1; t <= tests; t++) {
            StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
            int a = Integer.parseInt(tokenizer.nextToken());
            int b = Integer.parseInt(tokenizer.nextToken());
            int d = getDigitCount(a);
            int result = 0;
            int tp = 1;
            for (int i = 0; i < d; i++) {
                tp *= 10;
            }
            for (int i = a; i <= b; i++) {
                HashSet<Integer> h = new HashSet<Integer>();
                int p = 1;
                for (int j = 0; j < d - 1; j++) {
                    p *= 10;
                    int rest = i % p;
                    int del = i / p;
                    int pretend = rest * (tp / p) + del;
                    if (pretend > i && pretend <= b && !h.contains(pretend)){
                        result++;
                        h.add(pretend);
                    }
                }
            }
            writer.write("Case #" + t + ": " + result);
            writer.newLine();
        }
        writer.close();
    }
}
