import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemC {

    public static void main(String[] args) throws Exception {
//        Scanner in = new Scanner(System.in);
//        PrintStream out = System.out;
        Scanner in = new Scanner(new File("C.in"));
        PrintStream out = new PrintStream("C.out");
        int TOTAL_TESTS = in.nextInt(); // always "1"
        out.println("Case #" + TOTAL_TESTS + ":");
        int n = in.nextInt();
        int j = in.nextInt();

        long[] divisors = new long[9];

        NUMBER:
        for (int i = 0; i < 1 << (n - 2); i++) {
            String number = "1" + toBinaryString(i, n - 2) + "1";
            for (int base = 2; base <= 10; base++) {
                long div = getDivisor(number, base);
                if (div < 0) continue NUMBER; // is prime in base "base"
                divisors[base - 2] = div;
            }

            out.print(number);
            for (long divisor : divisors) {
                out.print(" " + divisor);
            }
            out.println();
            j--;
            if (j == 0) break;
        }
    }

    private static String toBinaryString(int x, int length) {
        String s = Integer.toBinaryString(x);
        while (s.length() < length) {
            s = "0" + s;
        }
        return s;
    }

    private static long getDivisor(String number, int base) {
        long x = Long.parseLong(number, base);
        if ((x & 1) == 0) return 2;
        long sqrt = (long) Math.sqrt(x);
        for (long i = 3; i <= sqrt; i += 2) {
            if (x % i == 0) return i;
        }
        return -1;
    }

}
