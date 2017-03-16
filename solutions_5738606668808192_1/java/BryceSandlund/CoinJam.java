import java.util.*;
import java.math.BigInteger;
import java.math.*;

public class CoinJam {

    private static BigInteger toBigI(int n) {
        return new BigInteger(Integer.toString(n));
    }

    private static BigInteger aToN(int a, int n) {
        return toBigI(a).pow(n);
    }

    private static long getFactor(BigInteger a) {
        int n_bits = Math.min(a.bitLength()/2, 25);
        BigInteger maximum = aToN(2, n_bits);
        long maxInt = maximum.longValue();
        
        //System.out.println(a + " " + maxInt);

        for (int i = 2; i < maxInt; ++i) {
            if (a.mod(toBigI(i)) == BigInteger.ZERO) {
            //    System.out.println(a + ": " + i);
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int T, N, J;
        Scanner in = new Scanner(System.in);

        T = in.nextInt();
        N = in.nextInt();
        J = in.nextInt();

        for (int cs = 1; cs <= T; ++cs) {
            System.out.println("Case #" + cs + ":");
            Random r = new Random(1);
            
            for (int iteration = 0; iteration < J; ++iteration) {
                boolean[] num = new boolean[N];
                num[0] = num[N-1] = true;

                for (int i = 1; i < N-1; ++i) {
                    num[i] = r.nextBoolean();
                }

                long[] factors = new long[9];
                
                boolean success = true;
TEST:
                for (int a = 2; a <= 10; ++a) {
                    BigInteger n = new BigInteger("0");

                    for (int i = 0; i < N; ++i) {
                        if (num[i]) {
                            n = n.add(aToN(a, i));
                        }
                    }

                    factors[a-2] = getFactor(n);
                    if (factors[a-2] == -1) {
                        --iteration;
                        success = false;
                        break TEST;
                    }
                }

                if (success) {
                    for (int i = N-1; i >= 0; --i) {
                        System.out.print(num[i] ? "1" : "0");
                    }

                    for (int i = 0; i < 9; ++i) {
                        System.out.print(" " + factors[i]);
                    }

                    System.out.println();
                }
            }
        }
    }

}
