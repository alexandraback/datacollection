package qulifying;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.lang.Math.*;

/**
 * Created with longelliJ IDEA.
 * User: raggzy
 * Date: 13.04.13
 * Time: 3:33
 * To change this template use File | Settings | File Templates.
 */
public class ProblemC {

    private static boolean isPalindrome(long x) {
        String str = String.valueOf(x);
        for (int i = 0; i < str.length() / 2; i++) {
            if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    private static List<Long> precalculate() {
        List<Long> result = new ArrayList<Long>();
        for (long x = 1; x <= 10000000; x++) {
            if (isPalindrome(x) && isPalindrome(x * x)) {
                result.add(x * x);
            }
        }
        return result;
    }

    private static int count(List<Long> numbers, long from, long to) {
        int result = 0;
        for (long number : numbers) {
            if (from <= number && number <= to) {
                result++;
            }
        }
        return result;
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("C:/Temp/gcj/c-in.txt"));
        PrintStream out = new PrintStream(new FileOutputStream("C:/Temp/gcj/c-out.txt"));
        List<Long> good = precalculate();
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            long A = in.nextLong();
            long B = in.nextLong();
            out.println(String.format("Case #%d: %d", i + 1, count(good, A, B)));
        }
        in.close();
        out.close();

    }
}
