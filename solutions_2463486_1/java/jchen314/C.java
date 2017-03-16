import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Long> list = new ArrayList<Long>();
        for (long i = 1; i <= 10000000; i++) {
            if (isPalindrome(i) && isPalindrome(i * i)) {
                list.add(i * i);
            }
        }
        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            long A = sc.nextLong();
            long B = sc.nextLong();
            int indexB = Collections.binarySearch(list, B);
            if (indexB < 0) {
                indexB = -2 - indexB;
            }
            int indexA = Collections.binarySearch(list, A - 1);
            if (indexA < 0)
                indexA = -2 - indexA;
            System.out.println("Case #" + caseNum + ": " + (indexB - indexA));
        }

    }

    static boolean isPalindrome(long n) {
        String str = n + "";
        for (int j = 0; j < str.length(); j++) {
            if (str.charAt(j) != str.charAt(str.length() - 1 - j)) {
                return false;
            }
        }
        return true;
    }
}
