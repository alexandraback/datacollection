import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Created with longelliJ IDEA.
 * User: Qba
 * Date: 13.04.13
 * Time: 16:30
 * To change this template use File | Settings | File Templates.
 */
public class Solution {

    long current;

    public static void main(String[] args) throws FileNotFoundException {
        Solution solution = new Solution();
        Scanner scanner = new Scanner(new File("files/input"));
        int cases = scanner.nextInt();
        for (int i = 0; i < cases; i++) {
            long result = solution.solve(scanner.nextLong(), scanner.nextLong());
            System.out.println("Case #" + (i + 1) + ": " + result);
        }
    }

    public long solve(long from, long to) {
        long result = 0;
        current = from;
        while (current <= to) {
            if (isPalindrome(current) && isSquareOfPalindrome(current)) {
                result++;
            }
            determineCurrent();
        }
        return result;
    }

    private void determineCurrent() {
        long root = (long) Math.sqrt(current);
        current = (root + 1) * (root + 1);
//        System.out.println(current);
    }

    private boolean isSquareOfPalindrome(long i) {
        long root = (long) Math.sqrt(i);
        return root * root == i && isPalindrome(root);
    }

    private boolean isPalindrome(long i) {
        boolean is = true;
        String string = Long.toString(i);
        for (int j = 0; j < string.length(); j++) {
            if (string.charAt(j) != string.charAt(string.length() - j - 1)) {
                return false;
            }
        }
        return is;
    }

}
