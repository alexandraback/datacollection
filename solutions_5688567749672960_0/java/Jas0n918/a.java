import java.util.Arrays;
import java.util.Scanner;

/**
 * @Author Jason918
 */
public class Main {


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int c = 1; c <= t; c++) {
            int n = sc.nextInt();


            System.out.printf("Case #%d: %d%n", c, solve(n));
        }


    }

    private static int solve(int n) {
        if (n < 10) {
            return n;
        }
        int[] f = new int[n + 1];
        Arrays.fill(f, n + 1);
        f[1] = 1;
        for (int i = 1; i < n; i++) {
            int r = reverse(i);
            if (r <= n) {
                f[r] = Math.min(f[i] + 1, f[r]);
            }
            f[i + 1] = Math.min(f[i] + 1, f[i + 1]);
        }
        return f[n];
    }

    private static int reverse(int i) {
        int ans = 0;
        while (i > 0) {
            ans = ans * 10 + i % 10;
            i /= 10;
        }
        return ans;
    }

}
