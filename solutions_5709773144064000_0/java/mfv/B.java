import java.io.*;
import java.util.*;

class B {

    Scanner in;
    PrintWriter out;

    double solveOne(double farmCost, double farmSpeed, double target) {
        double speed = 2;
        double timeBeforeLastFarm = 0;
        double minTime = Double.MAX_VALUE;
        int minTimeFarms = 0;
        for (int nFarms = 0; timeBeforeLastFarm < minTime; nFarms++) {
            double time = timeBeforeLastFarm + target / speed;
            if (time < minTime) {
                minTime = time;
                minTimeFarms = nFarms;
            }
            timeBeforeLastFarm += farmCost / speed;
            speed += farmSpeed;
        }
        // out.println("minTimeFarms = " + minTimeFarms);
        return minTime;
    }

    void solve() {
        in.useLocale(Locale.US);
        int nTests = in.nextInt();
        for (int i = 1; i <= nTests; i++) {
            out.printf(Locale.US, "Case #%d: %.7f%n", i, solveOne(in.nextDouble(), in.nextDouble(), in.nextDouble()));
        }
    }

    void run() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);
        try {
            solve();
        } finally {
            out.close();
        }
    }

    public static void main(String args[]) {
        new B().run();
    }
}
