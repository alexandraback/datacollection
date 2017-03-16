import java.text.DecimalFormat;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        for (int t = 0; t < T; t++) {
            int A = s.nextInt();
            int B = s.nextInt();
            double[] ps = new double[A];
            double allGood = 1;
            double allBad = 1;
            for (int i = 0; i < A; i++) {
                ps[i] = s.nextDouble();
                allGood *= ps[i];
                allBad *= 1 - ps[i];
            }

            double[] cummulative = new double[A + 1];
            cummulative[0] = 0;
            cummulative[1] = ps[0];
            for (int i = 2; i <= A; i++) {
                cummulative[i] = cummulative[i - 1] * ps[i - 1];
            }

            //case 1: press enter right away:
            double enterRightAway = B + 2;
            double enterWhenAllCorrect = (B - A + 1) * allGood + (B - A + B + 2) * (1 - allGood);

            double min = Math.min(enterRightAway, enterWhenAllCorrect);
            for (int i = 1; i < A; i++) {
                // i = number of backspaces
                double eraseIandOk = cummulative[A - i] * (2 * i + 1 + B - A);
                double eraseIandRepeat = (1 - cummulative[A - i]) * ((2 * i + 1 + B - A) + B + 1);

                min = Math.min(min, eraseIandOk + eraseIandRepeat);
            }

            min = Math.min(min, A + B + 1); // erasing all elements
            DecimalFormat myFormatter = new DecimalFormat("0.000000");
            System.out.println("Case #" + (t + 1) + ": " + myFormatter.format(min));
        }
    }
}
