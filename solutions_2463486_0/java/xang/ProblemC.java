package com.forthgo.contest.g2013r0;

import com.forthgo.math.Helper;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class ProblemC {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("C.in"));
            PrintWriter out = new PrintWriter(new FileWriter("C.out"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                out.printf("Case #%d: ", i + 1);
                solve(in, out);
                out.println();
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    private static void solve(Scanner in, PrintWriter out) {
        long a = in.nextLong();
        long b = in.nextLong();
        long sa = Helper.sqrt(a);
        long sb = Helper.sqrt(b);
        long count = 0;
        int na = Helper.countDigits(sa) / 2;
        int nb = Helper.countDigits(sb) / 2;
        for (int n = na; n <= nb; n++) {
            long nn = Helper.ipow(10, n);
            long x0 = n == 0 ? 0 : Helper.ipow(10, n - 1);
            long x1 = Helper.ipow(10, n) - 1;
            for (long x = x0; x <= x1; x++) {
                long y = Helper.reverse(x);
                long p = x * nn + y;
                long pp = p * p;
                if (pp > b)
                    break;
                if (pp >= a && Helper.isPalindrome(pp)) {
//                    System.out.printf("%21d = %11d * %11d%n", pp, p, p);
                    count++;
                }
                for (int i = 0; i <= 9; i++) {
                    p = (x * 10 + i) * nn + y;
                    pp = p * p;
                    if (pp > b)
                        break;
                    if (pp >= a && Helper.isPalindrome(pp)) {
//                        System.out.printf("%21d = %11d * %11d%n", pp, p, p);
                        count++;
                    }
                }
            }
        }
        out.print(count);
    }


}

