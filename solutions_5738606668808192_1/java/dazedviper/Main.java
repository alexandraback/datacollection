import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static long _sieve_size;
    static boolean[] bs = new boolean[10000010];
    static List<Long> primes;

    public static void main(String[] args) {
        //sieve(10000000);
        int N = 32; int J = 500;
        long a = 1L << N-1, b = (1L << N) - 1;
        for (long x = a+1; x <= b && J > 0; x += 2) {
            //if (x % 5 == 0) System.out.println(x);
            List<Long> divisors = new ArrayList<>();
            for (int k = 2; k <= 10; k++) {
                BigInteger y = tobasek(BigInteger.valueOf(x), k);
                if (y.isProbablePrime(100)) break;
                for (BigInteger d = BigInteger.valueOf(2); d.compareTo(y) == -1 && d.compareTo(BigInteger.valueOf(100000)) == -1 ; d = d.add(BigInteger.ONE)) {
                    if (y.mod(d).equals(BigInteger.ZERO)) {
                        divisors.add(Long.valueOf(d.toString()));
                        break;
                    }
                }
            }
            if (divisors.size() == 9) {
                System.out.print(Long.toBinaryString(x) + " ");
                /*for (int k = 2; k <= 10; k++) cout << tobasek(x, k) << " ";
                cout << endl;*/
                for (int i = 0; i < 8; i++) System.out.print(divisors.get(i) + " ");
                System.out.print(divisors.get(8));
                System.out.println();
                J--;
            }
        }
    }

    /*private static void sieve(long upperbound) {
        _sieve_size = upperbound + 1;
        for (int i = 0; i < 10000010; i++) bs[i] = true;
        bs[0] = false;
        bs[1] = false;
        for (int i = 2; i <= _sieve_size; i++)
            if (bs[i]) {
                for (long j = i*i; j <= _sieve_size; j += i) bs[j] = false;
                primes.add(new Long(i));
            }
    }*/

    static BigInteger tobasek(BigInteger x, int k) {
        BigInteger p = BigInteger.ONE;
        BigInteger ret = BigInteger.ZERO;
        while (x.compareTo(BigInteger.ZERO) == 1) {
            ret = ret.add(x.mod(BigInteger.valueOf(2)).multiply(p));
            x = x.divide(BigInteger.valueOf(2));
            p = p.multiply(BigInteger.valueOf(k));
        }
        return ret;
    }

}
