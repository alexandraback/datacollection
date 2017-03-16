import java.io.File;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

/**
 * @author Alexander Gulko
 */
public class ProblemA {
    @SuppressWarnings("FieldCanBeLocal")
    private static int caseNumber;
    private static Scanner scan;

    long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }

        return gcd(b, a % b);
    }

    void solve() {
        String[] s = scan.next().split("/");
        long p = Long.parseLong(s[0]);
        long q = Long.parseLong(s[1]);

        long gcd = gcd(p, q);
        p /= gcd;
        q /= gcd;

        long pow2 = Long.highestOneBit(q);
        if (pow2 != q || (pow2 > (1L << 41)))  {
            System.out.printf("%s\n", "impossible");
            return;
        }

        long h = Long.highestOneBit(p);

        int res = 0;
        while (q > h) {
            q >>>= 1;
            ++res;
        }

        System.out.printf("%s\n", res);
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

//        String file = "test-a";
        String file = "A-small-attempt0";

        redirectToFile(file);

        String inFile = file + ".in";
        scan = new Scanner(new File(inFile));

        int cases = scan.nextInt();
        for (caseNumber = 1; caseNumber <= cases; ++caseNumber) {
            System.out.printf("Case #%s: ", caseNumber);
            new ProblemA().solve();
            System.out.flush();
        }

        scan.close();
    }

    static void redirectToFile(String file) throws Exception {
        System.setOut(new PrintStream(file + ".out"));
    }
}
