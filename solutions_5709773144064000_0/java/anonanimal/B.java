import java.util.Scanner;

public class B {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            System.out.printf("Case #%d: ", t);
            solve(in);
        }

    }

    public static void solve(Scanner in) {

        double C = in.nextDouble();// Cost of farm
        double F = in.nextDouble(); // F per second
        double X = in.nextDouble(); // Goal

        double rate = 2;
        double time = 0;
        double best = Double.MAX_VALUE;

        while (true) {
            double timeToFarm = C / rate;
            double timeToX = X / rate;

            double candidate = time + timeToX;
            best = Math.min(candidate, best);

            if (time > best) {
                break;
            }

            time += timeToFarm;
            rate += F;
        }
        System.out.printf("%.7f\n", best);

    }

}
