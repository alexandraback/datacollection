import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by burger on 4/12/14.
 */
public class CookieClickerAlpha {
    private static Scanner sc;

    public static void main(String[] args) {
        try {
            sc = new Scanner(new File("small.in"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        try {
            PrintWriter writer = new PrintWriter("answer.out", "UTF-8");

            int T = sc.nextInt();
            for (int t = 1; t <= T; t++) {
                double C = sc.nextDouble();
                double F = sc.nextDouble();
                double X = sc.nextDouble();
                writer.write("Case #" + t + ": " + new CookieClickerAlpha().solve(C, F, X) + "\n");
            }
            writer.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }

    private double solve(double C, double F, double X) {
        final int MAX_NUM_FARMS = 100000;

        double f = 2.0, timeToBuyFarms = 0, res = X / f;
        for (int i = 1; i <= MAX_NUM_FARMS; i++) {
            timeToBuyFarms = timeToBuyFarms + C / f;
            f += F;
            res = Math.min(res, X / f + timeToBuyFarms);
        }

        return res;
    }
}
