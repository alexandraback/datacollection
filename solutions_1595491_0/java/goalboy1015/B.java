
import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {

    public static void main(String args[]) throws Exception {
        final String PATH = "/home/goalboy/software installation/codejam-commandline-1.0-beta4/source/";
        final String FILE = "B-small-0";
        Scanner in = new Scanner(new File(PATH + FILE + ".in"));
        PrintWriter out = new PrintWriter(PATH + FILE + ".out");

        int test = in.nextInt();
        for (int t = 1; t <= test; t++) {
            int N = in.nextInt();
            int S = in.nextInt();
            int p = in.nextInt();
            int totals[] = new int[N];
            int bests[] = new int[N];
            boolean addables[] = new boolean[N];
            for (int i = 0; i < N; i++) {
                totals[i] = in.nextInt();
            }
            Arrays.sort(totals);
            for (int i = 0; i < N; i++) {
                if (totals[i] % 3 == 0) {
                    bests[i] = totals[i] / 3;
                    addables[i] = (bests[i] > 0);
                } else if (totals[i] % 3 == 1) {
                    bests[i] = totals[i] / 3 + 1;
                    addables[i] = false;
                } else {
                    bests[i] = totals[i] / 3 + 1;
                    addables[i] = (bests[i] > 0);
                }
            }
            int result = 0;
            for (int i = N - 1; i >= 0; i--) {
                if (bests[i] >= p) {
                    result++;
                } else if (addables[i] && bests[i] + 1 >= p && S > 0) {
                    result++;
                    S--;
                }
            }
            out.println("Case #" + t + ": " + result);
        }

        out.close();
    }
}
