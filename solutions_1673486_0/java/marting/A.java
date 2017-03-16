import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
    static double calc(int A, int B, double[] P) {
        double res[] = new double[A+1];
        double resra = 0;
        for (int firstm = 0; firstm <= A; firstm ++) {
            double curp = 1;
            for (int i = 0; i < firstm; i++) {
                curp *= P[i];
            }
            if (firstm < A)
                curp *= 1-P[firstm];
            resra += curp*(2+B);
            for (int i = 0; i <= A; i++) {
                double r = (A-i) + B-i+1;
                if (i>firstm)
                    r += B+1;
                res[i] += r * curp;
            }
        }
        Arrays.sort(res);
        return Math.min(resra, res[0]);
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(new File("A.txt"));
        PrintWriter pw = new PrintWriter(new File("out.txt"));
        int T = sc.nextInt();
        for (int I = 0; I < T; I++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            double P[] = new double[A];
            for (int i = 0; i < A; i++) {
                P[i] = sc.nextDouble();
            }
            double res = calc(A, B, P);
            pw.printf("Case #%d: %f\n", I+1, res);
        }
        pw.close();
    }
}
