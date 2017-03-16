
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B {
    public static void main(String[] args) throws Exception {
//        InputStream in = System.in;
        InputStream in = new FileInputStream("/home/floris/Downloads/B-small-attempt0.in");
        System.setOut(new PrintStream("/home/floris/temp/codejam2014/src/B.out"));
        Scanner sc = new Scanner(in);

        for (int c = 1, cases = sc.nextInt(); c <= cases; c++) {
            double cost = sc.nextDouble();
            double increase = sc.nextDouble();
            double x = sc.nextDouble();

            double best = x;
            double rate = 2;
            for (double t = 0; t < best;) {
                if (t+x/rate < best) {best = t+x/rate; }
                t+=cost/rate;
                rate+= increase;
            }
            System.out.printf("Case #%d: %.7f%n", c, best);
        }
    }
}
