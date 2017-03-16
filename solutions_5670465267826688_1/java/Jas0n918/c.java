import java.util.Scanner;

/**
 * Created by jianghaiting on 15/4/8.
 */
public class Main {


    private static final int[][] LOOK_UP = new int[][] {
        { -1, 'k', -'j' },
        { -'k', -1, 'i' },
        { 'j', -'i', -1 }
    };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();

        for (int c = 1; c <= t; c++) {
            int l = sc.nextInt();
            long x = sc.nextLong();
            String s = sc.next();
            System.out.printf("Case #%d: %s\n", c, solve(l, x, s) ? "YES" : "NO");
        }
    }

    private static boolean solve(int l, long x, String s) {
        if (x * l < 3) {
            return false;
        }

        int curI = 1;
        int i;
        for (i = 0; i < 4 * l && curI != 'i'; i++) {
            curI = multi(curI, s.charAt(i % l));
        }
        if (i == 4*l) {
            return false;
        }
        i--;


        int curK = 1;
        int k;
        for (k = 4 * l - 1; k >= 0 && curK != 'k'; k--) {
            curK = multi(s.charAt(k % l), curK);
        }
        if (k < 0) {
            return false;
        }
        k++;

        long left = x - (i / l + 5 - k / l);
        if (left < -1 || left == -1 && i >= k) {
            return false;
        }
        long target;
        if (left == -1) {
            target = (k - 1 + l) % l;
        } else {
            left %= 4;
            target = l + left * l + k % l - 1;
        }

        int curJ = 1;
        int j;
        for (j = i % l + 1; j <= target; j++) {
            curJ = multi(curJ, s.charAt(j % l));
        }
        return curJ == 'j';
    }


    private static int multi(int a, int b) {
        int signA = sign(a);
        int signB = sign(b);
        a *= signA;
        b *= signB;
        if (a == 1 || b == 1) {
            return a * b * signA * signB;
        }
        a -= 'i';
        b -= 'i';
        return LOOK_UP[a][b] * signA * signB;
    }

    private static int sign(int a) {
        return a >= 0 ? 1 : -1;
    }
}
