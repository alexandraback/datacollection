import java.math.BigInteger;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;

public class C
{
    private static BigInteger pollard_rho(BigInteger n)
    {
        int i = 0, k = 2;
        BigInteger x = BigInteger.valueOf(42), y = BigInteger.valueOf(3);
        while (i < 100000) {
            i ++;
            x = x.multiply(x).mod(n).add(n).subtract(BigInteger.ONE).mod(n);
            BigInteger d = y.subtract(x).abs().gcd(n);
            if (!d.equals(BigInteger.ONE) && !d.equals(n)) return d;
            if(i == k) {
                y = x;
                k *= 2;
            }
        }
        return BigInteger.ZERO;
    }
	public static void main(String args[])
	{
        int T, N, J;
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        N = sc.nextInt();
        J = sc.nextInt();

        System.out.println("Case #1:");
        HashSet<String> used = new HashSet<>();
        Random rng = new Random(1337);
        for(int i = 0; i < J; ++i) {
            outer: while(true) {
                StringBuilder sb = new StringBuilder();
                sb.append('1');
                for(int j = 0; j < N-2; ++j) {
                    if (rng.nextBoolean())
                        sb.append('0');
                    else
                        sb.append('1');
                }
                sb.append('1');
                String str = sb.toString();
                if(used.contains(str))
                    continue;
                used.add(str);
                for(int b = 2; b <= 10; ++b) {
                    BigInteger bi = new BigInteger(str, b);
                    if(bi.isProbablePrime(100))
                        continue outer;
                }
                String out = str;
                for(int b = 2; b <= 10; ++b) {
                    BigInteger bi = new BigInteger(str, b);
                    BigInteger pr = pollard_rho(bi);
                    out += " " + pr;
                    if(pr.equals(BigInteger.ZERO))
                        continue outer;
                }
                System.out.println(out);
                break;
            }
        }
	}
}
