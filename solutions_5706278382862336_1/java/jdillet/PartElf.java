import java.io.IOException;
import java.math.BigInteger;
import java.util.Locale;
import java.util.Scanner;

public class PartElf {

    private void processInput() throws IOException {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();

        for (int testCase = 1; testCase <= T; testCase++) {
            String str = in.next();
            String[] sp = str.split("/");
            long P = Long.valueOf(sp[0]);
            long Q = Long.valueOf(sp[1]);

            String res = go(P, Q);

            System.out.printf(Locale.ENGLISH, "Case #%d: %s\n", testCase, res);         
        }

        in.close();
    }

    private String go(long P, long Q) {
        long gcd = gcd(P, Q);
        long p = P / gcd;
        long q = Q / gcd;
        
        BigInteger bp = BigInteger.valueOf(p);
        BigInteger bq = BigInteger.valueOf(q);
        
        for (int i = 1; i <= 40; i++) {
            if (q == (1<<i)) {
                
                for (int j = 1; j <= 40; j++) {
                    BigInteger sh = BigInteger.valueOf(2).pow(j);
                    BigInteger mult = sh.multiply(bp);
                    if (bq.compareTo(mult) <= 0) {
                        return String.valueOf(j);
                    }
                }
                return "40";
            }
        }
        
        return "impossible";
    }

    public long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    
    public long lcm(long a, long b) {
        return b * a / gcd(a, b);
    }

    public static void main(String[] args) throws Exception {
        PartElf main = new PartElf();
        main.processInput();
    }
}
