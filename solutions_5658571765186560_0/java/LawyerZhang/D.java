import java.util.*;

public class D {
    static boolean test(int x, int w, int h, int leftLen, int rightLen, int leftEmpty) {
        int curr = leftEmpty;
        for (int center = leftLen; center + rightLen < w; ++center) {
            if (curr % x == 0)
                return false;
            curr += h;
            if (curr % x == 0)
                return false;
        }
        return true;
    }

    public static final void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for (int cs = 1; cs <= T; ++cs) {
            int x = scan.nextInt(), r = scan.nextInt(), c = scan.nextInt();
            int min = Math.min(r, c);
            boolean win = false;
            if (x == 2 * min - 1) {
                for (int left = 0; left <= min - 1; ++left)
                    if (test(x, Math.max(r, c), Math.min(r, c), left, min - 1 - left, (min - 1) * left))
                        win = true;
            } else if (x == 2 * min) {
                for (int left = 0; left <= min - 1; ++left) {
                    if (test(x, Math.max(r, c), Math.min(r, c), left + 1, min - 1 - left, (min - 1) * (left + 1)))
                        win = true;
                    if (test(x, Math.max(r, c), Math.min(r, c), left, min - left, (min - 1) * left))
                        win = true;
                    if (left > 0 && test(x, Math.max(r, c), Math.min(r, c), left, min - 1 - left, (min - 1) * left - 1))
                        win = true;
                    if (left < min - 1 && test(x, Math.max(r, c), Math.min(r, c), left, min - 1 - left, (min - 1) * left))
                        win = true;
                }
            }
            if (win || x >= 7 || x > Math.max(r, c) || r * c % x != 0 || x >= 2 * min + 1)
                System.out.format("Case #%d: Richard\n", cs);
            else
                System.out.format("Case #%d: Gabriel\n", cs);
        }
    }
}
