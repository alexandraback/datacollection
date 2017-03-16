package partElf;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Locale;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class PartElf {

    public static long P, Q;
    public static int Qfak;
    public static Scanner s;
    public static Writer w;

    public static void main(String[] args) {
        try {
            s = new Scanner(new BufferedReader(new FileReader("A-large.in")));
            w = new BufferedWriter(new FileWriter("A-large.out"));

            s.useLocale(Locale.US);

            int T = s.nextInt();
            for (int t = 0; t < T; ++t) {
                int sol = handle();
                if (sol == -1)
                    out("Case #" + (t + 1) + ": impossible\n");
                else
                    out("Case #" + (t + 1) + ": " + sol + "\n");

            }
            w.flush();
            w.close();
            s.close();
        } catch (IOException ex) {
            Logger.getLogger(PartElf.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static long ggt(long a, long b) {
        while (a > 0) {
            if (a < b) {
                long tmp = a;
                a = b;
                b = tmp;
            }
            a %= b;
        }
        return b;
    }

    private static int handle() {
        String line = s.next();
        P = Long.parseLong(line.substring(0, line.indexOf('/')));
        Q = Long.parseLong(line.substring(line.indexOf('/') + 1));

        System.out.println("ggt");
        long ggt = ggt(P, Q);
        P /= ggt;
        Q /= ggt;

        Qfak = -1;
        int fak = 0;
        for (long k = 1; fak < 50; fak++) {
            if (Q == k) {
                Qfak = fak;
                break;
            }
            k *= 2;
        }

        if (Qfak == -1)
            return -1;

        long div = Q;
        while (div > P)
            div /= 2;

        long rest = P - div;

        System.out.println("term");
        if (terminate(rest * 2) + 1 >= 40)
            return -1;
        System.out.println("termed");

        int doub = 0;
        while (div < Q) {
            div *= 2;
            doub++;
        }
        return doub;
    }

    private static int terminate(long p) {
//        System.out.println("terminate: " + p);
        if (p > Q / 2)
            p = Q - p;

        if (p == 0)
            return 0;

        long fak = 1;
        for (int i = 0; i <= 40; ++i) {
            if (p == fak)
                return Qfak - i;
            fak *= 2;
        }

        long div = Q;
        while (div > p)
            div /= 2;
        return Math.max(terminate(div * 2), terminate((p - div) * 2)) + 1;
    }

    private static void out(String s) {
        try {
            w.write(s);
        } catch (IOException ex) {
            Logger.getLogger(PartElf.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
