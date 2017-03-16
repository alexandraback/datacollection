package gcj14.qualification;

import java.util.Scanner;

public class CookieClicker {
    void solve(Scanner scan) {
        double C = scan.nextDouble();
        double F = scan.nextDouble();
        double X = scan.nextDouble();
        double S = 2;
        double T = 0;
        final double error = 1e-9;

        while (true) {
            if (X / S + error <= C / S + X / (S + F)) {
                T += X / S;
                break;
            }
            T += C / S;
            S += F;
        }

        System.out.println(String.format("%.7f", T));
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: ", i);
            new CookieClicker().solve(scan);
        }
    }
}
