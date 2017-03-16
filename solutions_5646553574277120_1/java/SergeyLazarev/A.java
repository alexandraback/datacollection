import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * User: hamilkar
 * Date: 10.05.15
 * Time: 12:19
 */
public class A {
    private static Scanner scanner;
    private static PrintWriter writer;

    static {
        try {
            scanner = new Scanner(new File("input.txt"));
            writer = new PrintWriter("output.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        int tests = scanner.nextInt();
        for (int t = 1; t <= tests; t++) {
            long c = scanner.nextInt();
            int d = scanner.nextInt();
            long v = scanner.nextInt();
            int[] a = new int[d];
            for (int i = 0; i < d; i++) {
                a[i] = scanner.nextInt();
            }
            Arrays.sort(a);

            long cur = 0;
            int i = 0;
            int res = 0;
            while (cur < v) {
                if (i < d && a[i] <= cur + 1) {
                    cur += a[i] * c;
                    i++;
                } else {
                    cur += (cur + 1) * c;
                    res++;
                }
            }

            writer.println("Case #" + t + ": " + res);
        }

        writer.close();
    }
}
