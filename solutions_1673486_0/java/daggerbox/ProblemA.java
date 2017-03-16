package com.forthgo.google.g2012r1a;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by Xan Gregg.
 * Date: 4/27/12
 */
public class ProblemA {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("A.in"));
            PrintWriter out = new PrintWriter(new FileWriter("A.out"));
            //PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                double p = solve(in, a, b);
                out.printf("Case #%d: %f%n", i + 1, p);
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static double solve(Scanner in, int a, int b) {
        double[] p = new double[a+1];
        double[] q = new double[a+1];
        q[0] = 1;
        for (int i = 1; i <= a; i++) {
            p[i] = in.nextDouble();
            if (i == 1)
                q[i] = p[i];
            else
                q[i] = p[i] * q[i - 1];
        }
        double min = b + 2;
        double [] cost = new double[a + 1];
        for (int i = 0; i <= a; i++) {
            cost[i] = a - i;
            cost[i] += q[i] * (b - i + 1) + (1 - q[i]) * (b - i + 1 + b + 1);
            if (cost[i] < min) {
                min = cost[i];
            }
        }
        double e = min;
        return e;
    }

}

