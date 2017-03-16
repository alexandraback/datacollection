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
        Queue<String> steps = new LinkedList<>();
        steps.offer("1");
        Set<Long> vis = new HashSet<>();
        while (!queue.isEmpty()) {
            long number = queue.poll(), counter = queue.poll();
            String st = steps.poll();
            if (vis.add(number+1)) {
                if (number+1 == N) {
                    System.out.println(st);
                    return counter + 1;
                } else {
                    queue.offer(number+1);
                    queue.offer(counter+1);
                    steps.offer(st + ',' + (number+1));
                }
            }
            long rev = reverse(number);
            if (vis.add(rev)) {
                if (rev == N) {
                    System.out.println(st);
                    return counter+1;
                } else {
                    queue.offer(rev);
                    queue.offer(counter+1);
                    steps.offer(st + ',' + rev);
                }
            }
        }
        return 0;
    }

    private static long reverseNum(long num) {
        long res = 0;
        while (num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }

    private static long findCount(long A, long B) {
        long d = 10, min = B - A;
        while (d < B) {
            min = Math.min(reverseNum(B/d) + B % d, min);
            d *= 10;
        }
        return min;
    }

    private static long solve(Scanner in) {
        long N = in.nextLong();
        if (N <= 10) return N;
        long d = 10, count = 10;
        while (d*10 < N) {
            count += findCount(d, d*10-1) + 1;
            d *= 10;
        }
        if (d*10 == N) return count + findCount(d, d*10-1) + 1;
        if (N % d == 0) return count + findCount(d, N-1) + 1;
        return count + findCount(d, N);
    }

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new FileInputStream("in-large.txt"));
        PrintStream out = new PrintStream(new FileOutputStream("out.txt"));
//        PrintStream out = System.out;
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            out.printf("Case #%d: %d\n", i+1, solve(in));
        }
        out.close();
    }

}
