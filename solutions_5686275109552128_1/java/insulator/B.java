package Qualification2015;

import java.util.Arrays;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int testCase = 1; testCase <= T; ++testCase) {
            int d = sc.nextInt();
            int[] p = new int[d];
            for (int i = 0; i < d; ++i)
                p[i] = sc.nextInt();
            int best = Integer.MAX_VALUE;
            for (int top = 1; top <= 1000; ++top) {
                int current = 0;
                for (int i = 0;i < d; ++i)
                    current += (p[i] - 1) / top;
                current += top;
                best = Math.min(best, current);
            }
            System.out.printf("Case #%d: %d\n", testCase, best);
        }
    }
}