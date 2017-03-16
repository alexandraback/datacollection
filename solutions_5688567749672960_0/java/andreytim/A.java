package com.andreytim.jafar.problems.googlecodejam.y2015.round1B;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

/**
 * Created by tim on 02/05/15.
 */
public class A {

    private static long reverse(long number) {
        return Long.valueOf(new StringBuilder(String.valueOf(number)).reverse().toString());
    }

    private static long solve2(Scanner in) {
        long N = in.nextLong();
        if (N == 1) return 1;
        Queue<Long> queue = new LinkedList<>();
        queue.offer(1L); queue.offer(1L);
        Set<Long> vis = new HashSet<>();
        while (!queue.isEmpty()) {
            long number = queue.poll(), counter = queue.poll();
            if (vis.add(number+1)) {
                if (number+1 == N) return counter+1;
                else {
                    queue.offer(number+1);
                    queue.offer(counter+1);
                }
            }
            long rev = reverse(number);
            if (vis.add(rev)) {
                if (rev == N) return counter+1;
                else {
                    queue.offer(rev);
                    queue.offer(counter+1);
                }
            }
        }
        return 0;
    }

    private static long solve(Scanner in) {
        long N = in.nextLong();
        if (N == 1) return 1;
        long d = 1, count = 0;
        while (d * 10 < N) {
            d *= 10;
            count += d / 10 + 9;
        }
        if (N == d * 10) {
            count += d + 9;
        } else if (N/d == 1) {
            count += N % d;
        } else if (N%10 >= 1) {
            count += N / d;
            count += N % d;
        } else {
            if (N/d > 2) count += N/d-1;
            count += d;
        }
        return count;
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileInputStream("in.txt"));
        PrintStream out = new PrintStream(new FileOutputStream("out2.txt"));
//        PrintStream out = System.out;
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            out.printf("Case #%d: %d\n", i+1, solve2(in));
        }
        out.close();
    }

}
