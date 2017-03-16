import java.util.Scanner;

public class ProblemB {

    public static void main(String[] args) throws Exception {

        long t;
        double c, x, f;

        Scanner in = new Scanner(System.in);
        
        t = in.nextInt();

        for(int t_ = 0; t_ < t; t_++) {
            c = in.nextDouble();
            f = in.nextDouble();
            x = in.nextDouble();

            double result = solve(0, 2, c, f, x);

            System.out.format("Case #%d: %.7f\n", (t_+1), result);
        }
    }

    public static double solve(double t, double r, double c, double f, double x) {

        double min_win = x / r;

        while(true) {

            t += c / r;
            r += f;

            if((x / r + t) < min_win) {
                min_win = x / r + t;
            } else {
                return min_win;
            }
        }
    }
}
