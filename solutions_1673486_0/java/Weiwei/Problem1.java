package codejam;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Problem1 {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new FileInputStream(new File(
                "A-small-attempt0.in")));

        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            sc.nextLine();
            int A = sc.nextInt();
            int B = sc.nextInt();
            sc.nextLine();

            double[] P = new double[A];
            for (int j = 0; j < A; j++) {
                P[j] = sc.nextDouble();
            }

            System.out.println(String.format("Case #%1$d: %2$.6f", i + 1,
                    solve(A, B, P)));
        }

        while (sc.hasNext()) {
            System.out.println(sc.nextLine());
        }

        sc.close();
    }

    private static double solve(int A, int B, double[] P) {

        double min = (double) (B + 2);

        int s = 2 * B - A + 2 + 2 * P.length;
        double r = 1.0d;
        double f = (double) (B + 1);

        double k = (double) s - f * r;
        if (k < min) {
            min = k;
        }

        for (int i = 0; i < P.length; i++) {
            r *= P[i];
            s -= 2;

            k = (double) s - f * r;
            if (k < min) {
                min = k;
            }
        }

        return min;
    }

}
