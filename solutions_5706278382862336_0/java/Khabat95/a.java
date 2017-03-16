package gcj2014.round1C;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by khabat95 on 11/05/14.
 */
public class a {

    public static String alg(double p, double q) {
        if ((long)q % 2 != 0)
            return "impossible";
        double test = q;
        while (test > 1) {
            test = test/2.0;
        }
        if (test != 1.0)
            return "impossible";
        double fract = p / q;
        long res = 0;
        while (fract < 1) {
            fract *= 2;
            res++;
        }
        return String.valueOf(res);
    }

    public static void main(String args[]) {
        try {
            Scanner sc = new Scanner(new FileReader("/home/khabat95/gcj2014/round1C/a1.in"));
            PrintWriter pw = new PrintWriter("/home/khabat95/gcj2014/round1C/a1.out");

            int T = sc.nextInt();
            for (int i = 0; i < T; i++) {
                String s = sc.next();
                double p = Long.valueOf(s.split("/")[0]);
                double q = Long.valueOf(s.split("/")[1]);
                System.out.println("Test case " + (i + 1) + "...");
                pw.println("Case #" + (i + 1) + ": " + alg(p, q));
            }

            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
