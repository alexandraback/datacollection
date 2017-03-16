import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Elf {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new FileInputStream("A-large.in"));
        PrintStream out = new PrintStream(new FileOutputStream("A-large.out"));
//        PrintStream out = new PrintStream(System.out);
        int nTests = scanner.nextInt();
        scanner.nextLine();
        for (int test = 1; test <= nTests; test++) {
            String[] s = scanner.nextLine().split("\\/");
//            System.out.printf("%d/%d\n", p, q);
            BigInteger pp = new BigInteger(s[0]);
            BigInteger qq = new BigInteger(s[1]);
            final BigInteger gcd1 = pp.gcd(qq);
            pp = pp.divide(gcd1);
            qq = qq.divide(gcd1);
            if (qq.bitCount() != 1) {
                out.printf("Case #%d: impossible\n", test);
                continue;
            }

            final int bitCount = qq.getLowestSetBit();
            do {
                final int lowestSetBit = pp.getLowestSetBit();
                final BigInteger bit = BigInteger.ONE.shiftLeft(lowestSetBit);
                if (bit.equals(pp)) {
                    out.printf("Case #%d: %d\n", test, bitCount - lowestSetBit);
                    break;
                }
                pp = pp.xor(bit);
            } while (true);
        }
        out.close();
    }
}
