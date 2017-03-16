import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * CodeJam 2015: Round1C-A
 * User: Mitesh, 5/10/15
 */
public class Problem1A {
    private static final boolean DEBUG = false;

    public static void main(String[] args) throws FileNotFoundException {
        Problem1A prog = new Problem1A();

        Scanner in = new Scanner(new FileReader(args[0]));
        final int cntCases = in.nextInt();

        for (int caseNum = 1; caseNum <= cntCases && in.hasNextLine(); caseNum++) {
            try {
                in.nextLine(); //discard!
                final int ROWS = in.nextInt();
                final int COLUMNS = in.nextInt();
                final int WIDTH = in.nextInt();

                int ans1 = prog.solve(ROWS, COLUMNS, WIDTH);
                System.out.println("Case #" + caseNum + ": " + ans1);
            }
            catch (NoSuchElementException ex) {
                if (DEBUG) System.out.println("err: " + ex);
            }
        }
    }

    private int solve(final int r, final int c, final int w) {
        int cnt = c/w;
        cnt += (w-1);

        int leftover = c%w;
        if (leftover != 0) cnt++;

        return cnt;
    }

}
