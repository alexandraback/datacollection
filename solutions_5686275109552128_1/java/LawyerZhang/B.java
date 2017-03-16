import java.util.*;

public class B {
    public static final void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int cs = 1; cs <= T; ++cs) {
            int d = scan.nextInt();
            int[] a = new int[d];
            for (int i = 0; i < d; ++i)
                a[i] = scan.nextInt();
            int ans = Integer.MAX_VALUE;
            for (int k = 1; k <= 1000; ++k) {
                int t = 0;
                for (int i = 0; i < d; ++i)
                    t += (a[i] + k - 1) / k - 1;
                ans = Math.min(ans, k + t);
            }
            System.out.format("Case #%d: %d\n", cs, ans);
        }
    }
}
