import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Q1 {

    public static String solve(String s) {

        String res = "" + s.charAt(0);
        for (int i = 1; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= res.charAt(0)) {
                res = c + res;
            } else {
                res += c;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
        in.nextLine();
        for (int i = 1; i <= t; ++i) {
            String s = in.nextLine();
            System.out.println("Case #" + i + ": " + solve(s));
        }
    }

}
