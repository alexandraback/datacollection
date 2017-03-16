import java.io.FileInputStream;
import java.util.Scanner;

/**
 * Created by ocozalp on 5/3/14.
 */
public class NewLotteryGame {
    public static void main(String [] args) throws Exception {
        Scanner sc = new Scanner(new FileInputStream("/home/ocozalp/Downloads/B-small-attempt0.in"));
        //Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int testCase = 1; testCase <= t; testCase++) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            long k = sc.nextLong();

            long res = calculate(a, b, k);

            System.out.println("Case #" + testCase + ": " + res);
        }
    }

    private static long calculate(long a, long b, long k) {
        int result = 0;
        for(int i = 0; i<a; i++) {
            for(int j = 0; j<b; j++) {
                int and = i & j;
                if(and >= 0 && and < k) {
                    result++;
                }
            }
        }

        return result;
    }
}
