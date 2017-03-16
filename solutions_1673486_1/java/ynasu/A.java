import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class A {
    public double solve(int A, int B, double[] p) {
        double res = B + 2;
        double correct = 1.0;
        for (int i = 0; i < A; i++) {
            res = Math.min(res, A + B - 2 * i + 1 + (1 - correct) * (B + 1));
            correct *= p[i];
        }
        res = Math.min(res, B - A + 1 + (1 - correct) * (B + 1));
        return res;
    }

    public static void main(String[] args) {
        try {
            int T;
            BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

            T = Integer.parseInt(input.readLine());
            for (int i = 0; i < T; i++) {
                String[] str = input.readLine().split(" ");
                if (str.length != 2) throw new RuntimeException();
                int A = Integer.parseInt(str[0]);
                int B = Integer.parseInt(str[1]);
                str = input.readLine().split(" ");
                if (str.length != A) throw new RuntimeException();
                double[] p = new double[A];
                for (int j = 0; j < A; j++) {
                    p[j] = Double.parseDouble(str[j]);
                }
                System.out.println("Case #" + (i + 1) + ": " + new A().solve(A, B, p));
            }
            if (input.readLine() != null) throw new RuntimeException();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
