package codejam;

import java.math.BigInteger;
import java.util.Scanner;

public class D {

    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 1; t <= T; t++) {
            String solution = solve(scanner);
            System.out.println("Case #" + t + ":" + solution);
        }
    }

    private static String solve(Scanner scanner) {
        long K = scanner.nextLong();
        long C = scanner.nextLong();
        long S = scanner.nextLong();

        BigInteger KBI = BigInteger.valueOf(K);

        long T = K / C;
        long extraT = (K % C != 0) ? 1 : 0;

        if (S < T + extraT) {
            return " IMPOSSIBLE";
        }

        String toClean = "";
        for (long i = 0; i < T; i++) {
            long t = 1L;
            for (long j = 0; j < C; j++) {
                t += (i * C + j) * KBI.pow((int) (C - 1 - j)).longValue();
            }

            toClean += " " + t;

        }
        if (extraT == 1) {
            long i = T;
            long t = 1L;
            for (long j = 0; j < K % C; j++) {
                t += (i * C + j) * KBI.pow((int) (K % C - 1 -  j)).longValue();
            }

            toClean += " " + t;
        }
        return toClean;
    }

}
