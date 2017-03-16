import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class DeceitfulWar {

    // private static String file = "data/q4sample.txt";

    // private static String file = "data/D-small-attempt0.in";

    private static String file = "data/D-large.in";

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        FileInputStream is = new FileInputStream(new File(file));
        Scanner scanner = new Scanner(is);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            int n = scanner.nextInt();
            List<Double> naomi = new ArrayList<Double>();
            List<Double> ken = new ArrayList<Double>();
            for (int i = 0; i < n; i++) {
                naomi.add(scanner.nextDouble());
            }
            for (int i = 0; i < n; i++) {
                ken.add(scanner.nextDouble());
            }
            Collections.sort(naomi);
            Collections.sort(ken);
            Collections.reverse(naomi);
            Collections.reverse(ken);

            // System.out.println(naomi);
            // System.out.println(ken);

            int deceit = 0;
            {
                int kenOffset = 0;
                for (double naomiValue : naomi) {
                    while (kenOffset < ken.size() && naomiValue < ken.get(kenOffset)) {
                        kenOffset++;
                    }
                    if (kenOffset >= ken.size()) {
                        break;
                    }
                    deceit++;
                    kenOffset++;
                }
            }

            int normal = 0;
            {
                int naomiOffset = 0;
                for (double kenValue : ken) {
                    while (naomiOffset < naomi.size() && kenValue < naomi.get(naomiOffset)) {
                        naomiOffset++;
                    }
                    if (naomiOffset >= naomi.size()) {
                        break;
                    }
                    // System.out.println("ken:" + kenValue + ", naomi:" + naomi.get(naomiOffset));
                    normal++;
                    naomiOffset++;
                }
            }
            out(t, deceit + " " + (n - normal));
        }
    }

    static void out(int t, Object ans) {
        System.out.println("Case #" + (t + 1) + ": " + ans);
    }

}
