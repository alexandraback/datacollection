import java.util.Scanner;

/**
 * @Author Mikhail Linkov
 * Date: 05.05.12
 */

public class ProblemC {
    private static int [] b;
    private static int [] a;

    private static boolean flag;
    private static int n;

    private static void recTwo(int sum, int k, int needSum) {


        if ((sum == needSum) && (sum > 0)) {
            flag = true;
        }

        if (flag) {
            return;
        }

        if (sum > needSum) {
            return;
        }

        if (k == n) {
            return;
        }

        if (b[k] == 1) {
            recTwo(sum, k + 1, needSum);
        } else {
            b[k] = 0;
            recTwo(sum, k + 1, needSum);
            if (flag) {
                return;
            }
            b[k] = 2;
            recTwo(sum + a[k], k + 1, needSum);
            if (flag) {
                return;
            }
            b[k] = 0;
        }
    }

    private static void recOne(int sum, int k) {
        if (k == n) {
            recTwo(0, 0, sum);
            return;
        }
        if (flag) {
            return;
        }
        for (int i = 0; i < 2; i++) {
            b[k] = i;
            recOne(sum + b[k] * a[k], k + 1);
            if (flag) {
                return;
            }
            b[k] = 0;
        }
    }

    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int testCount = scanner.nextInt();

        for (int test = 1; test < testCount + 1; test++) {
            n = scanner.nextInt();
            a = new int[n];
            b = new int[n];
            flag = false;

            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }

            recOne(0, 0);
            System.out.println("Case #" + test + ": ");
            if (flag) {
                for (int i = 0; i < n; i++) {
                    if (b[i] == 1) {
                        System.out.print(a[i] + " ");
                    }
                }
                System.out.println();
                for (int i = 0; i < n; i++) {
                    if (b[i] == 2) {
                        System.out.print(a[i] + " ");
                    }
                }
                System.out.println();
            }
            else {
                System.out.println("Impossible");
            }
        }

    }

}
