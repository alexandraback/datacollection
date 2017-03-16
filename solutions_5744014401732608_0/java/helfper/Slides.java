import java.util.Scanner;

/**
 * Created by helfper on 08/05/16.
 */
public class Slides {
    private final static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();

        for (int i = 1; i <= t; i++) {
            solve(i);
        }
    }

    private static void solve(int tc) {
        int b = sc.nextInt();
        long m = sc.nextLong();

        long ways = (long) (b - 1) * (b - 2) / 2 + 1;

        System.out.printf("Case #%d: %s\n", tc, m > ways ? "IMPOSSIBLE" : "POSSIBLE");
        if (m <= ways) {
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < b; j++) {
                    if (j == i + 1) {
                        System.out.print("1");
                    } else if (j <= i || m <= 1) {
                        System.out.print("0");
                    } else {
                        System.out.print("1");
                        m--;
                    }
                }
                System.out.println();
            }
        }
    }
}
