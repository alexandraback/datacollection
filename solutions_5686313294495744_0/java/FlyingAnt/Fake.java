import java.util.Scanner;

public class Fake {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        for (int kase = 1, kases = scanner.nextInt(); kase <= kases; kase++) {
            int n = scanner.nextInt();
            int[][] A = new int[n][2];
            for (int i = 0; i < n; i++) {
                String ss = "";
                while (ss.isEmpty()) {
                    ss = scanner.nextLine();
                }
                String[] s = ss.trim().split("\\s+");
                A[i][0] = s[0].hashCode();
                A[i][1] = s[1].hashCode();
            }

            int ans = 0;

            OUTER:
            for (int mask = 1; mask < (1 << n) - 1; mask++) {
                int cur = 0;
                for (int i = 0; i < n; i++) {
                    if ((mask & (1 << i)) != 0) {
                        if (!canBe(A, mask, i)) {
                            continue OUTER;
                        }
                        cur++;
                    }
                }
                ans = Math.max(ans, cur);
            }

            System.out.println("Case #" + kase + ": " + ans);
        }
    }

    private static boolean canBe(int[][] a, int mask, int i) {
        boolean x = false, y = false;
        for (int j = 0; j < a.length; j++) {
            if ((mask & (1 << j)) == 0) {
                x |= a[i][0] == a[j][0];
                y |= a[i][1] == a[j][1];
            }
        }
        return x && y;
    }
}
