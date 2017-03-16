import java.util.Scanner;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[1001];
        for (int i = 1; i * i <= 1000; i++) {
            if (isPalindrome(i) && isPalindrome(i * i)) {
                arr[i * i] = 1;
            }
        }
        int[] total = new int[1001];
        for (int i = 1; i <= 1000; i++) {
            total[i] = total[i - 1] + arr[i];
        }

        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            System.out.println("Case #" + caseNum + ": " + (total[B] - total[A - 1]));
        }
    }

    static boolean isPalindrome(int n) {
        String str = n + "";
        for (int j = 0; j < str.length(); j++) {
            if (str.charAt(j) != str.charAt(str.length() - 1 - j)) {
                return false;
            }
        }
        return true;
    }
}
