package codejam.y2016.qualification;

import lib.FastScanner;

import java.io.*;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * @author Max Myslyvtsev
 * @since 4/8/16
 */
public class ACountingSheep {

    public static void main(String[] args) throws Exception {
        //FastScanner in = new FastScanner("/Users/max/Work/Source/foobar/src/main/resources/input.txt");
        FastScanner in = new FastScanner("/Users/max/Downloads/A-small-attempt0.in");
        PrintStream out = new PrintStream(new FileOutputStream("/Users/max/Work/Source/foobar/src/main/resources/output.txt"));
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            Integer a = solve(N);
            String answ = "Case #"+t+": " + (a != null ? a.toString() : "INSOMNIA");
            out.println(answ);
            System.out.println(answ);
        }
    }

    private static Integer solve(int N) {
        if (N == 0) {
            return null;
        }
        Set<Character> digits = new HashSet<>();
        for (int i = 1; ; i++) {
            int q = N * i;
            String s = String.valueOf(q);
            for (char ch : s.toCharArray()) {
                digits.add(ch);
            }
            if (digits.size() == 10) {
                return q;
            }
        }
    }
}
