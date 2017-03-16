import java.util.*;

public class KingdomRush {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        ts: for (int t = 1; t <= T; ++t) {
            int N = sc.nextInt(), count = 0;
            final int[] a = new int[N], b = new int[N], st = new int[N];
            for (int i = 0; i < N; ++i) {
                a[i] = sc.nextInt();
                b[i] = sc.nextInt();
                st[i] = 0;
            }
            l: for (int stars = 0; stars < N*2; ++count) {
                for (int i = 0; i < N; ++i)
                    if (stars >= b[i] && st[i] < 2) {
                        stars += 2 - st[i];
                        st[i] = 2;
                        continue l;
                    }
                int bigGap = -1, winner = -1;
                for (int i = 0; i < N; ++i)
                    if (stars >= a[i] && st[i] == 0)
                        if (b[i] - a[i] > bigGap)
                            bigGap = b[i] - a[winner = i];
                if (winner == -1) {
                    System.out.printf("Case #%d: Too Bad\n", t);
                    continue ts;
                }
                ++stars;
                st[winner] = 1;
            }
            System.out.printf("Case #%d: %d\n", t, count);
        }
    }
}
