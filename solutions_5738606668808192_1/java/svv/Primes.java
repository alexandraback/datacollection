package codejam.year2016.qualification.coinjam;

import java.math.BigInteger;
import java.util.BitSet;
import java.util.LinkedHashSet;
import java.util.Set;

public class Primes {

    private static final int MAX = 1_000_000;

    private static final Set<Integer> PRIMES = new LinkedHashSet<>();

    static {
        BitSet bs = new BitSet(MAX);
        int c = 2;
        while (c < MAX) {
            while (c < MAX && bs.get(c)) {
                c++;
            }
            PRIMES.add(c);
            for (int j = c; j < MAX; j += c) {
                bs.set(j);
            }
        }
    }


    public long divisor(BigInteger a) {
        long v = (long) (Math.sqrt(a.doubleValue()));

        for (long t : PRIMES) {
            if (t > v) break;

            BigInteger tt = BigInteger.valueOf(t);
            if (a.equals(tt)) continue;

            if (a.remainder(tt).equals(BigInteger.ZERO)) {
                return t;
            }
        }
        return 0;
    }

}
