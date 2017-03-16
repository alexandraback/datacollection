package gcj2013r1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class FallingDiamonds {
    public static void main(String[] args) throws IOException,
            FileNotFoundException {
        String input = "B-small-attempt0.in";
        String output = "B-small-attempt0.out";
        // String input = "B-large.in";
        // String output = "B-large.out";

        init();

        Scanner scan = new Scanner(new BufferedReader(new FileReader(input)));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(
                output)));

        int T = Integer.parseInt(scan.nextLine());
        for (int t = 1; t <= T; t++) {
            String[] info = scan.nextLine().split(" ");
            int N = Integer.parseInt(info[0]);
            int X = Integer.parseInt(info[1]);
            int Y = Integer.parseInt(info[2]);

            // the level where the interested place at
            int aimLevel = 1 + (Math.abs(X) + Y) / 2;
            int aimIndex = Y;
//            System.out.println("aimLevel : " + aimLevel);
//            System.out.println("aimIndex : " + aimIndex);

            double result = 0;
            for (int level = 1; N > 0; level++) {
                // how many diamonds could be placed in this level
                int capacity = 4 * level - 3;
                // System.out.println("capacity : " + capacity);
                if (level < aimLevel) {
                    N -= capacity;
                    continue;
                }

                // max diamonds each side
                int n = 2 * level - 1;
                // System.out.println("n : " + n);
                if (aimIndex == n - 1 && N < capacity)
                    result = 0;
                else if (N > n - 1 + aimIndex)
                    result = 1;
                else {
                    int maxTheOtherSide = Math.min(N, n - 1);
                    int minThisSide = Math.max(0, N - (n - 1));
                    aimIndex -= minThisSide;
                    double[] ps = new double[n];
                    double p = 1;
                    for (int i = 0; i < maxTheOtherSide - minThisSide; i++) {
                        p /= 2;
                        for (int index = 0; index <= i; index++)
                            ps[index] += p;
                    }
//                    System.out.println("aimIndex : " + aimIndex);
                    result = ps[aimIndex];
                }
                break;
            }

            pw.println("Case #" + t + ": " + result);
            System.out.println("Case #" + t + ": " + result);
//            System.out.println();
        }

        scan.close();
        pw.close();
    }

    private static long[][] c = new long[11][11];

    private static void init() {
        for (int i = 0; i < 11; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= i; j++)
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}
