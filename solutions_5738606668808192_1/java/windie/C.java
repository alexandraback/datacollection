/**
 * Created by linxy on 4/8/16.
 */
import java.math.BigInteger;
import java.util.*;

public class C {

    public static void search(long N, int J) {
        long start = (1L << (N - 1)) + 1;
        long end = (1L << N);
        Set<String> results = new HashSet<String>();
        Random r = new Random();
        System.out.println("Case #1:");
        while (results.size() < J) {
            long c = (long) (r.nextDouble() * (end - start)) + start;
            if (c % 2 == 0) {
                continue;
            }
            String str = Long.toBinaryString(c);
            if (results.contains(str)) {
                continue;
            }
            boolean find = true;
            for (int base = 2; base <= 10; base++) {
                BigInteger i = new BigInteger(str, base);
                if (i.isProbablePrime(50)) {
                    find = false;
                    break;
                }
            }
            if (find) {
                List<Integer> divisors = new ArrayList<Integer>();
                for (int base = 2; base <= 10; base++) {
                    BigInteger i = new BigInteger(str, base);
                    for (int div = 2; div <= 10000; div++) {
                        if (i.mod(BigInteger.valueOf(div)).equals(BigInteger.ZERO)) {
                            divisors.add(div);
                            break;
                        }
                    }
                }
                if (divisors.size() == 9) {
                    System.out.print(str);
                    for (int div : divisors) {
                        System.out.print(" " + div);
                    }
                    System.out.println();
                    results.add(str);
                }
            }
        }
    }

    public static void main(String[] args) {
        search(32, 500);
    }
}
