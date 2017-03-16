import java.util.Scanner;

public class FairAndSquare {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int T = sc.nextInt();

        for (int i = 0; i < T; i++) {
            long A = sc.nextLong(), B = sc.nextLong();
            System.out.println("Case #" + (i + 1) + ": " + fairAndSquare(A, B));
        }
    }

    private static long fairAndSquare(long A, long B) {
        int a = (int) Math.ceil(Math.sqrt(A));
        int b = (int) Math.floor(Math.sqrt(B));
        int num = 0;
        for (int i = a; i <= b; i++) {
            long l = i;
            if(isPalindrome(""+i) && isPalindrome("" + l*l))
                num++;
        }

        return num;
    }

    private static boolean isPalindrome(String s) {
        char[] S = s.toCharArray();

        for (int i = 0, j = S.length - 1; i < j; i++, j--)
            if (S[i] != S[j])
                return false;

        return true;
    }
}
