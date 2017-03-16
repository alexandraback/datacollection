import java.util.Scanner;

/**
 * Created by poly on 4/18/15.
 */
public class CounterCulture {
    static long lpow(final long n, final int i) {
        long res = 1;
        int j = 0;
        while (j++ < i) {
            res *= n;
        }
        return res;
    }

    static String repeat(final String s, final int i) {
        StringBuilder sb = new StringBuilder();
        int j = 0;
        while (j++ < i) {
            sb.append(s);
        }
        return sb.toString();
    }

    public static void main(String argv[]) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            long n = scanner.nextLong();
            if (n < 21) {
                System.out.println("Case #" + (t + 1) + ": " + n);
                continue;
            }
            int rank = String.valueOf(n).length();
            long ans = 9;
            for (int i = 2; i <= rank; i++) {
                long target = lpow(10, i) - 1;
                long start = lpow(10, i - 1) - 1;
                if (i == rank) {
                    target = n;
                }
//                System.out.println("target=" + target + ", start=" + start);
                String s = String.valueOf(target);
                String firstS = s.substring(0, (i + 1) / 2) + repeat("0", (i / 2) - 1) + "1";
                long second = Long.valueOf(firstS);
                if (second > target) {
                    firstS = String.valueOf(target - 1).substring(0, (i + 1) / 2) + repeat("0", (i / 2) - 1) + "1";
                    if (firstS.length() == rank) {
                        second = Long.valueOf(firstS);
                    }
                }
                firstS = new StringBuilder(firstS).reverse().toString();
                long first = Long.valueOf(firstS);
//                System.out.println(first + ":" + second);
                long tmp = 0;
                if ((second <= first) || (second > target || target <= first)) {
                    tmp = target - start;
                } else {
                    tmp = (target - second) + 1 + (first - start);
                }
//                System.out.println("tmp=" + tmp);
                ans += tmp;
            }
            System.out.println("Case #" + (t + 1) + ": " + ans);
        }
    }
}
