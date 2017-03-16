
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author zhs
 */
public class Main {

    private static long solve(ArrayList<Integer> res, String[] s) {
        if (res.size() == s.length) {
            boolean[] f = new boolean[26];
            char last = 0;
            for (Integer i : res) {
                for (int j = 0; j < s[i].length(); j++) {
                    char ch = s[i].charAt(j);
                    if (f[ch - 'a'] && last != ch) {
                        return 0;
                    }
                    last = ch;
                    f[ch - 'a'] = true;
                }
            }
            return 1;
        }
        long r = 0;
        for (int i = 0; i < s.length; i++) {
            if (!res.contains(i)) {
                res.add(i);
                r += solve(res, s);
                res.remove(res.size() - 1);
            }
        }
        return r;
    }

    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream(
                "/home/zhs/file/code/codejam/20140511/B-small-attempt0.in"));
        System.setOut(new PrintStream(
                "/home/zhs/file/code/codejam/20140511/B-small-attempt0.out"));
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int cs = 1; cs <= t; cs++) {
            System.out.print("Case #" + cs + ": ");
            int n = scanner.nextInt();
            String[] s = new String[n];
            for (int i = 0; i < n; i++) {
                s[i] = scanner.next();
            }
            System.out.println(solve(new ArrayList<Integer>(), s));
        }
    }
}
