package codejam2013.lawnmower;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Lawnmower {

    public static void main(String[] args) throws FileNotFoundException {

        System.out.println(args[0]);
        System.out.println(args[1]);

        final Scanner sc = new Scanner(new FileInputStream((args[0])));
        final PrintStream out = new PrintStream(new FileOutputStream(args[1]));

        final int np = sc.nextInt();
        for (int p = 0; p < np; ++p) {

            final int n = sc.nextInt();
            final int m = sc.nextInt();

            final int lawn[][] = new int[n][m];
            final int rowmax[] = new int[n];
            final int colmax[] = new int[m];

            Arrays.fill(rowmax, Integer.MIN_VALUE);
            Arrays.fill(colmax, Integer.MIN_VALUE);

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    lawn[i][j] = sc.nextInt();
                    rowmax[i] = Math.max(rowmax[i], lawn[i][j]);
                    colmax[j] = Math.max(colmax[j], lawn[i][j]);
                }
            }

            boolean ok = true;
            for (int i = 0; ok && i < n; ++i) {
                for (int j = 0; ok && j < m; ++j) {
                    if ((lawn[i][j] < rowmax[i]) && (lawn[i][j] < colmax[j])) {
                        ok = false;
                        out.format("Case #%s: NO\n", p + 1);
                    }
                }
            }

            if (ok) {
                out.format("Case #%s: YES\n", p + 1);
            }

        }

        out.close();

    }

}
