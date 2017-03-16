import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.Scanner;

public class Diamonds {
    long n, x, y;
    public Diamonds(Scanner in) {
        n = in.nextInt();
        x = Math.abs(in.nextInt());
        y = in.nextInt();
    }

    /** How many trials are attempting to fill this layer? */
    long trialsInThisLayer() { return n - prevFilled(); }

    boolean filledForSure() { return filled() <= n; }
    boolean cantReach() { return prevFilled() >= n; }

    /** What should n be to fill the entire layer that this is in? */
    long filled() { return pyramid(layer()); }
    long prevFilled() { return pyramid(prevLayer()); }

    static long pyramid(long k) { return (k * k + k) / 2L; }

    /** What is the width of the layer we are in? */
    long layer() { return x + y + 1; }
    long prevLayer() { return layer() - 2; }

    /** How many diamonds can each side hold? */
    long diamondsPerSide() { return layer() - 1; }

    public double report() {
        if (filledForSure()) return 1.;
        else if (x == 0) return 0; // if it's not filled for sure, it won't reach the top
        else if (cantReach()) return 0;
        else return modelFilled(trialsInThisLayer(), diamondsPerSide(), y + 1);
    }

    /** What is the chance that at least y out of n will slide down our side?
     *  Each side can hold _side_ diamonds.
     *  n, y, side <= 10,000 */
    private double modelFilled(long n, long side, long y) {
        if (n - side >= y) return 1; // other side filled up and reached us
        else /*if (side >= n) */{ // can't overfill either side, so it's a simple situation
            BigDecimal accum = BigDecimal.ZERO;
            for (long i = y; i <= n; ++i)
                accum = accum.add(choose(n, i));
            return accum.divide(exp2(n)).doubleValue();
        }
//        else { // there's a chance that one side might fill up
//
//        }
    }

    static final BigDecimal TWO = BigDecimal.valueOf(2);
    static BigDecimal exp2(long n) {
        BigDecimal result = BigDecimal.ONE;
        for (long i = 0; i < n; ++i)
            result = result.multiply(TWO);
        return result;
    }

    static BigDecimal fact(long n) {
        BigDecimal result = BigDecimal.ONE;
        for (long i = 2; i <= n; ++i)
            result = result.multiply(BigDecimal.valueOf(i));
        return result;
    }

    static BigDecimal choose(long n, long k) {
        return fact(n).divide(fact(k).multiply(fact(n - k)));
    }

    public static void main(String[] args) throws IOException {
        String name = new Scanner(System.in).next();
        Scanner in = new Scanner(Diamonds.class.getResourceAsStream(name));
        int n = in.nextInt();
        long start = System.currentTimeMillis();
        int fileI = 1;
        File outFile;
        if (name.endsWith(".in"))
            outFile = new File(name.replace(".in", ".out"));
        else
            outFile = new File(name + ".out");

        FileOutputStream fout = new FileOutputStream(outFile);
        PrintWriter print = new PrintWriter(fout);
        for (int i = 1; i <= n; ++i) {
            String report = "Case #" + i + ": " + new Diamonds(in).report();
            print.println(report);
            System.out.println(report);
        }
        print.flush();
        fout.close();
        System.out.println("Elapsed: " + (System.currentTimeMillis() - start));
    }
}
