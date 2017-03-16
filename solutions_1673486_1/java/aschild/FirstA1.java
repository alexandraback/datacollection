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
            double[] prods = new double[A + 1];
            prods[0] = 1;
            for (int k = 1; k < A + 1; k++) {
                prods[k] = prods[k - 1] * prbs[k - 1];
            }
            System.out.println("Case #" + (i + 1) + ": " + getBestKeystrokes(A, B, prods));
        }
    }

    private static double getBestKeystrokes(int A, int B, double[] prbs) {
        double minExp = Double.MAX_VALUE;
        for (int i = 0; i <= A; i++) {
            double exp = (2 * i + B - A + 1) + (1 - prbs[A - i]) * (B + 1);
            minExp = Math.min(exp, minExp);
        }
        return Math.min(minExp, B + 2);
    }
}
