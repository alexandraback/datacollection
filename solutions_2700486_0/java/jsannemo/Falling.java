package gcj13.oneb;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author Johan Sannemo
 */
public class Falling {

    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream("C:\\Users\\Johan Sannemo\\Downloads\\B-small-attempt0.in"));
        System.setOut(new PrintStream("C:\\Users\\Johan Sannemo\\Downloads\\B-small.out"));

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for (int i = 1; i <= t; ++i) {
            System.out.print("Case #"+i+": ");
            solve(sc);
        }
    }

    private static final double calcProb(int height, int need, int events) {
        double[][] dp = new double[events + 1][need + 1];
        dp[events][need] = 1;
        for (int i = events; i > 0; --i) {
            for (int j = need; j > 0; --j) {
                if ((events - i) - (need - j) == height) {
                    dp[i - 1][j - 1] += dp[i][j];
                } else {
                    dp[i - 1][j] += dp[i][j] * 0.5;
                    dp[i - 1][j - 1] += dp[i][j] * 0.5;
                }
            }
            dp[i - 1][0] += dp[i][0];
        }
        double sum = dp[0][0];
        return sum;
    }

    private static final void solve(Scanner sc) {
        int n = sc.nextInt();
        int x = Math.abs(sc.nextInt());
        int y = sc.nextInt();
        if (y < 0) {
            System.out.println("0");
            return;
        }
        int layer = (x + y) / 2;
        int acc = 0;
        for (int i = 0;; i++) {
            acc += 4 * i + 1;
            if (layer == i) {
                if (acc <= n) {
                    System.out.println("1");
                } else {
                    int left = n - (acc - (4 * i + 1));
                    int height = 2 * i + 1;
                    if (height - 1 + y + 1 <= left) {
                        System.out.println("1");
                    } else {
                        if (y == height - 1) {
                            System.out.println("0");
                        } else {
                            System.out.println(calcProb(height - 1, y + 1, left));
                        }
                    }
                }
                break;
            }
            if (acc >= n) {
                System.out.println("0");
                break;
            }
        }
    }
}
