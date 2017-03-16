import java.util.Scanner;

class SolveLarge {
    public static boolean isPalindrome(String s) {
        if (s.length() <= 1) {
            return true;
        }
        return s.charAt(0) == s.charAt(s.length() - 1) 
            && SolveLarge.isPalindrome(s.substring(1, s.length() - 1));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numCases = scanner.nextInt();
        for (int i = 0; i < numCases; ++i) {
            // 10^14 is still within 2^64, we can use long
            long low = scanner.nextLong();
            long high = scanner.nextLong();
            long start = Math.round(Math.ceil(Math.sqrt(low)));
            long end = Math.round(Math.floor(Math.sqrt(high))) + 1;
            long res = 0;
            for (long s = start; s < end; s++) {
                if (isPalindrome(Long.toString(s)) && isPalindrome(Long.toString(s * s))) {
                    res += 1;
                }
            }
            System.out.printf("Case #%d: %d\n", i + 1, res);
        }
    }
}
