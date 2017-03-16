import java.util.*;
import java.math.BigInteger;

class C {
    static int T, N, J;
    static final BigInteger LIMIT = new BigInteger("10");

    static BigInteger[] primes;
    static int nbPrimes;

    static void genPrimes() {
        HashMap<BigInteger, Boolean> isPrime = new HashMap<BigInteger, Boolean>();
        for(BigInteger i = new BigInteger("2"); i.compareTo(LIMIT) <= 0; i = i.add(BigInteger.ONE))
            isPrime.put(i, true);

        for(BigInteger i = new BigInteger("2"); i.multiply(i).compareTo(LIMIT) <= 0; i = i.add(BigInteger.ONE))
            if(isPrime.get(i)) 
                for(BigInteger j = new BigInteger(i.toString()); i.multiply(j).compareTo(LIMIT) <= 0; j = j.add(BigInteger.ONE))
                    isPrime.put(i.multiply(j), false);

        primes = new BigInteger[6000000];
        nbPrimes = 0;
        for(BigInteger i = new BigInteger("2"); i.compareTo(LIMIT) <= 0; i = i.add(BigInteger.ONE))
            if(isPrime.get(i))
                primes[nbPrimes++] = i;
    }

    static BigInteger divisor(BigInteger n) {
        for(int i = 0; i < nbPrimes; ++i) 
            if(n.mod(primes[i]) == BigInteger.ZERO)
                return primes[i];
        return null;
    }

    static BigInteger toBase10(String s, BigInteger b) {
        BigInteger n = new BigInteger("0"), m = new BigInteger("1");
        for(int i = 0; i < s.length(); ++i) {
            n = n.add(m.multiply(new BigInteger("" + s.charAt(i))));
            m = m.multiply(b);
        }
        return n;
    }

    static void completeSearch(String s) {
        if(J == 0) return;
        else if(s.length() == N-2) {
            String S = '1' + s + '1';
            // System.out.println(S);
            ArrayList<BigInteger> divs = new ArrayList<BigInteger>();
            for(BigInteger b = new BigInteger("2"); b.compareTo(BigInteger.TEN) <= 0; b = b.add(BigInteger.ONE)) {
                // System.out.println(toBase10(S, b));
                BigInteger d = divisor(toBase10(S, b));
                if(d == null)
                    return;
                divs.add(d);
            }

            System.out.print(new StringBuilder(S).reverse());
            for(BigInteger d : divs)
                System.out.print(" " + d);
            System.out.println();
            --J;
        } else {
            completeSearch(s + '1');
            completeSearch(s + '0');
        }
    }

    public static void main(String[] args) {
        genPrimes();
        // System.out.println(nbPrimes);

        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 0; t < T; ++t) {
            System.out.printf("Case #%d:\n", t+1);
            N = sc.nextInt();
            J = sc.nextInt();

            completeSearch("");
        }
    }
}

