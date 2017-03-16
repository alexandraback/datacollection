package codejamreg;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class FairSquare {

    private static long[] fairSquares = new long[40];

    public static void main(String[] args) throws FileNotFoundException {
        long len = (long) Math.pow(10, 7);
        int pos = 0;
        System.out.println(len * len);
        for (long i = 0; i < len; i++) {
            if (!isPalindrome(i)) {
                continue;
            }
            if (!isPalindrome(i * i)) {
                continue;
            }
            fairSquares[pos++] = i * i;
        }
        System.out.println(pos);
        System.out.println(Arrays.toString(fairSquares));
        String input = "data/C/large1.txt";
        String output = "data/C/large1O.txt";
        Scanner sc = new Scanner(new File(input));
        PrintStream out = new PrintStream(output);
        int cases = sc.nextInt();
        for (int i = 0; i < cases; i++) {
            out.print("Case #" + (i + 1) + ": ");
            out.println(exec(sc));
        }
    }

    public static String exec(Scanner sc) {
        long start = sc.nextLong();
        long end = sc.nextLong();
        int startCount = Arrays.binarySearch(fairSquares, 0, fairSquares.length, start);
        int endCount = Arrays.binarySearch(fairSquares, 0, fairSquares.length, end);
        startCount = (startCount < 0 ? -startCount - 1 : startCount);
        endCount = (endCount < 0 ? -endCount - 1 : endCount+1);
        return "" + (endCount - startCount);
    }

    public static boolean isPalindrome(long i) {
        if (i == 0) {
            return true;
        }
        int len = (int) Math.log10(i);
        long pos = (long) Math.pow(10, len);
        while (pos != 0) {
            long first = (i / pos) % 10;
            long last = i % 10;
            if (first != last) {
                return false;
            }
            i /= 10;
            pos /= 100;
        }
        return true;
    }
}
