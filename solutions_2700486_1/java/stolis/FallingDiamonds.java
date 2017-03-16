package round1;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

public class FallingDiamonds {
    static int T;
    static double[] result;
    static int X;
    static int Y;
    static int N;

    public static void main(String[] args) throws IOException {
        read();
        write();
    }

    static void read() throws IOException {
        File input = new File("input.txt");
        Scanner scanner = new Scanner(input);
        T = scanner.nextInt();
        result = new double[T];
        for (int t=0; t<T; t++) {
            N = scanner.nextInt();
            X = scanner.nextInt();
            Y = scanner.nextInt();
            result[t]  = process();
        }
    }

    static double process() {
        int k = 1;
        while ((k+1)*(2*k+1) <= N) k++;
        int full = k-1;
        int layer = (Y+Math.abs(X))/2;
        if (layer <= full) {
            return 1;
        }
        if (layer > full+1) {
            return 0;
        }
        int rest = N-(full+1)*(2*full+1);
        int height = Y+1;
        if (rest >= 2*full+2+height) {
            return 1;
        }
        if (rest < height) {
            return 0;
        }
        BigInteger val = BigInteger.ZERO;
        for (int i=0; i<=rest; i++) {
            int our = Math.max(Math.min(i, 2*full+2), rest-2*full-2);
            if (our >= height) {
                val = val.add(binomial(rest, i));
            }
        }
        BigDecimal d = new BigDecimal(val);
        for (int i=0; i<rest; i++) {
            d = d.divide(BigDecimal.valueOf(2));
        }
        return d.doubleValue();
    }
    
    static BigInteger binomial(int N, int K) {
        if (N < K) {
            return BigInteger.ZERO;
        }
        BigInteger result = BigInteger.ONE;
        for (int k = 0; k < K; k++) {
            result = result.multiply(BigInteger.valueOf(N-k))
                     .divide(BigInteger.valueOf(k+1));
        }
        return result;
    }

    static void write() throws IOException {
        File output = new File("output.txt");
        PrintWriter pw = new PrintWriter(output);

        for (int t=0; t<T; t++) {
            pw.println("Case #"+(t+1)+": "+result[t]);
        }

        pw.close();
    }

}
