import java.util.Scanner;

public class FairAndSquare2 {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            long A = sc.nextLong(), B = sc.nextLong();
            System.out.println("Case #" + (i + 1) + ": " + fairAndSquare(A, B));
        }
    }

    private static long fairAndSquare(long A, long B) {
        long a = (int) Math.ceil(Math.sqrt(A));
        long b = (int) Math.floor(Math.sqrt(B));
        int num = 0;

        long palindrome = firstPalindromeAbove(a);

        while(palindrome <= b) {
            if (isPalindrome("" + palindrome * palindrome))
                num++;
            palindrome = nextPalindrome(palindrome);
        }

        return num;
    }

    static long firstPalindromeAbove(long number) {
        String numberAsString = Long.toString(number);
        long palindrome = Long.parseLong(new String(mirror(numberAsString.toCharArray(), numberAsString.length())));

        while (palindrome < number) {
            palindrome = nextPalindrome(palindrome);
        }

        return palindrome;
    }

    static long nextPalindrome(long palindrome) {
        String s = Long.toString(palindrome);
        int l = s.length();
        String Headd = s.substring(0, (l + 1) / 2);
        long head = Long.parseLong(Headd);
        head++;
        int headLength = ("" + head).length();
        int prevLength = Headd.length();
        char[] Head = Long.toString(head).toCharArray();

        char[] nextPalindrome;
        if (headLength > prevLength) {
            nextPalindrome = mirror(Head, l + 1);
        } else {
            nextPalindrome = mirror(Head, l);
        }

        return Long.parseLong(new String(nextPalindrome));
    }

    private static char[] mirror(char[] start, int length) {
        char[] palindrome = new char[length];
        System.arraycopy(start, 0, palindrome, 0, length / 2);
        int j = 0;
        for (int i = length - 1; i >= length / 2; i--) {
            palindrome[i] = start[j++];
        }
        return palindrome;
    }

    private static boolean isPalindrome(String s) {
        char[] S = s.toCharArray();

        for (int i = 0, j = S.length - 1; i < j; i++, j--)
            if (S[i] != S[j])
                return false;

        return true;
    }


}
