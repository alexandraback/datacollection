package codejam2016.counting_sheep;

import java.util.Scanner;

public class Sheep {

    private static int numberBeforeSleep(int n) {
        if (n == 0) return 0;
        boolean[] set = new boolean[10];
        int k = 0;
        for (int seen = 0; seen < 10; ) {
            k += n;
            for (int x = k; x > 0; x /= 10) {
                int digit = x % 10;
                if (!set[digit]) {
                    seen++;
                    set[digit] = true;
                }
            }
        }
        return k;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; ++i) {
            int n = sc.nextInt();
            int x = numberBeforeSleep(n);
            if (x == 0)
                System.out.printf("Case #%d: INSOMNIA\n", i + 1);
            else
                System.out.printf("Case #%d: %d\n", i + 1, x);
        }
    }
}
