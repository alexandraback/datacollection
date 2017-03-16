import java.util.Scanner;

/**
 * Created by poly on 4/12/15.
 */
public class Dijkstra {
    static int[][] table = {
            {1, 2, 3, 4},
            {2, -1, 4, -3},
            {3, -4, -1, 2},
            {4, 3, -2, -1}
    };

    static int getId(char c) {
        switch (c) {
            case '1':
                return 1;
            case 'i':
                return 2;
            case 'j':
                return 3;
            case 'k':
                return 4;
        }
        return -1;
    }

    static int multiply(int i, int j) {
        int sign = 1;
        if (i < 0) {
            i = -i;
            sign *= -1;
        }
        if (j < 0) {
            j = -j;
            sign *= -1;
        }
        return sign * table[i - 1][j - 1];
    }

    public static void main(String argv[]) {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int l = scanner.nextInt();
            long x = scanner.nextLong();
            String s = scanner.next();
            int i = 0;
            {
                boolean leftok = false;
                int left = 1;
                for (i = 0; i < Math.min(4L, x) * l; i++) {
                    left = multiply(left, getId(s.charAt(i % l)));
                    if (left == 2) {
                        leftok = true;
                        break;
                    }
                }
                if (!leftok) {
                    System.err.println("left no");
                    ans(t, "NO");
                    continue;
                }
            }
            i++;
            {
                boolean middleok = false;
                int middle = 1;
                for (; i < Math.min(8L, x) * l; i++) {
                    middle = multiply(middle, getId(s.charAt(i % l)));
                    if (middle == 3) {
                        middleok = true;
                        break;
                    }
                }
                if (!middleok) {
                    System.err.println("middle no");
                    ans(t, "NO");
                    continue;
                }
            }
            int total = 1;
            for (i = 0; i < (x % 4L) * l; i++) {
                total = multiply(total, getId(s.charAt(i % l)));
            }
            if (total == -1) {
                ans(t, "YES");
            } else {
                System.err.println("total no");
                ans(t, "NO");
            }
        }
    }

    static void ans(int t, String ans) {
        System.out.println("Case #" + (t + 1) + ": " + ans);
    }
}
