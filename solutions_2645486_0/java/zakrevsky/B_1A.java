import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B_1A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("1A/B-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new File("1A/b.out"));
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int e = in.nextInt();
            int r = in.nextInt();
            int n = in.nextInt();
            int[] v = new int[n];
            for (int i = 0; i < n; v[i++] = in.nextInt());

            int ans = calc(e, r, n, v, 0, e, 0);
            out.println("Case #" + t + ": " + ans);
        }
        out.close();
    }

    private static int calc(int e, int r, int n, int[] v, int i, int tE, int gain) {
        if (i == n) return gain;

        int ans = 0;
        for (int j = 0; j <= tE; j++) {
            ans = Math.max(ans, calc(e, r, n, v, i + 1, Math.min(tE - j + r, e), gain + v[i] * j));
        }
        return ans;
    }
}
