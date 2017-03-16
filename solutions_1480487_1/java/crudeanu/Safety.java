import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.concurrent.Callable;

public class Safety {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new BufferedInputStream(new FileInputStream("A-large.in")));
        PrintStream out = new PrintStream(new FileOutputStream("A-large.out"));

        int nTests = scanner.nextInt();
        for (int test = 1; test <= nTests; test++) {
            final int n = scanner.nextInt();
            final double [] scores = new double[n];
            final Integer [] sort = new Integer[n];
            double sum = 0;
            for (int f = 0; f < n; f++) {
                scores[f] = scanner.nextInt();
                sum += scores[f];
                sort[f] = f;
            }
            final double finalSum = sum;
            double [] sol = new double[n];
            Arrays.sort(sort, new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return Double.valueOf(scores[o1]).compareTo(scores[o2]);
                }
            });
            for (int f = 0; f < n; f++) {
                final int index = f;
                sol[sort[index]] = new Callable<Double>(){
                    @Override
                    public Double call() {
                        return binarySearch(0d, 1d);
                    }
                    private double binarySearch(double low, double high) {

                        while (low <= high - 0.00000001d) {
                            double mid = (low + high) /2d;
                            int cmp = eval(mid);

                            if (cmp < 0)
                                low = mid;
                            else if (cmp > 0)
                                high = mid;
                            else
                                return mid; // key found
                        }
                        return (low + high)/2f;  // key not found.
                    }
                    private int eval(double val) {
                        double pi = scores[sort[index]] + val * finalSum;
                        double consumed = val;
                        for (int f = 0; f < n; f++) {
                            if (f == index)
                                continue;
                            if (scores[sort[f]] + (1 - consumed) * finalSum < pi)
                                return 1;
                            else
                                consumed += (pi - scores[sort[f]]) / finalSum;
                        }

                        return -1;
                    }
                }.call();
            }
            out.printf("Case #%d:", test);
            for (int f = 0; f < n; f++) {
                out.printf(" %.06f", 100d*sol[f]);
            }
            out.println();
        }
        out.close();
    }


}
