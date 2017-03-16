package the2012.round1a;

import java.io.*;
import java.util.Scanner;

public class PasswordProblem {


    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(new BufferedInputStream(new FileInputStream("/Users/taobo2/Documents/A-small-attempt1.in")));
        Writer writer = new BufferedWriter(new FileWriter("A-small-attempt0-1ans.txt"));
        int N = scanner.nextInt();
        for (int i = 1; i <= N; i++) {
            int typedLen = scanner.nextInt();
            int total = scanner.nextInt();
            double[] typed = new double[typedLen];
            for (int j = 0; j < typed.length; j++)
                typed[j] = scanner.nextDouble();
            writer.write("Case #" + i + ": " + new PasswordProblem().solve(typed, total) + "\n");
        }

        writer.flush();
        writer.close();
    }

    public double solve(double[] typed, int total) {
        double ret = Double.MAX_VALUE;

        int left = total - typed.length;
        double[] gailv = new double[typed.length + 1];
        gailv[0] = 1;
        double mul = 1.0d;
        for (int i = 0; i < typed.length; ++i) {
            mul *= typed[i];
            gailv[i+1] = mul;

        }


        ret = gailv[gailv.length - 1] * (left + 1) + (1 - gailv[gailv.length - 1]) * (left + 1 + typed.length + 1 + left);


        double temp = 0.0d;


        for (int i = typed.length; i > 0; i--) {
            temp = (1 - gailv[gailv.length - i - 1]) * (i + i + left + left + typed.length + 1 + 1) + gailv[gailv.length - i - 1] * (i + i + left + 1);

            ret = Math.min(ret, temp);

        }


        ret = Math.min(ret, left + typed.length + 1 + 1);

        return ret;
    }

}
