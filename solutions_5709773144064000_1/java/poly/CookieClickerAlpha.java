import java.io.File;
import java.io.FileInputStream;
import java.util.Scanner;

public class CookieClickerAlpha {

    // private static String file = "data/q2sample.txt";
    // private static String file = "data/B-small-attempt0.in";
    private static String file = "data/B-large.in";

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        FileInputStream is = new FileInputStream(new File(file));
        Scanner scanner = new Scanner(is);
        int T = scanner.nextInt();
        for (int t = 0; t < T; t++) {
            double c = scanner.nextDouble();
            double f = scanner.nextDouble();
            double x = scanner.nextDouble();
            double speed = 2.0;
            double minTime = Double.MAX_VALUE;
            double offset = 0;
            while (offset < minTime) {
                double time = offset + x / speed;
                minTime = Math.min(minTime, time);
                // System.out.println(offset + ", " + time + ", speed=" + speed);

                // process to get another c cookies
                offset = offset + c / speed;
                speed += f;
            }

            out(t, String.format("%.7f", minTime));
        }
    }

    static void out(int t, Object ans) {
        System.out.println("Case #" + (t + 1) + ": " + ans);
    }

}
