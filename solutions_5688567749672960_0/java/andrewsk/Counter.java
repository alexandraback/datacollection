import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Counter {

    public static Map<Long, Long> memo = new HashMap<Long, Long>();

    public static void main(String[] args) {
        for (long i = 1; i <= 11; i++) {
            memo.put(i, i);
        }

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            long n = sc.nextLong();
            long res = getRes(n);
            System.out.println("Case #" + (i + 1) + ": " + res);
        }
    }

    private static long getRes(long n) {
        if (memo.containsKey(n)) {
            return memo.get(n);
        }
        long prev = getRes(n - 1);
        long flipn = flip(n);
        long flip;
        if (n % 10 == 0 || n <= flipn) {
            memo.put(n, prev + 1);
            return prev + 1;
        } else {
            flip = getRes(flipn);
            long min = Math.min(flip, prev);
            memo.put(n, min + 1);
            return min + 1;
        }
    }

    private static long flip(long input_long) {
        long reversedNum = 0;

        while (input_long != 0) {
            reversedNum = reversedNum * 10 + input_long % 10;
            input_long = input_long / 10;
        }

        return reversedNum;
    }
}
