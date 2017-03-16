import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class C {

    public static void main(String[] args) throws IOException {

        Scanner sc = new Scanner(new File("C-small-attempt2.in"));
        FileWriter fw = new FileWriter(new File("c.out"));
        long n = sc.nextInt();
        for (long i = 1; i <= n; i++) {
            fw.append(String.format("Case #%d:\n%s", i, new C().solve(sc)));
        }
        fw.close();
        sc.close();

    }

    private static long isPrime(long i) {

        for (long j = 2; j * j <= i; j++) {
            if (i % j == 0) return j;
        }

        return 0;
    }

    private String solve(Scanner sc) {

        long n = sc.nextInt();
        long j = sc.nextInt();

        long from = (1 << (n - 1)) + 1;
        long to = 1 << n;

//        System.out.println(binToBase(0b1000000000110011, 2));
//        System.out.println(0b1000000000110011);

        StringBuilder sb = new StringBuilder();

        long i = 0;
        for (long t = from; t < to && i < j; t += 2) {

            long t2, t3, t4, t5, t6, t7, t8, t9, t10;
            if (
                    (t2 = isPrime(binToBase(t, 2))) != 0 &&
                            (t3 = isPrime(binToBase(t, 3))) != 0 &&
                            (t4 = isPrime(binToBase(t, 4))) != 0 &&
                            (t5 = isPrime(binToBase(t, 5))) != 0 &&
                            (t6 = isPrime(binToBase(t, 6))) != 0 &&
                            (t7 = isPrime(binToBase(t, 7))) != 0 &&
                            (t8 = isPrime(binToBase(t, 8))) != 0 &&
                            (t9 = isPrime(binToBase(t, 9))) != 0 &&
                            (t10 = isPrime(binToBase(t, 10))) != 0
                    ) {
                sb.append(Long.toBinaryString(t));
                sb.append(' ').append(t2)
                        .append(' ').append(t3)
                        .append(' ').append(t4)
                        .append(' ').append(t5)
                        .append(' ').append(t6)
                        .append(' ').append(t7)
                        .append(' ').append(t8)
                        .append(' ').append(t9)
                        .append(' ').append(t10);
                sb.append('\n');
                i++;
            }
        }

        return sb.toString();

    }

    private long binToBase(long bin, long base) {

        long result = 0;

        long i = 1;
        while (bin > 0) {
            long temp = bin % 2;
            bin /= 2;
            result += temp * i;
            i *= base;
        }

        return result;

    }

}
