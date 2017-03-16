import java.text.DecimalFormat;
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        for (int caseNum = 1; caseNum <= cases; caseNum++) {
            double C = sc.nextDouble();
            double F = sc.nextDouble();
            double X = sc.nextDouble();

            double best = Double.MAX_VALUE;
            double rate = 2;
            double lastFarmTime = 0;
            for (int numFarms = 0;; numFarms++) {
                double time = X / rate + lastFarmTime;
                if (time <= best) {
                    best = time;
                } else {
                    break;
                }

                lastFarmTime += C / rate;
                rate += F;
            }

            DecimalFormat df = new DecimalFormat("0.0000000");
            System.out.println("Case #" + caseNum + ": " + df.format(best));
        }
    }
}
