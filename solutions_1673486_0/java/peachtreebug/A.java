import java.util.*;
import java.math.*;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        A th = new A();
        for (int i = 0; i < T; i++) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            double[] p = new double[A];
            for (int j = 0; j < A; j++) {
                p[j] = sc.nextDouble();
            }
            String c = th.getAnswer(A, B, p);
            System.out.println("Case #" + (i+1) + ": " + c);
        }
    }
    public String getAnswer(int A, int B, double[] p) {
        int b = B - A;
        double minc = (double) (A + b + 2);
        double pr = 1.0;
        double mint = minc;
        for (int i = 0; i < A; i++) {
            pr = p[i] * pr;
            double s = pr * (double) ((A-i-1)*2+b+1);
            double f = (1.0-pr) * (double) ((A-i-1)*2+b+A+b+2);
            mint = s + f;
            if (mint < minc) {
                minc = mint;
            }
        }
        return tr(minc);
    }
    public String tr(double d) {
        double e = d + 0.00000000013;
        String s = "" + e;
        char[] c = s.toCharArray();
        int n = c.length;
        char[] b = new char[n];
        int k = 0;
        while (c[k] != '.') {
            b[k] = c[k];
            k++;
        }
        char[] bc = new char[k + 7];
        for (int i = 0; i < k; i++) {
            bc[i] = b[i];
        }
        bc[k] = '.';
        k++;
        for (int i = 0; i < 6; i++) {
            bc[k] = c[k];
            k++;
        }
        return new String(bc);
    }


}

