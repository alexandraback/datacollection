import java.util.Arrays;
import java.util.Scanner;

public class Osmos {

    private static void out(int t, String ans) {
        System.out.println("Case #" + (t + 1) + ": " + ans);
        return;
    }

    private static int solve(int a, int[] motes, int offset, int count) {
        if (count > 23) {
            return 10000000;
        }
        int n = motes.length;
        if (offset >= n) {
            return count;
        }
        if (motes[offset] < a) {
            return solve(a + motes[offset], motes, offset + 1, count);
        } else {
            // add
            int ans1 = solve(a * 2 - 1, motes, offset, count + 1);
            // remove
            int ans2 = solve(a, motes, offset + 1, count + 1);

            return Math.min(ans1, ans2);
        }

    }

    /**
     * @param args
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        final int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int a = scanner.nextInt();
            int size = scanner.nextInt();
            int motes[] = new int[size];
            for (int j = 0; j < size; j++) {
                motes[j] = scanner.nextInt();
            }
            Arrays.sort(motes);
            if (a == 1) {
                out(t, "" + size);
            } else {
                out(t, "" + solve(a, motes, 0, 0));
            }
        }
    }

}
