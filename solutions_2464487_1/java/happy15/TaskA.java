import java.math.BigInteger;
import java.util.Scanner;

public class TaskA {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numTests = in.nextInt();

        for (int testId = 1; testId <= numTests; ++testId) {
            System.out.print("Case #" + testId + ": ");

            long r = in.nextLong();
            long t = in.nextLong();
            long lb = 1;
            long rb = 1500000000;
            BigInteger tt = BigInteger.valueOf(t);
            while (lb <= rb) {
                long mid = (lb + rb) / 2;
                BigInteger x = BigInteger.valueOf(2 * r + 1 + 2 * mid);
                BigInteger y = BigInteger.valueOf(mid + 1);
                if (x.multiply(y).compareTo(tt) <= 0) {
                    lb = mid + 1;
                } else {
                    rb = mid - 1;
                }
            }
            System.out.println(lb);
        }
    }
}
