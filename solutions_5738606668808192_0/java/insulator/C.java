package Qualification2016;

import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int testCase = 1; testCase <= T; ++testCase) {
            final int n = sc.nextInt();
            final int j = sc.nextInt(); //j, really?
            StringBuilder divisorBuilder = new StringBuilder();
            for (int base = 2; base <= 10; ++base) {
                long v = 1;
                for (int i = 0; i < n / 2; ++i) {
                    v *= base;
                }
                divisorBuilder.append(v + 1);
                if (base != 10) {
                    divisorBuilder.append(" ");
                }
            }
            final String divisors = divisorBuilder.toString();
            StringBuilder ans = new StringBuilder();
            int x = 1 << (n / 2 - 2);
            for (int i = 0; i < j; ++i) {
                ans.append(Integer.toBinaryString(2 * x + 1) + Integer.toBinaryString(2 * x + 1) + " ");
                ans.append(divisors);
                ans.append("\n");
                ++x;
            }
            System.out.printf("Case #%d:\n" + ans, testCase);
        }
    }
}