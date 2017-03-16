import java.io.*;
import java.text.DecimalFormat;
import java.util.Scanner;

/**
 * Created by Rafal on 4/12/14.
 */
public class B {

    public static void main(String[] args) {
        try {

            InputStream in = new FileInputStream("c:/codejam/B.in");
            Scanner scanner = new Scanner(in);
            OutputStream out = new FileOutputStream("c:/codejam/B.out");
            PrintWriter writer = new PrintWriter(new OutputStreamWriter(out, "utf8"));
            int t = scanner.nextInt();
            for (int i = 0; i < t; i++) {
                solve(scanner, i+1, writer);
            }
            writer.close();
        } catch (Exception e) {
            System.out.println("Error: " + e);
            e.printStackTrace();
        }
    }


    public static void solve(Scanner scanner, int t, PrintWriter out) {
        double c = scanner.nextDouble();
        double f = scanner.nextDouble();
        double x = scanner.nextDouble();

        double seconds = 0;
        double cookies = 0;
        double rate = 2;        // 2 per second
        double tt;
        double tt2;
        double nextFarm;
        double nextRate;
        while (true) {
            // see how much time we have until we can reach x
            //double left = x -
            tt = x / rate;      // this much time is needed until we all cookies
            nextFarm = c / rate;    // this much time until we get next farm
            nextRate = rate + f;
            tt2 = (x / nextRate) + nextFarm;        // this is time to get result with all
            if (tt2 < tt) {
                seconds += nextFarm;
                rate = nextRate;
            } else {
                seconds += tt;
                break;
            }
        }
        System.out.println("Case #" + t + ": " + formatDouble(seconds));
        out.println("Case #" + t + ": " + formatDouble(seconds));
    }

    static DecimalFormat df = new DecimalFormat("#######################0.00000000000");
    private static String formatDouble(double seconds) {
        return df.format(seconds);
    }
}
