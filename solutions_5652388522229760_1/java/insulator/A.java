package Qualification2016;

import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int T = sc.nextInt();
        for (int testCase = 1; testCase <= T; ++testCase) {
            final int n = sc.nextInt();
            System.out.printf("Case #%d: ", testCase);
            if (n > 0) {
                long x = 0;
                int unmarked = 10;
                boolean seen[] = new boolean[10];
                do {
                    x += n;
                    long res = x;
                    while (res > 0) {
                        int digit = (int) (res % 10);
                        res /= 10;
                        if (!seen[digit]) {
                            --unmarked;
                            seen[digit] = true;
                        }
                    }
                } while (unmarked > 0);
                System.out.println(x);
            } else {
                System.out.println("INSOMNIA");
            }
        }
    }
}