
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;

/**
 *
 * @author peterboyen
 */
public class DancingWithTheGooglers {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("/Users/peterboyen/Downloads/B-small-attempt0.in"));

        String line = br.readLine();

        int testCases = Integer.parseInt(line);

        PrintStream ps = new PrintStream("/Users/peterboyen/Downloads/B-small-attempt0.out");
        for (int i = 1; i <= testCases; i++) {
            line = br.readLine();

            ps.println("Case #" + i + ": " + solve(line));
        }

        br.close();
        ps.close();
    }

    private static int solve(String line) {
        String[] split = line.split(" ");
        int N = Integer.parseInt(split[0]);
        int S = Integer.parseInt(split[1]);
        int p = Integer.parseInt(split[2]);

        if (p == 0) {
            return N;
        }

        int[] scores = new int[N];

        for (int i = 0; i < scores.length; i++) {
            scores[i] = Integer.parseInt(split[i + 3]);
        }

        int result = 0;

        for (int score : scores) {
            if (score >= p * 3 - 2) {
                result++;
            } else if (score >= p && score >= p * 3 - 4 && S > 0) {
                result++;
                S--;
            }
        }

        return result;
    }
}
