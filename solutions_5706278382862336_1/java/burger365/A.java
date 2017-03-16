import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by burger on 5/11/14.
 */
public class A {
    public String solve(long P, long Q) {
        long gcd = BigInteger.valueOf(P).gcd(BigInteger.valueOf(Q)).longValue();
        P /= gcd;
        Q /= gcd;

        if (P == 0 || (Q & (Q - 1)) != 0) return "impossible";
        long t = (1L << 40) / Q * P;
        for (int g = 1; g <= 40; g++) {
            if (t >= (1L << (40 - g)))
                return String.valueOf(g);
        }
        return "impossible";
    }

    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("large.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("answer.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);

        int T = in.nextInt();
        in.nextLine();
        for (int t = 1; t <= T; t++) {
            String[] strs = in.nextLine().split("/");
            long P = Long.parseLong(strs[0]);
            long Q = Long.parseLong(strs[1]);
            out.write("Case #" + t + ": " + new A().solve(P, Q) + "\n");
        }

        out.close();
    }
}
