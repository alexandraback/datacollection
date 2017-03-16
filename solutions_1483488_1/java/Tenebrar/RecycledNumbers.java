
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashSet;

/**
 *
 * @author peterboyen
 */
public class RecycledNumbers {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("/Users/peterboyen/Downloads/C-large.in"));

        String line = br.readLine();

        int testCases = Integer.parseInt(line);

        PrintStream ps = new PrintStream("/Users/peterboyen/Downloads/C-large.out");
        for (int i = 1; i <= testCases; i++) {
            line = br.readLine();

            ps.println("Case #" + i + ": " + solve(line));
        }

        br.close();
        ps.close();
    }

    private static int solve(String line) {
        String[] split = line.split(" ");
        int A = Integer.parseInt(split[0]);
        int B = Integer.parseInt(split[1]);

        int result = 0;
        for (int m = A + 1; m <= B; m++) {
            result += getRecycled(m, A);
        }

        return result;
    }

    private static int getRecycled(int m, int A) {
        String M = "" + m;

        HashSet<Integer> set = new HashSet<Integer>();

        int result = 0;
        for (int i = 0; i < M.length() - 1; i++) {
            M = M.substring(1) + M.charAt(0);
            if (M.charAt(0) != '0') {
                int n = Integer.parseInt(M);
                if (n >= A && n < m && !set.contains(n)) {
                    result++;
                    set.add(n);
                }
            }
        }

        return result;
    }
}
