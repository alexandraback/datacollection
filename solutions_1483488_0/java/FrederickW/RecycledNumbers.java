import java.io.*;
import java.util.HashSet;
import java.util.Set;

/**
 * Created with IntelliJ IDEA.
 * User: Frederick
 * Date: 4/14/12
 * Time: 9:40 AM
 * To change this template use File | Settings | File Templates.
 */
public class RecycledNumbers {

    private static int solve(int a, int b) {
        int count = 0;
        for (int n = a; n < b; n++) {
            String nString = Integer.toString(n);
            int len = nString.length();
            Set<Integer> existing = new HashSet<Integer>();
            for (int i = 1; i < len; i++) {
                String mString = nString.substring(i) + nString.substring(0, i);
                int m = Integer.parseInt(mString);
                if (n < m && m <= b && existing.add(m)) {
                    count++;
                }
            }
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        File input = new File("C:\\Users\\Frederick\\Downloads\\C-small-attempt0.in");
        File output = new File(input.getAbsolutePath() + ".out");
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(input)));
        PrintStream out = new PrintStream(output);
        int cases = Integer.parseInt(in.readLine());
        for (int i = 1; i <= cases; i++) {
            String[] s = in.readLine().split(" ");
            int a = Integer.parseInt(s[0]);
            int b = Integer.parseInt(s[1]);
            int solution = solve(a, b);
            String print = "Case #" + i + ": " + solution;
            System.out.println(print);
            out.println(print);
        }
    }

}
