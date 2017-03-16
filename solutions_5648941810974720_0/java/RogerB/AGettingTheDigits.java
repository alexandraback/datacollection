package Round1B;

import java.util.Scanner;

public class AGettingTheDigits {
    static int[][] digitCounts;
    
    static int[] count(String input) {
        int[] result = new int[26];
        for (int x = 0; x < input.length(); x++) result[input.charAt(x) - 'A']++;
        return result;
    }
    
    static boolean subtract(int[] a, int[] b) {
        boolean isValid = true;
        for (int x = 0; x < 26; x++) {
            a[x] -= b[x];
            if (a[x] < 0) isValid = false;
        }
        return isValid;
    }
    
    static void add(int[] a, int[] b) {
        for (int x = 0; x < 26; x++) a[x] += b[x];
    }
    
    static boolean isZero(int[] count) {
        for (int x = 0; x < 26; x++) if (count[x] != 0) return false;
        return true;
    }
    
    static String getDigits(int[] count, int minFirst) {
        if (isZero(count)) return "";
        for (int guessDigit = minFirst; guessDigit <= 9; guessDigit++) {
            boolean isValid = subtract(count, digitCounts[guessDigit]);
            if (isValid) {
                String result = getDigits(count, guessDigit);
                if (!result.equals("ERROR")) {
                    return guessDigit + result;
                }
            }
            add(count, digitCounts[guessDigit]);
        }
        return "ERROR";
    }
    
    public static void main (String[] args) {
        digitCounts = new int[][] {count("ZERO"), count("ONE"), count("TWO"), count("THREE"), count("FOUR"), count("FIVE"), count("SIX"), count("SEVEN"), count("EIGHT"), count("NINE")};
        Scanner sc = new Scanner(System.in);
        int tests = sc.nextInt();
        for (int t = 1; t <= tests; t++) {
            System.out.printf("Case #%d: %s%n", t, getDigits(count(sc.next()), 0));
        }
        sc.close();
    }
}
