import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

public class B {

    private static PrintStream out;
    private static Scanner in;


    @SuppressWarnings("ConstantConditions")
    public static void main(String[] args) throws FileNotFoundException {
        Locale.setDefault(Locale.US);
        out = System.out;
        boolean LOCAL = false;

        String inName = "input.txt";

        if (!LOCAL) {
            char TASK = 'B';
            int ATTEMPT = 0;
            boolean LARGE = false;

            String outName;

            if (LARGE) {
                inName  = TASK + "-large" + ".in";
                outName = TASK + "-large" + ".out";
            } else {
                inName  = TASK + "-small-attempt" + ATTEMPT + ".in";
                outName = TASK + "-small-attempt" + ATTEMPT + ".out";
            }

            out = new PrintStream(new FileOutputStream(outName));
        }

        in = new Scanner(new File(inName));



        int cases = in.nextInt();
        for (int tc = 1; tc <= cases; tc++) {
            out.print("Case #" + tc + ": ");
            double res = new B().solve();
            out.printf("%.9f\n", res);
        }
        out.close();
    }

    private double solve() {
        double C = in.nextDouble();
        double F = in.nextDouble();
        double X = in.nextDouble();

        double rate = 2;
        double res = X / rate;

        double time = 0;

        while (time < res) {
            time += C / rate;
            rate += F;
            res = Math.min(res, time + X / rate);
        }

        return res;
    }
}
