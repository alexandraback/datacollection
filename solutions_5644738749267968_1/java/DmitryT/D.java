import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * by dt on 4/12/14, 2:28 AM
 */
public class D {
    static PrintWriter pwdf = new PrintWriter(System.out);
    public static void main(String[] args) throws FileNotFoundException {
//        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new File("./GCJ14qual/D-small-attempt2.in"));
        Scanner sc = new Scanner(new File("./GCJ14qual/D-large.in"));
//        PrintWriter pw = new PrintWriter(new File("./GCJ14qual/D-small-attempt2.out"));
        PrintWriter pw = new PrintWriter(new File("./GCJ14qual/D-large.out"));
//        PrintWriter pwdf = new PrintWriter(new File("./GCJ14qual/D-large-debug.txt"));
//        PrintWriter pwdf = new PrintWriter(new File("./GCJ14qual/D-small-attempt0-debug.txt"));

//        PrintWriter pw = new PrintWriter(System.out);

        int t = sc.nextInt();
        for (int j = 1; j <= t; j ++) {
            int m = sc.nextInt();
            double[] k = new double[m], n = new double[m];
            for (int l = 0; l < m; l ++) {
                n[l] = sc.nextDouble();
            }
            for (int l = 0; l < m; l ++) {
                k[l] = sc.nextDouble();
            }
            Arrays.sort(n);
            Arrays.sort(k);

            pwdf.println("N: " + Arrays.toString(n));
            pwdf.println("K: " + Arrays.toString(k));
            int w = war(m, k , n);
            pwdf.println("Case #" + j + ": " + ((m == 1) ? w : dWar(m, k, n)) + " " + w);
            pwdf.flush();

            pw.println("Case #" + j + ": " + ((m == 1) ? war(m, k , n) : dWar(m, k, n)) + " " + war(m, k, n));
            pwdf.flush();
        }

        pw.close();
        pwdf.close();
    }

    private static int dWar(int m, double[] k, double[] n) {
        boolean[] ku = new boolean[m];
        int nw = 0;
        int i = 0;
        int j = 0;

        while (i < m) {
            if (n[i] > k[j]) {
                int km = km(k, ku, n[i]);
                double dec = decMin(n, n[i], k, ku);
                int kmd = km(k, ku, dec);
                double nt = (n[i] < k[km] && (km != kmd)) ? dec : n[i];
                kmd = km(k, ku, nt);
                if (n[i] > k[kmd]) {
                    nw ++;
                }
                boolean f = nt < 0 || (n[i] < k[kmd] && nt > k[kmd]);
//                pwdf.println(String.format("nm = %f, km = %f, nt = %f, kmd = %f %s, %d", n[i], k[km], nt, k[kmd], !f ? "OK" : "FAIL", nw));
                ku[kmd] = true;
                j ++;
            }
            i ++;
        }
        return nw;
    }

    private static double decMin(double[] n, double nm, double[] k, boolean[] ku) {
        double min = Double.MAX_VALUE;
        for (int i = k.length - 1; i >= 0; i --) {
            if (!ku[i] && k[i] < min) {
                min = k[i];
            }
        }
        // ken's min unused block -- to be attacked

        double s = Double.MIN_VALUE;
        for (int i = k.length - 1; i >= 0; i --) {
            if (!ku[i] && k[i] > s && nm > min) {
                s = k[i];
            }
        }
        // ken's max unused block found

        boolean m = false; // make sure they don't match
        do {
            s += 0.000001;
            for (double kk : k) {
                m |= (kk == s);
            }
        } while (m);

        return s;
    }

    private static double decMax(double[] n, double nm, double[] k, boolean[] ku) {
        double s = Double.MIN_VALUE;
        for (int i = k.length - 1; i >= 0; i --) {
            if (!ku[i] && k[i] > s) {
                s = k[i];
            }
        }
        // ken's max unused block found -- to be attacked

        boolean m = false; // make sure they don't match
        do {
            s -= 0.000001;
            for (double kk : k) {
                m |= (kk == s);
            }
        } while (m);

        return s;
    }

    private static int war(int m, double[] k, double[] n) {
        boolean[] ku = new boolean[m];

        int nw = 0;
        for (int i = 0; i < m; i ++) { // game turns
            int km = km(k, ku, n[i]);
            if (n[i] > k[km]) {
                nw ++;
            }
            ku[km] = true;
        }

        return nw;
    }

    private static int km(double[] k, boolean[] ku, double v) {
        int idx = -1;
        double s = Double.MAX_VALUE;
        for (int i = k.length - 1; i >= 0; i --) { // pick up one slightly larger
            if (!ku[i] && k[i] > v && k[i] < s) {
                s = k[i];
                idx = i;
            }
        }
        s = Double.MAX_VALUE;
        if (idx == -1) { // losing, pick up smallest
            for (int i = 0; i < k.length; i ++) { // pick up one slightly larger
                if (!ku[i] && k[i] < s) {
                    s = k[i];
                    idx = i;
                }
            }
        }
        return idx;
    }
}