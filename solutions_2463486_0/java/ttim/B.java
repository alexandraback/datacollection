package ru.abishev.qual;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
    public static void run(Scanner input, PrintWriter output) {
        int t = input.nextInt();
        for (int _t = 0; _t < t; _t++) {
            int a = input.nextInt();
            int b = input.nextInt();
            int ans = 0;
            for (int i = a; i <= b; i++) {
                if (isOk(i)) {
                    ans++;
                }
            }
            output.println("Case #" + (_t + 1) + ": " + ans);
        }
        output.flush();
    }

    private static boolean isPol(int val) {
        String s = String.valueOf(val);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    private static boolean isOk(int val) {
        if (!isPol(val)) {
            return false;
        }
        int sq = (int) Math.sqrt(val);
        for (int posSq = Math.max(1, sq - 2); posSq <= sq + 2; posSq++) {
            if (posSq * posSq == val) {
                return isPol(posSq);
            }
        }
        return false;
    }

    public static void main(String[] args) throws FileNotFoundException {
//        run(new Scanner(System.in), new PrintWriter(System.out));

        PrintWriter output = new PrintWriter(new FileOutputStream("./C-small-attempt0.out"));
        run(new Scanner(new FileInputStream("./C-small-attempt0.in")), output);
        output.close();
    }
}
