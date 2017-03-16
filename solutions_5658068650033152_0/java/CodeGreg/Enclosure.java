package enclosure;

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

public class Enclosure {

    public static int N, M, K;
    public static Scanner s;
    public static Writer w;

    public static void main(String[] args) {
        try {
            s = new Scanner(new BufferedReader(new FileReader("C-small-attempt1.in")));
            w = new BufferedWriter(new FileWriter("C-small-attempt1.out"));

            s.useLocale(Locale.US);

            int T = s.nextInt();
            for (int t = 0; t < T; ++t)
                out("Case #" + (t + 1) + ": " + handle() + "\n");
            w.flush();
            w.close();
            s.close();
        } catch (IOException ex) {
            Logger.getLogger(Enclosure.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static int handle() {
        N = s.nextInt();
        M = s.nextInt();
        K = s.nextInt();

        if (N > M) {
            int tmp = M;
            M = N;
            N = tmp;
        }

        if (N <= 2 || M <= 2)
            return K;

        if (K >= N * M - 4)
            return (N - 2) * 2 + (M - 2) * 2 + (K - (N * M - 4));

        int best = K;

        for (int m = 1; m < M - 1; ++m)
            for (int n = 1; n < N - 1; ++n) {
                int k = n * m + m * 2 + n * 2;
                int nec = m * 2 + n * 2;
                if (k >= K) {
                    if (nec < best)
                        best = nec;
                } else if (k + 1 >= K)
                    if (nec + 1 < best)
                        best = nec + 1;
                if (m < 2 || k <= K)
                    continue;
                for (int i = 1; i <= (int) (m / 2) && k >= K; ++i)
                    for (int j = 1; j <= ((int) (n / 2) > i ? 2 : 4); ++j) {
                        k -= i + 1;
                        nec -= 1;
                        if (k >= K && nec < best)
                            best = nec;
                    }
            }
        return best;
    }

    private static void out(String s) {
        try {
            w.write(s);
        } catch (IOException ex) {
            Logger.getLogger(Enclosure.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
