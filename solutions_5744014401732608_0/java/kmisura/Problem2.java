import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Problem2 {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("data/B-small-attempt0.in"));
        PrintWriter pw = new PrintWriter(new File("data/B-small-attempt0.out"));

        int T = sc.nextInt();

        for (int tc = 1; tc <= T; tc++) {
            int b = sc.nextInt();
            long m = sc.nextLong();

            boolean[][] ret = solve(b, m);
            if (ret == null) {
                pw.println("Case #" + tc + ": IMPOSSIBLE");
            } else {
                pw.println("Case #" + tc + ": POSSIBLE");
                for (int i = 0; i < b; i++) {
                    for (int j = 0; j < b; j++) {
                        if (ret[i][j]) {
                            pw.print(1);
                        } else {
                            pw.print(0);
                        }
                    }
                    pw.println();
                }
            }
        }

        pw.close();
    }

    static boolean[][] solve(int b, long m) {
        boolean[][] ret = new boolean[b][b];
        if (m == (1L << (b - 2))) {
            ret[0][b - 1] = true;
            m--;
        }
        int idx = b - 2;
        while (m > 0 && idx > 0) {
            if (m % 2 == 1) {
                ret[0][idx] = true;
            }
            m >>>= 1;
            idx--;
        }
        if (m != 0) {
            return null;
        }
        for(int i=1;i<b;i++){
            for(int j=i+1;j<b;j++){
                ret[i][j] = true;
            }
        }
        return ret;
    }
}
