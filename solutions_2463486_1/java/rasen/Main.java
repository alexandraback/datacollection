import java.util.Scanner;

public class Main {

    static boolean isPalindrome(Long in) {
        String str = in.toString();
        int len = str.length();
        int n2 = len/2;
        for (int i = 0; i < n2; ++i) {
            if (str.charAt(i) != str.charAt(len-i-1)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        for (int k = 1; k <= n; ++k) {
            Long a = in.nextLong();
            Long b = in.nextLong();

            Long sa, sb;
            sa = (long)Math.ceil(Math.sqrt(a));
            sb = (long)Math.floor(Math.sqrt(b));

            int count = 0;
            for (Long i = sa; i <= sb; ++i) {
                if (isPalindrome(i) && isPalindrome(i*i)) {
                    ++count;
                }
            }

            System.out.println("Case #" + k + ": " + count);
        }
    }
}
