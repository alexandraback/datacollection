import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * by dt on 4/11/14, 8:18 PM
 */
public class B {
    public static void main(String[] args) throws FileNotFoundException {
//        Scanner sc = new Scanner(System.in);
        Scanner sc = new Scanner(new File("./GCJ14qual/B-small-attempt2.in"));
        PrintWriter pw = new PrintWriter(new File("./GCJ14qual/B-small-attempt2.out"));
//        PrintWriter pw = new PrintWriter(System.out);
        PrintWriter pwd = new PrintWriter(System.out);

        int t = sc.nextInt();
        for (int j = 1; j <= t; j ++) {
            double c = sc.nextDouble(), f = sc.nextDouble(), x = sc.nextDouble();
            pwd.println("C=" + c + " F=" + f + " X= " + x);
            pwd.flush();
            double min = Double.MAX_VALUE, tn, s = 0;
            int n = 0;
            do {
                tn = s + x / (2 + n*f);
                if (tn <= min) {
                    min = tn;
                    s += c / (2 + n*f);
                    n ++;
                }
            } while (tn <= min);

            pw.println(String.format("Case #%d: %.7f", j, min));
            pwd.println(String.format("Case #%d: %.7f", j, min));
            pwd.flush();
        }
        sc.close();
        pw.close();
    }
}
