import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.math.BigInteger;
import java.util.*;

public class Task1 {
    private static final String TASK = "Task1";

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();
        Locale.setDefault(Locale.US);

        InputStream in = System.in;
        if (args.length > 0) in = new FileInputStream(args[0]);

        try (Scanner s = new Scanner(in)) {
            int t = s.nextInt();
            for (int i = 0; i < t; i++) {
                String[] fraction = s.next().split("/");

                String result = solve(Long.valueOf(fraction[0]), Long.valueOf(fraction[1]));

                sb.append("Case #").append(i+1).append(": ").append(result).append("\n");
            }
        }

        try (FileWriter f = new FileWriter("CodeJam2014_Round1C/src/" + TASK + "_results.txt")) {
            f.write(sb.toString());
        }
    }

    private static String solve(Long p, Long q) {
        long gcd = gcd(p, q);

        return solveA(p/gcd, q/gcd);
    }

    private static String solveA(long p, long q) {
        long result = log2(q);
        if (result == -1) return "impossible";

        if (p > 1) result -= log21(p - p % 2);

        return "" + result;
    }

    private static long log21(long l) {
        if (l == 1) return 0;

        return 1 + log21(l/2);
    }

    public static long gcd(long a, long b) { return b==0 ? a : gcd(b, a%b); }
    public static long log2(long n) {
        int k = 1;
        int l = 0;
        while (k < n && k <= Long.MAX_VALUE / 2) {
            k = k << 1;
            l++;
        }

        if (k == n) return l;
        return -1;
    }
}
