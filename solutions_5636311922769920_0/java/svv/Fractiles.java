package codejam.year2016.qualification.fractiles;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Scanner;

public class Fractiles {


    public static void main(String[] args) {
        new Fractiles().run();
    }

    private void run() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = in.nextInt();
        in.skip("\n");
        for (int i = 1; i <= N; ++i) {
            System.out.print("Case #" + i + ": " + readAndSolve(in));
            if (i != N) {
                System.out.println();
            }
        }
    }

    private String readAndSolve(Scanner in) {
        int K = in.nextInt(); // original size
        int C = in.nextInt(); // complexity
        int S = in.nextInt(); // tiles

        double req = Math.round(Math.ceil(((double) K) / C));
        if (req > S) {
            return "IMPOSSIBLE";
        }

        BigInteger CC = BigInteger.valueOf(C);
        BigInteger KK = BigInteger.valueOf(K);

        BigInteger size = KK.pow(C);

        StringBuilder sb = new StringBuilder();
        int start = 0;
        for (int i = 0; i < req; i++) {
            BigInteger pos = pos(K, C, start).add(BigInteger.ONE);
            sb.append(pos).append(" ");

            start += C;
            if (start >= K)
                start = K - 1;
        }
        sb.setLength(sb.length() - 1);

        return sb.toString();
    }

    static BigInteger pos(int K, int C, int start) {
        BigInteger KK = BigInteger.valueOf(K);
        BigInteger CC = BigInteger.valueOf(C);

        BigInteger p = BigInteger.valueOf(start);

        BigInteger r = BigInteger.valueOf(start);

        for (int i = 2; i <= C; i++) {
            p = p.add(BigInteger.ONE);
            if (p.compareTo(KK) >= 0)
                p = KK.subtract(BigInteger.ONE);

            r = KK.multiply(r).add(p);
        }

       return r;
    }

    static BigInteger start(int K, int C) {
        BigInteger KK = BigInteger.valueOf(K);
        BigInteger CC = BigInteger.valueOf(C);

        BigInteger pos = BigInteger.ZERO;
        BigInteger d = BigInteger.ZERO;
        for (int i = 2; i <= C; i++) {
            d = d.add(BigInteger.ONE);
            if (d.compareTo(KK) >= 0)
                d = KK.subtract(BigInteger.ONE);
            pos = pos.multiply(KK).add(d);
        }
        pos = pos.add(BigInteger.ONE);

       return pos;
    }
}
