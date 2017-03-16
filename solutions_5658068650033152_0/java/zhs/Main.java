
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author zhs
 */
public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream(
                "/home/zhs/file/code/codejam/20140511/C-small-attempt5.in"));
        System.setOut(new PrintStream(
                "/home/zhs/file/code/codejam/20140511/C-small-attempt5.out"));
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int cs = 1; cs <= t; cs++) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int k = scanner.nextInt();
            if (n > m) {
                n ^= m;
                m ^= n;
                n ^= m;
            }
//            System.out.println(n + " " + m + " " + k);
            System.out.print("Case #" + cs + ": ");
            if (k <= 4) {
                System.out.println(k);
            } else {
                if (n <= 2) {
                    System.out.println(k);
                } else {
                    int r = 2 * m + 2 * n - 4;
                    if (3 * m >= k) {
                        for (int i = 1; i + 2 <= m + 1; i++) {
                            if (i + 2 == m + 1) {
                                r = m * 2 + 2 - (3 * m - k);
                                break;
                            }
                            if (i * 3 + 2 >= k) {
                                r = Math.min(r, i * 2 + 2);
                                break;
                            }
                            if (i * 3 + 2 + 1 >= k) {
                                r = Math.min(r, i * 2 + 2 + 1);
                                break;
                            }
                        }
                    }
                    if (n == 4) {
                        for (int i = 1; i + 2 <= m + 1; i++) {
                            if (i + 2 == m + 1) {
                                r = m * 2 + 4 - (4 * m - k);
                                break;
                            }
                            if (i * 4 + 2 >= k) {
                                r = Math.min(r, i * 2 + 3);
                                break;
                            }
                            if (i * 4 + 4 >= k) {
                                r = Math.min(r, i * 2 + 4);
                                break;
                            }
                        }
                    }
                    System.out.println(r);
                }
            }
        }
    }
}
