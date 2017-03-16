package r1c;

import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int ti = 1; ti <= t; ti++) {
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            int w = scanner.nextInt();
            int res = solve(r, c, w);
            System.out.printf("Case #%d: %d\n", ti, res);
        }
    }

    static int solve(int r, int c, int w) {
        int m = c / w;
        int ma = m * r;
        int b = c - (m - 1) * w;
        int k = b > w ? 0 : 1;
        return ma + w - k;
    }
}
