import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class C {

    private static final String FILE_NAME = "C-small-attempt0";

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
        BufferedWriter out = new BufferedWriter(new FileWriter(FILE_NAME + ".out"));

        List<Long> palindromes = createPalindromes();

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            String[] row = in.readLine().split(" ");
            long start = Long.parseLong(row[0]);
            long end = Long.parseLong(row[1]);
            int count = 0;
            for (Long palindrome : palindromes) {
                if (palindrome > end) {
                    break;
                }
                if (start <= palindrome && end >= palindrome) {
                    ++count;
                }
            }
            out.write(String.format("Case #%d: %d\n", c, count));
        }
        out.close();
    }

    private static List<Long> createPalindromes() {
        List<Long> palindromes = new ArrayList<Long>();
        for (long i = 1; i <= 1e7; ++i) {
            if (isPalindrome(i) && isPalindrome(i*i)) {
                palindromes.add(i*i);
            }
        }
        return palindromes;
    }

    private static boolean isPalindrome(long i) {
        String s = Long.toString(i);
        for (int j = 0; j < s.length()/2; ++j) {
            if (s.charAt(j) != s.charAt(s.length()-1-j)) {
                return false;
            }
        }
        return true;
    }
}
