package problem;

import deceitfulWar.*;
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

public class Problem {

    static final int N_MAX = 1000;
    static double[] nvals = new double[N_MAX];
    static double[] kvals = new double[N_MAX];

    private static long pos(int A, int B, int K) {
        if (A <= K || B <= K)
            return A * B;
        if (K == 0)
            return (int) (A / 2) * (int) (B / 2);
        int larK = 60;
        while ((larK & (1 << larK)) != 1)
            larK--;
        long prevPos = (A >> larK) * (B >> larK);
        System.out.println("prevPos: ");

        return 0;
    }

    public static void main(String[] args) {
        try {
            Scanner s = new Scanner(new BufferedReader(new FileReader("B-small-attempt0.in")));
            Writer w = new BufferedWriter(new FileWriter("B-small-attempt0.out"));

            s.useLocale(Locale.US);

            int T = s.nextInt();
            for (int t = 0; t < T; ++t) {
                int A, B, K;
                A = s.nextInt();
                B = s.nextInt();
                K = s.nextInt();
                long poss = 0;
                for (int a = 0; a < A; ++a)
                    for (int b = 0; b < B; ++b)
                        if ((a & b) < K)
                            poss++;

                w.write("Case #" + (t + 1) + ": " + poss + "\n");
            }
            w.flush();
            w.close();
            s.close();
        } catch (IOException ex) {
            Logger.getLogger(DeceitfulWar.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
