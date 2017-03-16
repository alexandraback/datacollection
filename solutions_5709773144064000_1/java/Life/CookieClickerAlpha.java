package codejam2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class CookieClickerAlpha {
    public static void main(String[] args) throws IOException {

        String fileName;

        fileName = "B-large.in";
        //fileName = "test.in";

        try (BufferedReader r = new BufferedReader(new FileReader(fileName));
             BufferedWriter w = new BufferedWriter(new FileWriter(fileName.replace(".in", ".out")));) {
            Scanner s = new Scanner(r);
            int T = s.nextInt();
            long startTotal = System.currentTimeMillis();
            for (int i = 0; i < T; i++) {
                double C = s.nextDouble();
                double F = s.nextDouble();
                double X = s.nextDouble();
                w.write("Case #" + (i + 1) + ": " + calc(C, F, X) + "\n");
                System.out.println("case " + +(i + 1) + ". time: " + (System.currentTimeMillis() - startTotal));
            }
            System.out.println("Total time: " + (System.currentTimeMillis() - startTotal));
        }
    }

    // should be possible to use binary search
    private static String calc(double C, double F, double X) {
        double minTime = 1.0 * X / 2;
        double lastFactoryBuildTime = 0;
        int k = 0;
        while (true) {
            // time to build next factory
            double t = 1.0 * C / (2 + F * k);
            double nextFactory = lastFactoryBuildTime + t;
            k++;
            double goal = nextFactory + 1.0 * X / (2 + F * k);
            if(goal > minTime) {
                break;
            } else {
                minTime = goal;
                lastFactoryBuildTime = nextFactory;
            }
        }
        return String.format("%.8f", minTime);
    }
}

