import java.io.*;
import java.util.Scanner;

public class Password {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new BufferedInputStream(new FileInputStream("A-small-attempt0.in")));
        PrintStream out = new PrintStream(new FileOutputStream("A-small.out"));
        int nTests = scanner.nextInt();
        for (int test = 1; test <= nTests; test++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            double [] probs = new double[a];
            for (int f = 0; f < a; f++) {
                probs[f] = scanner.nextDouble();
            }
            double minKS = Double.MAX_VALUE;
            double [] probFirstGood = new double[a + 1];
            double prod = 1.0;
            for (int f = 0; f <= a; f++) {
                probFirstGood[f] = prod;
                if (f< a)
                    prod *= probs[f];
            }
            for (int backspaces = 0; backspaces <= a; backspaces ++) {
                double v = probFirstGood[a - backspaces ];
                double expectedKS = v * (b - a + 2 * backspaces + 1) +
                        (1.d - v) * (b-a + 2*backspaces + b + 2);
                minKS = Math.min(expectedKS, minKS);
            }
            minKS = Math.min(minKS, 1+b + 1);
            out.printf("Case #%d: %.06f\n", test, minKS);
        }
        out.close();
    }
}
