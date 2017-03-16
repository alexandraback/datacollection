package com.cuteants.problems.codejam.y2012.round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class KindomRush {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        in = new Scanner(
            "4\n" +
            "2\n" +
            "0 1\n" +
            "0 2\n" +
            "3\n" +
            "2 2\n" +
            "0 0\n" +
            "4 4\n" +
            "1\n" +
            "1 1\n" +
            "5\n" +
            "0 5\n" +
            "0 1\n" +
            "1 1\n" +
            "4 7\n" +
            "5 6 ");
        in = new Scanner(new File("C:\\Users\\aurel\\Downloads\\B-small-attempt1.in"));
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            int n = in.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            int[] L = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = in.nextInt();
                b[j] = in.nextInt();
            }

            int levels = 0;
            int stars = 0;

            boolean over = false;
            while (!over) {
                boolean found = false;
                for (int j = 0; j < n; j++) {
                    if (stars >= b[j] && L[j] == 0) {
                        stars += 2;
                        L[j] = 2;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    for (int j = 0; j < n; j++) {
                        if (stars >= b[j] && L[j] == 1) {
                            stars += 1;
                            L[j] = 2;
                            found = true;
                            break;
                        }
                    }
                }
                if (!found) {
                    int maxb = -1;
                    int bestj = -1;
                    for (int j = 0; j < n; j++) {
                        if (stars >= a[j] && L[j] == 0) {
                            if (maxb < b[j]) {
                                maxb = b[j];
                                bestj = j;
                            }
                        }
                    }
                    if (bestj != -1) {
                        stars += 1;
                        L[bestj] = 1;
                        found = true;
                    }
                }
                if (found) {
                    levels++;
                    if (stars == 2 * n) {
                        over = true;
                    }
                } else {
                    over = true;
                    levels = -1;
                }
            }

            System.out.println("Case #" + i + ": " + (levels >= 0 ? levels : "Too Bad"));
        }
    }
}
