
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(B.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(B.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = in.nextInt();
            }
        }
        boolean[][] z = new boolean[n][m];
        while (true) {
            int mi = 0;
            int mj = 0;
            int min = 1000;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!z[i][j] && a[i][j] < min) {
                        min = a[i][j];
                        mi = i;
                        mj = j;
                    }
                }
            }
            boolean ok = true;
            for (int j = 0; j < m; j++) {
                if (!z[mi][j] && a[mi][j] > min) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int j = 0; j < m; j++) {
                    z[mi][j] = true;
                }
            } else {
                ok = true;
                for (int i = 0; i < n; i++) {
                    if (!z[i][mj] && a[i][mj] > min) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    for (int i = 0; i < n; i++) {
                        z[i][mj] = true;
                    }
                } else {
                    return "NO";
                }
            }
            if (min == 1000) break;
        }
        return "YES";
    }
}