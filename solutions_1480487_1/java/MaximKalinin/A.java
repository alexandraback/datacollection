import java.util.Locale;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Locale.setDefault(Locale.ENGLISH);
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; ++t) {
            int N = in.nextInt();
            int[] s = new int[N];
            double X = 0;
            for (int i = 0; i < N; ++i) {
                s[i] = in.nextInt();
                X += s[i];
            }
            System.out.print("Case #");
            System.out.print(t);
            System.out.print(": ");
            for (int i = 0; i < N; ++i) {
/*
                double y = 2.0 / N - s[i] / X;
                if (y < 0) y = 0;
                if (y > 1) y = 1;
                y *= 100;
                System.out.print(y);
                System.out.print(" ");
*/
                double l = 0, r = 1;
                while (r - l > 1e-8) {
                    double m = (l + r) / 2;
                    double sum = 0;
                    for (int j = 0; j < N; ++j) {
                        double yj = (s[i] - s[j]) / X + m;
                        if (yj < 0) yj = 0;
                        sum += yj;
                    }
                    if (sum > 1) {
                        r = m;
                    } else {
                        l = m;
                    }
                }
                double y = (l + r) / 2 * 100;
                System.out.printf("%.8f", y);
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}
