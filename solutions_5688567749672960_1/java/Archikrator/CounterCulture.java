package google.codejam_2015;

import java.util.Scanner;

public class CounterCulture {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();

        for (int i = 0; i < t; i++) {
            long num = s.nextLong();
            System.out.printf("Case #%d: %s%n", i + 1, solve(num));
        }
    }

    private static long solve(long number) {
        long ops = 1;
        while (number != 1) {
            long on = onify(number);
            
            ops += number -on;
            number = on;

            long flipped = flip(number);
            if (flipped < number) {
                number = flipped;
                ops++;

            } else if (number > 10) {
                number -= 10;
                ops += 10;

            }
        }
        return ops;

    }
    private static int firstDigit(long number) {
        return Integer.valueOf("" + String.valueOf(number).charAt(0));
    }
    
    private static long onify(long number) {
        if (lastDigit(number) == '0') {
            number--;
        }
        char[] s = String.valueOf(number).toCharArray();
        int ending = s.length/2;
        for (int i = 1; i < ending; i++) {
            s[s.length - i-1] = '0';
        }
        s[s.length-1] = '1';
        return Long.valueOf(new String(s));
    }

    private static char lastDigit(long number) {
        String s = String.valueOf(number);
        return s.charAt(s.length() - 1);
    }

    private static long flip(long number) {
        String s = String.valueOf(number);
        return Long.valueOf(new StringBuilder(s).reverse().toString());
    }
}
