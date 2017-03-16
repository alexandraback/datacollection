package magictrick;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;

public class ProblemB {

    public static double F;
    public static double C;
    public static double X;

    public static double nthTime[] = new double[1000000];

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File f = new File("problemB.in");
        File f2 = new File("ProblemBSolve.out");
        Scanner sc = new Scanner(f);
        FileWriter fw = new FileWriter(f2);

        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            C = sc.nextDouble();
            F = sc.nextDouble();
            X = sc.nextDouble();
            nthTime = new double[1000000];
            int j = 0;
            
            double jTh = computeNFarmsTotalTime(j);
            double jThpls = computeNFarmsTotalTime(j + 1);
            while (jTh > jThpls) {
                j++;
                jTh = computeNFarmsTotalTime(j);
                jThpls = computeNFarmsTotalTime(j + 1);
            }

            fw.append("Case #" + (i + 1) + ": " + new DecimalFormat("0.0000000").format(jTh));
            
            if (i < T - 1) {
                fw.append("\n");
            }
        }
        fw.close();
    }

    public static double computeNFarmsTime(int n) {
        if (n == 0) {
            nthTime[0] = 0;
            return 0;
        }
        if (nthTime[n] != 0) {
            return nthTime[n];
        }
        nthTime[n] = computeNFarmsTime(n - 1) + C / (2 + F * (n - 1));
        return nthTime[n];
    }

    public static double computeNFarmsTotalTime(int n) {
        return computeNFarmsTime(n) + X / (2 + F * n);
    }
}
