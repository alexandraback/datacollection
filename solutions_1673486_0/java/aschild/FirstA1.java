import java.util.Scanner;


public class FirstA1 {
    
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        for (int i = 0; i < T; i++) {
            int A = s.nextInt();
            int B = s.nextInt();
            double[] prbs = new double[A];
            for (int j = 0; j < A; j++) {
                prbs[j] = s.nextDouble();
            }
            System.out.println("Case #" + (i + 1) + ": " + getBestKeystrokes(A, B, prbs));
        }
    }

    private static double getBestKeystrokes(int A, int B, double[] prbs) {
        double minExp = Double.MAX_VALUE;
        for (int i = 0; i <= A; i++) {
            double exp = (2 * i + B - A + 1) + (1 - product(prbs, A - i)) * (B + 1);
            minExp = Math.min(exp, minExp);
        }
        return Math.min(minExp, B + 2);
    }

    private static double product(double[] prbs, int max) {
        double prod = 1;
        for (int i = 0; i < max; i++) {
            prod *= prbs[i];
        }
        return prod;
    }

}
