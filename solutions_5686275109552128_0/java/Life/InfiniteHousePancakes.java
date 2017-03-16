package codejam2015;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class InfiniteHousePancakes {
    public static void main(String[] args) throws IOException {
        String fileName;

//        fileName = "test.in";
        //fileName = "B-large.in";
        fileName = "B-small-attempt0.in";

        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")))) {
            Scanner sc = new Scanner(r);
            int T = sc.nextInt();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                int d = sc.nextInt();
                int[] p = getArray(sc, d);
                w.write("Case #" + (i + 1) + ": " + calc(p) + "\n");
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }

    }

    private static int[] getArray(Scanner sc, int d) {
        int[] p = new int[d];
        for (int j = 0; j < d; j++) {
            p[j] = sc.nextInt();
        }
        return p;
    }

    private static String calc(int[] p) {
        int max = Integer.MIN_VALUE;
        for (int aP : p) {
            max = Math.max(max, aP);
        }

        int optimal = max;
        for (int target = 1; target < max - 1; target++) {
            int specialMins = 0;
            for (int j = 0; j < p.length; j++) {
                if (p[j] > target) {
                    specialMins += (p[j] + target - 1) / target - 1;
                }
            }
            int total = target + specialMins;
            if (total < optimal) {
                optimal = total;
            }
        }
        return "" + optimal;
    }
}
