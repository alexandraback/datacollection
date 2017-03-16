package gcj12;

import java.util.Scanner;

public class PasswordProblem {

    double solve(Scanner scan) {
        int A = scan.nextInt();
        int B = scan.nextInt();
        double[] p = new double[A];
        double[] pCorrect = new double[A];
        for (int i = 0; i < A; i++) {
            p[i] = scan.nextDouble();
        }
        pCorrect[0] = Math.log(p[0]);
        for (int i = 1; i < A; i++) {
            pCorrect[i] = pCorrect[i-1] + Math.log(p[i]);
        }

        double res =  B + 2;
        for (int i = 0; i <= A; i++) {
            int correct = i * 2 + (B-A) + 1;
            int wrong = correct + B + 1;
            double e = 0;
            if ( i < A) {
                double pc = Math.exp(pCorrect[A-i-1]);
                e = correct * pc + wrong * (1-pc);
            } else {
                e = correct;
            }
            if (e < res) {
                res = e;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        PasswordProblem pp = new PasswordProblem();
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.print("Case #" + i + ": ");
            double res = pp.solve(scan);
            System.out.printf("%.6f\n", res);
        }
    }
}
