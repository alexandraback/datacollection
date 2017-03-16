import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Round 1C. Problem C.
 */
public class ProblemC {

    public static void main(String[] args) throws Exception {
        new ProblemC().run();
    }

    private void run() throws Exception {
        Scanner in = new Scanner(new BufferedInputStream(System.in));
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int testCount = in.nextInt();
        for (int test = 1; test <= testCount; test++) {
            int n = in.nextInt();
            int nn[] = new int[n];
            int w[] = new int[n];
            int e[] = new int[n];
            int s[] = new int[n];
            int deltaD[] = new int[n];
            int deltaP[] = new int[n];
            int deltaS[] = new int[n];
            int nextD[] = new int[n];
            int maxL = 1000000;
            for (int i = 0; i < n; i++) {
                nextD[i] = in.nextInt();
                nn[i] = in.nextInt();
                w[i] = in.nextInt() + maxL;
                e[i] = in.nextInt() + maxL;
                s[i] = in.nextInt();
                deltaD[i] = in.nextInt();
                deltaP[i] = in.nextInt();
                deltaS[i] = in.nextInt();
            }

            int wall[] = new int[2 * maxL];
            int day = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                if ((nn[i] > 0) && (nextD[i] < day)) {
                    day = nextD[i];
                }
            }
            boolean nadoelo;
            int res = 0;
            do {
                nadoelo = true;
                int temp[] = new int[2 * maxL];
                System.arraycopy(wall, 0, temp, 0, wall.length);
                for (int i = 0; i < n; i++) {
                    boolean ok = false;
                    if ((nextD[i] == day) && (nn[i] > 0)) {
                        for (int j = w[i]; j < e[i]; j++) {
                            if (temp[j] < s[i]) {
                                ok = true;
                                wall[j] = Math.max(s[i], wall[j]);
                            }
                        }
                        w[i] += deltaP[i];
                        e[i] += deltaP[i];
                        s[i] += deltaS[i];
                        nextD[i] += deltaD[i];
                        nn[i]--;
                    }
                    if (ok) {
                        res++;
                    }
                }
                day = Integer.MAX_VALUE;
                for (int i = 0; i < n; i++) {
                    if ((nn[i] > 0) && (nextD[i] < day)) {
                        day = nextD[i];
                    }
                    if (nn[i] > 0) {
                        nadoelo = false;
                    }
                }
            } while (!nadoelo);

            out.print("Case #" + test + ": " + res);
            if (test < testCount) {
                out.println();
            }
        }

        in.close();
        out.close();
    }
}