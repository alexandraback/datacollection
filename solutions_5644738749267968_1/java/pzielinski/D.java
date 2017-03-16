import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 * Created by pz on 4/11/14.
 */
public class D {

    // y to gracz
    private static int test(final List<Double> x, final List<Double> y) {
        int normalnie = 0;
        int latacz = 0;
        for (int i = 0; i < x.size(); ++i) {
            while (latacz < x.size() && x.get(latacz) < y.get(i)) {
                ++latacz;
            }
            if (latacz == x.size()) {
                ++normalnie;
            } else {
                ++latacz;
            }
        }
        return normalnie;
    }

    private static void testcase(final Scanner sc) {
        final int n = sc.nextInt();
        final List<Double> naomi = new ArrayList<>();
        final List<Double> ken = new ArrayList<>();

        for (int i = 0; i < n; ++i) {
            naomi.add(sc.nextDouble());
        }

        for (int i = 0; i < n; ++i) {
            ken.add(sc.nextDouble());
        }

        Collections.sort(naomi);
        Collections.sort(ken);

        System.out.println(String.format("%d %d", n - test(naomi, ken), test(ken, naomi)));
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
