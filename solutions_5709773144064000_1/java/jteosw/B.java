import java.util.*;
public class B {
    static Scanner s;
    public static void main(String[] args) {
        s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.printf("Case #%d: %.7f\n", i, solve());
        }
    }

    public static double solve() {
        double C = s.nextDouble();
        double F = s.nextDouble();
        double X = s.nextDouble();
        if (X < C) return X / 2;
        double n = Math.ceil((X-C) / C - 2.0 / F);
        n = Math.max(n, 0.0);

        double time = 0;
        for (int i = 0; i < n; i++) {
            time += (C / (2 + i * F));
        }
        time += X / (2 + n * F);
        return time;
    }
}
