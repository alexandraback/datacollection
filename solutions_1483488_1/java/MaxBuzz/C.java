import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
    static final int MAX_N = 2000000;
    static int[][] precalc;
    static {
        precalc = new int[MAX_N + 1][];
        List<Integer> values = new ArrayList<Integer>();
        for (int i = 1, deg = 1; i <= MAX_N; ++i) {
            if (i == deg * 10) {
                deg *= 10;
            }
            values.clear();
            int curr = (i % 10) * deg + (i / 10);
            while (curr != i) {
                if (curr > i) {
                    values.add(curr);
                }
                curr = (curr % 10) * deg + (curr / 10);
            }
            int[] z = new int[values.size()];
            for (int j = 0; j < z.length; ++j) {
                z[j] = values.get(j);
            }
            precalc[i] = z;
        }
    }

    public void run(Scanner in, PrintWriter out, int nCase) {
        int min = in.nextInt();
        int max = in.nextInt();
        int count = 0;
        for (int i = min; i <= max; ++i) {
            for (int j : precalc[i]) {
                if (j <= max) {
                    ++count;
                }
            }
        }
        out.printf("Case #%d: %d%n", nCase, count);
    }

    public static void main(String[] args) throws FileNotFoundException {
        String filename = C.class.getSimpleName().toLowerCase();

        Scanner in = new Scanner(new File(filename + ".in"));
        PrintWriter out = new PrintWriter(filename + ".out");

        int nCases = in.nextInt();

        for (int i = 1; i <= nCases; ++i) {
            new C().run(in, out, i);
        }

        out.close();
        in.close();
    }
}
