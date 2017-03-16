package com.forthgo.contest.g2014r0;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
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
        double C = in.nextDouble();
        double F = in.nextDouble();
        double X = in.nextDouble();
        double y = X / 2.0;
        double yf = 0;
        for (int k = 1; ; k++) {
            double yk = X / (k * F + 2);
            yf += C / ((k - 1) * F + 2);
            yk += yf;
            if (yk < y)
                y = yk;
            else
                break;
        }
        out.printf("%.7f", y);
    }

}

