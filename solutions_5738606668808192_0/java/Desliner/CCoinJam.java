package codejam.y2016.qualification;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Max Myslyvtsev
 * @since 4/8/16
 */
public class CCoinJam {

    private static final List<BigInteger> PRIMES;
    static {
        PRIMES = new ArrayList<>();
        int limit = 10000;
        boolean[] q = new boolean[limit+1];
        for (int i = 2; i <= limit; i++) {
            if (!q[i]) {
                PRIMES.add(BigInteger.valueOf(i));
                for (long j = 2*i; j <= limit; j+=i) {
                    q[(int)j] = true;
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        //Scanner in = new Scanner(new FileInputStream("/Users/max/Work/Source/foobar/src/main/resources/input.txt"));
        Scanner in = new Scanner(new FileInputStream("/Users/max/Downloads/C-small-attempt1.in"));
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            int J = in.nextInt();
            String a = solve(N, J);
            String answ = "Case #" + t + ":\n" + a;
            out.println(answ);
            System.out.println(answ);
        }
        out.close();
    }

    private static String solve(int N, int J) {
        BigInteger q = BigInteger.ONE.shiftLeft(N-1).add(BigInteger.ONE);
        int found = 0;
        BigInteger two = BigInteger.valueOf(2);
        StringBuilder sb = new StringBuilder();
        while (found < J) {
            String v = verify(q);
            if (v != null) {
                found++;
                sb.append(q.toString(2)).append(" ").append(v).append("\n");
            }
            q = q.add(two);
        }
        return sb.toString();
    }

    private static String witness(BigInteger x) {
        for (BigInteger p : PRIMES) {
            if (x.mod(p).equals(BigInteger.ZERO)) {
                return String.valueOf(p);
            }
        }
        return null;
    }

    private static String verify(BigInteger x) {
        String w = witness(x);
        if (w == null) {
            return null;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(w);
        String s = x.toString(2);
        for (int b = 3; b <= 10; b++) {
            BigInteger q = new BigInteger(s, b);
            w = witness(q);
            if (w == null) {
                return null;
            }
            sb.append(" ").append(w);
        }
        return sb.toString();
    }
}
