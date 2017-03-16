package c;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class NewLotteryGameSmall {

    public static void main(String[] args) throws Exception {
//        String testCase = "A-small-attempt0";
//        String testCase = "A-large";
        String testCase = "B-small-attempt0";
        Scanner scanner = new Scanner(new File("input/" + testCase + ".in"));
        PrintStream output = new PrintStream(new File("output/" + testCase + ".out"));

        int cases = scanner.nextInt();
        for (int i = 1; i <= cases; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int k = scanner.nextInt();
            output.println("Case #" + i + ": " + calculate(a, b, k));
            output.flush();
        }
        scanner.close();
        output.close();
    }

    private static int calculate(int a, int b, int k) {
        int count = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if ((i & j) < k) count++;
            }
        }
        return count;
    }

}