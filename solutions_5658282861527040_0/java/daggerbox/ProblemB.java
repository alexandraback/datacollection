package com.forthgo.contest.g2014.r1b;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class ProblemB {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("B.in.txt"));
            PrintWriter out = new PrintWriter(new FileWriter("B.out.txt"));
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
            throw new RuntimeException(e);
        }

    }

    private static void solve(Scanner in, PrintWriter out) {
        long A = in.nextLong();
        long B = in.nextLong();
        long K = in.nextLong();

        long count = 0;
        for (long a = 0; a < A; a++) {
            for (long b = 0; b < B; b++) {
                if ((a & b) < K)
                    count++;
            }
        }
        out.print(count);
    }


}


