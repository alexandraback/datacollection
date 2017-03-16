package codejam2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class DeceitfulWar {
    public static void main(String[] args) throws IOException {

        String fileName;

        //fileName = "test.in";
        fileName = "D-small-attempt0.in";
        //fileName = "D-large.in";
        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")));) {
            Scanner s = new Scanner(r);
            int T = s.nextInt();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                int N = s.nextInt();
                double[] massN = getArray(s, N);
                double[] massK = getArray(s, N);
                w.write("Case #" + (i + 1) + ": " + calc(N, massN, massK) +"\n");
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }
    }

    private static double[] getArray(Scanner s, int n) {
        double[] res = new double[n];
        for (int i = 0; i < n; i++) {
            res[i] = s.nextDouble();
        }
        return res;
    }

    // should be possible to use binary search
    private static String calc(int N, double[] massN, double[] massK) {
        Arrays.sort(massN);
        Arrays.sort(massK);
        int deceitfulWar = calcScore(N, massN, massK);
        int war = N - calcScore(N, massK, massN );
        return deceitfulWar  + " " + war;
    }

    private static int calcScore(int n, double[] mass1, double[] mass2) {
        int res = 0;
        int i = 0;
        int j = 0;
        while(i < n ) {
            if(mass1[i] > mass2[j]) {
                res++;
                j++;
            }
            i++;
        }
        return res;
    }


}

