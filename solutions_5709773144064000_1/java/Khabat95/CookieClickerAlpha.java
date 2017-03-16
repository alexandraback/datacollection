import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.Scanner;

/**
 * Created by khabat95 on 13/04/14.
 */
public class CookieClickerAlpha {

    public static String alg(double C, double F, double X) {
        double res = X / 2.0;
        double tempRes = res;
        double tempFarms = 0;
        long farms = 0;
        do {
            res = tempRes;
            tempFarms += C/(2.0 + (double)farms*F);
            farms++;
            tempRes = tempFarms + X/(2.0 + (double)farms*F);
        } while (tempRes < res);
        DecimalFormat df = new DecimalFormat("#.#######");
        return df.format(res);
    }

    public static void main(String args[]) {
        try {
            Scanner sc = new Scanner(new FileReader("/home/khabat95/Downloads/test.in"));
            PrintWriter pw = new PrintWriter("/home/khabat95/Downloads/test.out");

            int T = sc.nextInt();
            for (int i = 0; i < T; i++) {
                System.out.println("Test case " + (i + 1) + "...");
                pw.println("Case #" + (i + 1) + ": " + alg(Double.valueOf(sc.next()), Double.valueOf(sc.next()), Double.valueOf(sc.next())));
            }

            pw.flush();
            pw.close();
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
