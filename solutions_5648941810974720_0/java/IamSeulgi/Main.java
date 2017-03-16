import java.io.*;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        final Scanner scanner = new Scanner(new BufferedInputStream(new FileInputStream("input.in")));
        final PrintWriter writer = new PrintWriter(new BufferedOutputStream(new FileOutputStream("output.out")));

        int T = scanner.nextInt();



        for (int cid = 1; cid <= T; cid++) {
            String str = scanner.next();
            final Solver solver = new Solver(str);
            writer.printf("Case #%d: %s\n", cid, solver.solve());

        }
        writer.flush();
    }

}

/*
    Unique in the below order
    Z => ZERO
    X => SIX
    W => TWO
    S => SEVEN
    V => FIVE
    G => EIGHT
    F => FOUR
    T => THREE
    O => ONE
    N => NINE
 */
class Solver {

    private static final String[] words =
        {"ZERO", "SIX", "TWO", "SEVEN", "FIVE", "EIGHT", "FOUR", "THREE", "ONE", "NINE"};

    private static final String[] nums = {"0", "6", "2", "7", "5", "8", "4", "3", "1", "9"};
    private static final char[] uniq = {'Z', 'X', 'W', 'S', 'V', 'G', 'F', 'T', 'O', 'N'};

    private String puzzle;
    private Map<Character, Integer> counts;

    public Solver(String puzzle) {
        this.puzzle = puzzle;
        counts = new HashMap<>();
    }

    public String solve() {

        for(int i=0; i < puzzle.length(); i++) {
            char ch = puzzle.charAt(i);
            if(counts.containsKey(ch)) {
                counts.put(ch, counts.get(ch) + 1);
            } else {
                counts.put(ch, 1);
            }
        }
        String ans = "";
        for (int i = 0; i <= 9; i++) {

            while(counts.containsKey(uniq[i]) && counts.get(uniq[i]) > 0) {
                ans += nums[i];
                for(char ch : words[i].toCharArray()) {
                    counts.put(ch, counts.get(ch) - 1);
                }
            }
        }
        char[] sorted = ans.toCharArray();
        Arrays.sort(sorted);
        return new String(sorted);
    }
}
