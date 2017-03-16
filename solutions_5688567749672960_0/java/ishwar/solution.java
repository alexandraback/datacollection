package com.example;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

import static java.util.Arrays.deepToString;

public class solution {
    static PrintWriter out = null;
    static FileInputStream in = null;
    Scanner sc;

    Long A, B, K;

    void read() {
        A = Long.valueOf(sc.next());
    }

    int len(float a) {
        int len = 0;
        while (a >= 1) {
            len++;
            a /= 10;
        }
        return len;
    }

    long pelin(long number) {
        long temp, reversedNumber = 0;
        while (number > 0) {
            temp = number % 10;
            number = number / 10;
            reversedNumber = reversedNumber * 10 + temp;
        }
        return reversedNumber;
    }

    void solve() {
        int digits = len(A);
        long solution = 0;

        while (digits > 1) {
            long devide = (long) Math.pow(10, digits / 2);
            long mod = A % devide - 1;
            if (mod < 0) {
                mod = devide - 1;
            }
            solution += mod;
            A -= mod;
            if (A == pelin(A)) {
                if (digits <= 2) {
                    break;
                }
            } else {
                A = pelin(A);
                solution++;
            }

            if (digits % 2 == 1) {
                devide *= 10;
            }
            mod = A % devide + 1;
            solution += mod;
            A -= mod;
            digits = len(A);
        }

        output(solution + A);
    }

    void output(Long a) {
        out.println(a);
        System.out.println(a);
    }

    void run() {
        try {
            in = new FileInputStream("src/com/resources/smallInput.txt");
            out = new PrintWriter("src/com/resources/output.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        sc = new Scanner(in);
        int caseN = sc.nextInt();
        for (int caseID = 1; caseID <= caseN; caseID++) {
            read();
            out.printf("Case #%d: ", caseID);
            System.out.printf("Case #%d: ", caseID);
            solve();
            System.out.flush();
        }
        out.close();
    }

    void debug(Object... os) {
        System.err.println(deepToString(os));
    }

    public static void main(String[] args) {
        try {
            System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : (solution.class.getName() + ".in"))));
        } catch (Exception e) {
        }
        new solution().run();
    }

    private static long gcd(long a, long b) {
        while (b > 0) {
            long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }
}
