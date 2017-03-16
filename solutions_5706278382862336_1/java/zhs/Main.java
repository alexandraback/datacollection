
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author zhs
 */
public class Main {

    private static long gcd(long a, long b) {
        if (a > b) {
            return gcd(b, a);
        }
        if (b % a == 0) {
            return a;
        }
        return gcd(b % a, a);
    }

    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream(
                "/home/zhs/file/code/codejam/20140511/A-large.in"));
        System.setOut(new PrintStream(
                "/home/zhs/file/code/codejam/20140511/A-large.out"));
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int cs = 1; cs <= t; cs++) {
            System.out.print("Case #" + cs + ": ");
            String s = scanner.next();
            int index = s.indexOf('/');
            long a = Long.parseLong(s.substring(0, index));
            long b = Long.parseLong(s.substring(index + 1));
            long gcd = gcd(a, b);
            a /= gcd;
            b /= gcd;
            long r = Long.highestOneBit(b);
            while (r <= (1L << 40) && r % b != 0) {
                r <<= 1;
            }
            if (r <= (1L << 40)) {
                a *= (r / b);
                r /= Long.highestOneBit(a);
                System.out.println(Long.numberOfTrailingZeros(r));
            } else {
                System.out.println("impossible");
            }
        }
    }
}
