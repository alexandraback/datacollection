import java.util.Scanner;


public class GCJ2014QualB {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            System.out.printf("Case #%d: %.7f%n", i, new GCJ2014QualB().solve(sc));
        }
    }

    private double solve(Scanner sc) throws Exception {
        double c = sc.nextDouble();
        double f = sc.nextDouble();
        double x = sc.nextDouble();

        double cps = 2;
        double ans = 100000000;
        double prevSec = 0;
        for (int numFarm = 0; numFarm < x; numFarm++) {
            cps = 2 + f * numFarm;
            if (ans < prevSec + x / cps) break;
            ans = prevSec + x / cps;
            double secToBuyAnotherFarm = c / cps;
            prevSec += secToBuyAnotherFarm;
        }
        return ans;
    }
}
