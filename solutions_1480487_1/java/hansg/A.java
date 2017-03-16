import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {
    public static void main(String[] args) throws IOException {
        if (args.length < 1) {
            System.err.println("Missing input filename as argument.");
            System.exit(1);
        }
        final BufferedReader in = new BufferedReader(new FileReader(args[0]));
        final PrintWriter out =
            new PrintWriter(new BufferedOutputStream(System.out));

        final int nbrTestCases = Integer.parseInt(in.readLine());
        for (int testCase = 1; testCase <= nbrTestCases; testCase++) {
            final StringTokenizer st1 = new StringTokenizer(in.readLine());
            final int n = Integer.parseInt(st1.nextToken());
            final int[] pointValues = new int[n];
            for (int i = 0; i < n; i++) {
                pointValues[i] = Integer.parseInt(st1.nextToken());
            }

            final double[] percentages = f(n, pointValues);
            out.printf("Case #%d:", testCase);
            for (int i = 0; i < n; i++) {
                out.printf(" %.6f", percentages[i]);
            }
            out.println();
        }

        out.flush();
    }

    private static double[] f(final int n, final int[] pointValues) {
        final double[] s = new double[n];
        for (int i = 0; i < n; i++) {
            s[i] = (double) pointValues[i];
        }
        final int[] sortedPointValues = Arrays.copyOf(pointValues, n);
        Arrays.sort(sortedPointValues);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += sortedPointValues[i];
        }

        final double[] means = new double[n];
        final int x = sum;
        //final double nAsDouble = (double) n;
        int sumSoFar = 0;
        for (int i = 0; i < n; i++) {
            sumSoFar += sortedPointValues[i];
            means[i] = (sumSoFar + x) / ((double) (i + 1));
        }

        int useMean = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            useMean = i;
            if (i > 0 && sortedPointValues[i] < means[i - 1]) {
                break;
            }
        }
        final double mean = means[useMean];
        /*
        System.err.println(Arrays.toString(sortedPointValues));
        System.err.println(Arrays.toString(means));
        System.err.println(useMean);
        */

        final double[] percentages = new double[n];
        final double xAsDouble = (double) x;
        for (int i = 0; i < n; i++) {
            if (s[i] >= mean) {
                percentages[i] = 0.0;
            } else {
                percentages[i] = 100.0 * (mean - s[i]) / xAsDouble;
            }
        }
        /*
        double pSum = 0.0;
        for (int i = 0; i < n; i++) {
            pSum += percentages[i];
        }
        System.err.println("Sum of percentages = " + pSum);
        */

        return percentages;
    }
}
