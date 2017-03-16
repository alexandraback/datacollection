import java.math.BigInteger;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            BigInteger r = new BigInteger(sc.next());
            long t = sc.nextLong();

            long low = 1;
            long high = Integer.MAX_VALUE;

            while (low < high) {
                long mid = (low + high + 1) / 2;
                BigInteger m = new BigInteger(mid + "");
                if (m.multiply(r).multiply(new BigInteger("2")).add(m.multiply(m).multiply(new BigInteger("2"))).compareTo(new BigInteger((mid + t) + "")) <= 0) {
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }

            System.out.println("Case #" + caseNum + ": " + low);
        }
    }
}
