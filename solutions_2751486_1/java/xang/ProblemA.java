package com.forthgo.contest.g2013r1c;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemA {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("A.in"));
            PrintWriter out = new PrintWriter(new FileWriter("A.out"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                out.printf("Case #%d: ", i + 1);
                solve(in, out);
                out.println();
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static void solve(Scanner in, PrintWriter out) {
        String s = in.next("[^ ]+");
        int L = s.length();
        int n = in.nextInt();
        boolean[] vowel = new boolean[256];
        vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = true;
        long[] v = new long[L + 1];
        long preceding = 0;
        long k = -1;
        for (int i = 0; i < L; i++) {
            char c = s.charAt(i);
            long w = 0;
            if (!vowel[c] && preceding >= n - 1) {
                w = i + 1 - (n - 1);
                k = i - (n - 1);
            }
            else {
                if (k >= 0) {
                    w = k + 1;
                }
            }
            if (vowel[c])
                preceding = 0;
            else
                preceding++;

            v[i + 1] = v[i] + w;
        }
        out.print(v[L]);
    }

}

