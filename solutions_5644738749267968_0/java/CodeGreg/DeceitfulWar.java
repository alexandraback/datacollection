package deceitfulWar;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class DeceitfulWar {

    static final int N_MAX = 1000;
    static double[] nvals = new double[N_MAX];
    static double[] kvals = new double[N_MAX];

    public static void main(String[] args) {
        Scanner s = null;
        try {
            s = new Scanner(new BufferedReader(new FileReader("small_war.in")));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DeceitfulWar.class.getName()).log(Level.SEVERE, null, ex);
        }
        s.useLocale(Locale.US);
        int T = s.nextInt();
        for (int t = 0; t < T; ++t) {
            int N = s.nextInt();

            for (int i = 0; i < N; ++i)
                nvals[i] = s.nextDouble();
            for (int i = 0; i < N; ++i)
                kvals[i] = s.nextDouble();

            Arrays.sort(nvals, 0, N);
            Arrays.sort(kvals, 0, N);

            /*            System.out.print("nvals:");
             for (int i = 0; i < N; ++i)
             System.out.print(" " + nvals[i]);
             System.out.println("");
             System.out.print("kvals:");
             for (int i = 0; i < N; ++i)
             System.out.print(" " + kvals[i]);
             System.out.println("");
             */
            int warWin = 0;

            int smallestk = 0;
            for (int n = 0; n < N; ++n) {
                while (smallestk < N && kvals[smallestk] < nvals[n])
                    smallestk++;
//                System.out.println("n: " + n + " -> " + smallestk);
                if (smallestk == N) {
                    warWin = N - n;
                    break;
                }
                smallestk++;
            }

            int decWarWin = warWin;
            for (int out = 0; out < N; ++out) {
                int n = out;
                while (n < N && nvals[n] > kvals[n - out])
                    n++;
                if (n == N)
                    decWarWin = Math.max(decWarWin, N - out);
                /*
                 smallestk = 0;
                 for (int n = out; n < N; ++n) {
                 if ()
                    
                 /*                    while (smallestk < N - out && kvals[smallestk] < nvals[n])
                 smallestk++;
                 System.out.println("n: " + n + " -> " + smallestk);
                 if (smallestk == N - out) {
                 System.out.println("out: " + out + " -> " + (N - n) + "(smallestk: " + smallestk + ", n: " + n + ")");
                 decWarWin = Math.max(decWarWin, N - n);
                 break;
                 }
                 smallestk++;*/
            }
            System.out.println("Case #" + (t + 1) + ": " + decWarWin + " " + warWin);
        }
    }
}
