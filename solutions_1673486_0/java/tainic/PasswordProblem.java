package com.cuteants.problems.codejam.y2012.round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class PasswordProblem {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        in = new Scanner(
            "3\n" +
            "2 5\n" +
            "0.6 0.6\n" +
            "1 20\n" +
            "1\n" +
            "3 4\n" +
            "1 0.9 0.1");
        in = new Scanner(new File("C:\\Users\\aurel\\Downloads\\A-small-attempt0.in"));
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            int a = in.nextInt();
            int b = in.nextInt();
            double[] p = new double[a];
            for (int j = 0; j < a; j++) {
                p[j] = in.nextDouble();
            }

            double P = 1;
            double min = b + 2;
            for (int x = a; x >= 0; x--) {
                if (x != a)
                    P *= p[a - x - 1];
                double prob = 2 * x + 2 * b - a + 2 - (b + 1) * P;
                if (prob < min) {
                    min = prob;
                }
            }
            System.out.println("Case #" + i + ": " + String.format("%.7f", min));
        }
    }
}
