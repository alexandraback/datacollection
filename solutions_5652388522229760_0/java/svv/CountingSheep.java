package codejam.year2016.qualification.countingsheep;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class CountingSheep {


    public static void main(String[] args) {
        new CountingSheep().run();
    }

    private void run() {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = in.nextInt();
        in.skip("\n");
        for (int i = 1; i <= N; ++i) {
            System.out.print("Case #" + i + ": " + readAndSolve(in));
            if (i != N) {
                System.out.println();
            }
        }
    }

    private String readAndSolve(Scanner in) {
        int N = in.nextInt();

        if (N == 0) {
            return "INSOMNIA";
        }

        DigitManager dm = new DigitManager();
        int n = N;
        while (true) {
            if (markDigits(n, dm)) {
                return Integer.toString(n);
            }
            n += N;
        }
    }

    private boolean markDigits(int number, DigitManager dm) {
        while (number > 0) {
            int d = number % 10;
            if (dm.markDigit(d)) {
                return true;
            }
            number /= 10;
        }
        return false;
    }

    private static class DigitManager {

        private final boolean[] marked = new boolean[10];
        private int leftToMark = 10;

        /**
         * @param digit
         * @return `true` if all marked
         */
        public boolean markDigit(int digit) {
            if (!marked[digit]) {
                marked[digit] = true;
                leftToMark--;
            }
            return leftToMark == 0;
        }

    }
}
