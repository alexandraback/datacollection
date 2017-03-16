import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class C {
    // SieveOfEratosthenes
    public static class Prime { // {{{
        public static final int LIMIT = (int) Math.sqrt(Integer.MAX_VALUE);
        public static BitSet prime;
        public static List<BigInteger> list; // list contains the primes less than or equal to LIMIT

        static {
            int halfLimit = LIMIT>>1;
            int sqrtLimit = (int) Math.sqrt(LIMIT);

            prime = new BitSet(halfLimit);
            prime.set(0, prime.size(), true);

            prime.clear(0);
            for (int num=3; num<=sqrtLimit; num+=2) {
                if (!prime.get(num>>>1)) continue;
                for (int factor=num*num, inc=num<<1; factor<=LIMIT; factor+=inc) {
                    prime.clear(factor>>>1);
                }
            }

            list = new ArrayList<>(4792);
            list.add(BigInteger.valueOf(2));
            for (int i = 1; i < halfLimit; i++) {
                if (!prime.get(i)) continue;
                list.add(BigInteger.valueOf((i<<1)+1));
            }
        }
    } // }}}

    void solve(int caseNum) {
        Random random = new Random();
        int n = in.nextInt();
        int j = in.nextInt();

        StringBuilder buf = new StringBuilder("\n");
        Set<String> visited = new HashSet<>();
l1:
        for (int i=0; i<j; ) {
            String s = String.format("1%"+(n-2)+"s1", new BigInteger(n-2, random).toString(2)).replaceAll(" ", "0");
            if (visited.contains(s)) continue;
            visited.add(s);

            List<BigInteger> divisors = new ArrayList<>();
l2:
            for (int r=2; r<=10; r++) {
                BigInteger t = new BigInteger(s, r);
                for (BigInteger p: Prime.list) {
                    if (t.mod(p).equals(BigInteger.ZERO)) {
                        divisors.add(p);
                        continue l2;
                    }
                }
                continue l1;
            }
            i++;
            buf.append(s);
            for (BigInteger d: divisors) buf.append(" ").append(d);
            buf.append("\n");
        }
        out.println(buf);
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public C() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new C();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
