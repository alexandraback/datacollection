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
        long common = pgcd((long)p, (long)q);
        p = p/(double)common;
        q = q/(double)common;
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
            Scanner sc = new Scanner(new FileReader("/home/khabat95/gcj2014/round1C/a2.in"));
            PrintWriter pw = new PrintWriter("/home/khabat95/gcj2014/round1C/a2.out");

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

    public static long pgcd(long a,long b) {
        long r = a;
        while (r!=0)  {r = a%b; a=b; b=r; }
        return(Math.abs(a));
    }
}
