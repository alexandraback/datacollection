import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
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
            int k = scanner.nextInt();
            int l = scanner.nextInt();
            int s = scanner.nextInt();
            char[] a = scanner.next().toCharArray();
            String b = scanner.next();

            char[] h = new char[s];

            int all = 0;
            int max = 0;
            int sum = 0;
            int[] d = new int[s];
            while (true) {


                for (int i = 0; i < s; i++) {
                    h[i] = a[d[i]];
                }

                int f = 0;
                for (int i = 0; i < s; i++) {
                    if (new String(h, i, s - i).startsWith(b)) {
                        f++;
                    }
                }
                all++;
                sum += f;
                max = Math.max(max, f);

                boolean next = false;
                for (int i = 0; i < s; i++) {
                    if (d[i] == k - 1) {
                        d[i] = 0;
                    } else {
                        d[i]++;
                        next = true;
                        break;
                    }
                }

                if (!next) {
                    break;
                }
            }

            writer.println("Case #" + t + ": " + (max - sum * 1.0 / all));
        }

        writer.close();
    }
}
