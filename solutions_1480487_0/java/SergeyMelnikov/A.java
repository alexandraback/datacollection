import java.util.Scanner;

public class A {
    double[] solve(int[] a) {
        double[] res = new double[a.length];
        int x = 0;
        for (int i : a) {
            x += i;
        }
        for (int i = 0; i < a.length; i++) {
            double L = 0;
            double R = 1;
            for (int it = 0; it < 100; it++) {
                double M = (L + R) / 2;
                double score = a[i] + M * x;
                double other = 0;
                for (int j = 0; j < a.length; j++) {
                    if (i == j) {
                        continue;
                    }
                    if (a[j] < score) {
                        other += (score - a[j]) / x;
                    }
                }
                if (M + other > 1){
                    R = M;
                }else {
                    L = M;
                }
            }
            res[i] = L;
        }
        return res;
    }

    public void run() {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int j = 0; j < n; j++) {
                a[j] = in.nextInt();
            }
            System.out.print("Case #" + (i + 1) + ":");
            for (double d : solve(a)) {
                System.out.printf(" %.10f",  d * 100);
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        new A().run();
    }
}
//
//10 == 30 * (1 - 2 * y)
//1 - 2 * y = 1/3
//2 / 3 = 2  *y
//y = 1/3