import java.util.Scanner;

public class PasswordProblem {
    public static void main(String[] _) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; ++t) {
            int A = sc.nextInt(), B = sc.nextInt();
            double minStrokes = B + 2, p = 1;
            for (int i = 0; i <= A; ++i) {
                if (i > 0) p *= sc.nextDouble();
                double eRight = A - i + B - i + 1,
                       eWrong = eRight + B + 1,
                       e = eRight * p + eWrong * (1 - p);
                minStrokes = Math.min(minStrokes, e);
            }
            System.out.printf("Case #%d: %f\n", t, minStrokes);
        }
    }
}
