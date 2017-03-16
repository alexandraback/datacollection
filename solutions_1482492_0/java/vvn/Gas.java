import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class Gas implements Runnable {
    final Scanner in;
    final PrintWriter out;

    public Gas() throws FileNotFoundException {
        out = new PrintWriter(getClass().getName().toLowerCase() + ".out");
        in = new Scanner(new File(getClass().getName().toLowerCase() + ".in"));
    }

    public static void main(String[] args) {
        try {
            new Gas().run();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        int tests = in.nextInt();
        in.useLocale(Locale.US);

        for (int testcase = 1; testcase <= tests; testcase++) {
            double d = in.nextDouble();
            int n = in.nextInt();
            int an = in.nextInt();

            double[] t = new double[n];
            double[] x = new double[n];

            for (int i = 0; i < n; i++) {
                t[i] = in.nextDouble();
                x[i] = in.nextDouble();
            }

            out.println("Case #" + testcase + ":");

            if (n > 1 && x[n - 1] > d) {
                double lv = velocity(x[n - 2], x[n - 1], t[n - 1] - t[n - 2]);
                double nt = t[n - 2] + (d - x[n - 2]) / lv;
                t[n - 1] = nt;
                x[n - 1] = d;
            }

            for (int ai = 0; ai < an; ai++) {
                double a = in.nextDouble();
                out.println(solve(t, x, a));
            }
        }

        out.close();
        in.close();
    }

    private double solve(double[] t, double[] x, double a) {
        double cx = 0;
        double v = 0;
        for (int i = 0; i < t.length - 1; i++) {
            double dt = t[i + 1] - t[i];
            double delta = getJoinTime(cx, x[i], x[i + 1], v, a, dt);

            if (delta >= dt) {
                cx = accel(cx, v, a, dt);
                v = v + a * dt;
            } else {
                cx = x[i + 1];
                v = velocity(x[i], x[i + 1], dt);
            }
        }
        return t[t.length - 1] + getComeTime(cx, v, a, x[x.length - 1]);
    }

    private double getComeTime(double cx, double v, double a, double d) {
        double l = 0;
        double r = 2 * Math.sqrt(Math.abs(2 * d * a));
        for (int i = 0; i < 100; i++) {
            double c = (l + r) / 2;
            double me = accel(cx, v, a, c);
            if (me > d) {
                r = c;
            } else {
                l = c;
            }
        }
        return l;
    }

    private double getJoinTime(double cx, double x1, double x2, double v, double a, double dt) {
        double l = 0;
        double r = dt;
        for (int i = 0; i < 100; i++) {
            double c = (l + r) / 2;
            double me = accel(cx, v, a, c);
            double he = linear(x1, x2, dt, c);
            if (me > he) {
                r = c;
            } else {
                l = c;
            }
        }
        return l;
    }

    private double accel(double cx, double v, double a, double c) {
        return cx + v * c + a * c * c / 2;
    }

    private double linear(double x1, double x2, double dt, double c) {
        return x1 + c * velocity(x1, x2, dt);
    }

    private double velocity(double x1, double x2, double dt) {
        return (x2 - x1) / dt;
    }
}
