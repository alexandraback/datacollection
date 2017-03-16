import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemB {
    private final int[] stack;

    public ProblemB(String pancakes) {
        stack = new int[pancakes.length()];
        for (int i = 0; i < pancakes.length(); i++) {
            stack[i] = pancakes.charAt(i) == '-' ? 0 : 1;
        }
    }

    /**
     * Flips the stack between <code>0</code> and <code>n</code> inclusive
     */
    private void flip(int n) {
        int tmp;
        for (int i = 0; i <= n; i++) {
            stack[i] = 1 - stack[i];
        }
        for (int i = 0; i < (n + 1) / 2; i++) {
            tmp = stack[i];
            stack[i] = stack[n - i];
            stack[n - i] = tmp;
        }
    }

    public int solution() {
        int count = 0;
        int i;
        while (true) {
            int lastZero = -1;
            for (i = 0; i < stack.length; i++) {
                if (stack[i] == 0) lastZero = i;
            }
            if (lastZero < 0) return count;
            if (stack[0] == 1) {
                i = 0;
                while (i < stack.length && stack[i] == 1) {
                    i++;
                }
                count++;
                flip(i - 1);
                if (i == stack.length) return count;
            }
            count++;
            flip(lastZero);
        }
    }

    public static void main(String[] args) throws Exception {
//        Scanner in = new Scanner(System.in);
//        PrintStream out = System.out;
        Scanner in = new Scanner(new File("B.in"));
        PrintStream out = new PrintStream("B.out");
        int TOTAL_TESTS = in.nextInt();
        for (int t = 1; t <= TOTAL_TESTS; t++) {
            String stack = in.next();
            out.println("Case #" + t + ": " + new ProblemB(stack).solution());
        }
    }

}
