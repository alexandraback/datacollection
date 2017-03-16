import java.math.BigInteger;
import java.util.Scanner;


public class GCJ2013Round1A {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: %d%n", i, new GCJ2013Round1A().solve(sc));
        }
    }
    
 // amount(n) = (r+2n-1)^2 - (r+2n-2)^2
//  = 2r(2n-1) +(2n-1)^2 - 2r(2n-2) - (2n-2)^2 
//  = 2r - 4n + 1 + 8n - 4
//  = 2r + 4n - 3
//S(n) = Σ{k=1..n}{2r + 4k - 3}
//= 2rn + 2n(n+1) - 3n
//= 2rn + 2n^2 - n
//<= t
//r>=1, not decreasing
//2rn + 2n^2 - n - t <= 0
//n^2 + (r-1/2)n -t/2 <= 0
// omg eclipse is broken
    
    private long solve(Scanner sc) throws Exception {
        BigInteger r = sc.nextBigInteger();
        BigInteger t = sc.nextBigInteger();
        
        final BigInteger TWO = BigInteger.valueOf(2);

        BigInteger left = BigInteger.ZERO;
        BigInteger right = BigInteger.valueOf(Math.max(t.longValue(),10));
        while (left.compareTo(right) < 0) {
            BigInteger mid = left.add(right).add(BigInteger.ONE).divide(TWO);
            BigInteger mv = mid.multiply(TWO).multiply(r).add(mid.pow(2).multiply(TWO)).subtract(mid).subtract(t);
//            System.out.println("n: " + mid + ", val: " + mv);
            if (mv.signum() <= 0) left = mid;
            else right = mid.subtract(BigInteger.ONE);
        }

        return left.longValue();
    }

}
