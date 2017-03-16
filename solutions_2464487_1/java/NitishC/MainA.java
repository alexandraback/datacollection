import java.math.BigInteger;
import java.util.Scanner;

public class MainA {
    public static BigInteger Btwo=new BigInteger(String.valueOf(2));

    public static BigInteger getVal(BigInteger Bc,BigInteger Bsub){
        BigInteger out=Bc.multiply(Bsub);
        BigInteger sum=Bc.multiply(Bc.subtract(BigInteger.ONE)).multiply(Btwo);
        return out.add(sum);
    }

    public static BigInteger getResult(BigInteger t1, BigInteger sub) {
        BigInteger min= BigInteger.ONE;
        BigInteger max=t1.divide(sub);
        while (min.compareTo(max)<=0) {
            BigInteger mid = min.add(max).divide(Btwo);
            BigInteger val = getVal(mid, sub);
            BigInteger nextVal = getVal(mid.add(BigInteger.ONE), sub);
            if (t1.compareTo(val) >= 0 && t1.compareTo(nextVal)<0) {
                return mid;
            } else if (t1.compareTo(val)<0) {
                max = mid.subtract(BigInteger.ONE);
            } else {
                min = mid.add(BigInteger.ONE);
            }
        }
        return BigInteger.ZERO;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        for (int t = 1; t <= T; t++) {
            BigInteger r = sc.nextBigInteger();
            BigInteger t1 = sc.nextBigInteger();
            BigInteger sub = r.multiply(Btwo).add(BigInteger.ONE);
            BigInteger output = getResult(t1, sub);
            System.out.println("Case #" + t + ": " + output);
        }
    }
}
