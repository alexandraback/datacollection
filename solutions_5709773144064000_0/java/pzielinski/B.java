import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

/**
 * Created by pz on 4/11/14.
 */
public class B {

    static void testcase(final Scanner sc) {
        final double c, f, x;
        c = sc.nextDouble();
        f = sc.nextDouble();
        x = sc.nextDouble();

        double best = Double.MAX_VALUE;
        double czas = 0;
        for (int i = 0; i <= 100000; ++i) {
            best = Math.min(best, czas + x / (2.0 + i*f));
            czas += c / (2.0 + i*f);
        }
        System.out.println(String.format("%.7f", best));
    }

    public static void main(String... args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        final int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            System.out.print(String.format("Case #%d: ", i+1));
            testcase(sc);
        }
    }
}
