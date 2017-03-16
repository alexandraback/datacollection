import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B {
    private static final String inFile = "B-small-attempt0.in";
    private static final String outFile = "B-out.txt";

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        int T = scanner.nextInt();
        FileWriter fw = new FileWriter(outFile);
        for (int t = 1; t <= T; ++t) {
            int d = scanner.nextInt();
            int[] p = new int[d];
            for (int i = 0; i < d; ++i) {
                p[i] = scanner.nextInt();
            }
            fw.write(String.format("Case #%d: %d\n", t, solve(p)));
        }
        fw.close();
    }

    private static int solve(int[] p) {
        int n = p.length;
        int max = 0;
        for (int i = 0; i < n; ++i) {
            max = Math.max(max, p[i]);
        }
        int res = Integer.MAX_VALUE;
        for (int k = 1; k <= max; ++k) {
            int s = 0;
            for (int i = 0; i < n; ++i) {
                if (p[i] > k) {
                    s += p[i]/k - 1;
                    if (p[i]%k != 0) ++s;
                }
            }
            res = Math.min(res, s + k);
        }
        return res;
    }
}
