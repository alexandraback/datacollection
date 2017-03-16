import java.util.*;

/**
 * Created by poly on 4/11/15.
 */
public class InfiniteHouseOfPancakes {
    public static void main(String argv[]) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int d = scanner.nextInt();
            int[] p = new int[d];
            for (int i = 0; i < d; i++) {
                p[i] = scanner.nextInt();
            }
            int ans = Integer.MAX_VALUE;
            for (int b = 1; b < 1001; b++) {
                int move = 0;
                for (int i = 0; i < d; i++) {
                    move += (p[i] / b) - 1 + ((p[i] % b) > 0 ? 1 : 0);
                }
                ans = Math.min(ans, move + b);
            }
            System.out.println("Case #" + (t + 1) + ": " + ans);
        }
    }
}
