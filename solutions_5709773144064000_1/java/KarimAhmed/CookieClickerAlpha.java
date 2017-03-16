
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author kahmed
 */
public class CookieClickerAlpha {

    public static double C, F, X;

    public static double start(double iterations, double currRate) {
        double s = 0;
        double time=Double.MAX_VALUE;
        while (iterations > 0) {
            time = Math.min(time, s + (X / currRate));
            s += C / currRate;
            currRate += F;
            iterations--;
        }
        return time;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("B-large.in"));
        PrintWriter out = new PrintWriter("B-large.out");
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            C = sc.nextDouble();
            F = sc.nextDouble();
            X = sc.nextDouble();
            double result = start(100000, 2);
            out.println("Case #" + (i + 1) + ": " + (result));
            out.flush();
        }
    }
}
