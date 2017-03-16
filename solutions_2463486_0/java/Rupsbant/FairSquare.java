package codejamreg;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class FairSquare {

    private static boolean[] fairSquares = new boolean[1001];

    public static void main(String[] args) throws FileNotFoundException {
        for (int i = 0; i < Math.sqrt(1000); i++) {
            if (!isPalindrome(i)) {
                continue;
            }
            if (!isPalindrome(i * i)) {
                continue;
            }
            fairSquares[i * i] = true;
        }
        String input = "data/C/small.txt";
        String output = "data/C/smallO.txt";
        Scanner sc = new Scanner(new File(input));
        PrintStream out = new PrintStream(output);
        int cases = sc.nextInt();
        for (int i = 0; i < cases; i++) {
            out.print("Case #" + (i + 1) + ": ");
            out.println(exec(sc));
        }
    }

    public static String exec(Scanner sc) {
        int count = 0;
        int start = sc.nextInt();
        int end = sc.nextInt();
        for (int i = start; i <= end; i++) {
            if (fairSquares[i]) {
                count++;
            }
        }
        return "" + count;
    }

    public static boolean isPalindrome(int i) {
        if (i == 0) {
            return true;
        }
        int len = (int) Math.log10(i);
        int pos = (int) Math.pow(10, len);
        while (pos != 0) {
            int first = (i / pos) % 10;
            int last = i % 10;
            if (first != last) {
                return false;
            }
            i /= 10;
            pos /= 100;
        }
        return true;
    }
}
