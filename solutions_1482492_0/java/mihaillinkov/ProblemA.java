import java.util.Scanner;

/**
 * @Author Mikhail Linkov
 * Date: 06.05.12
 */
public class ProblemA {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);

        int testCount = scanner.nextInt();

        for (int testNum = 1; testNum < testCount + 1; testNum++) {
            double dist = Double.parseDouble(scanner.next());
            System.out.println("Case #" + testNum + ": ");
            int n = scanner.nextInt();
            int aCount = scanner.nextInt();



            double [] x = new double[n];
            double [] t = new double[n];
            double [] a = new double[aCount];

            for (int i = 0; i < n; i++) {
                t[i] = Double.parseDouble(scanner.next());
                x[i] = Double.parseDouble(scanner.next());
            }
            for (int i = 0; i < aCount; i++) {
                a[i] = Double.parseDouble(scanner.next());
            }



            for (int i = 0; i < aCount; i++) {
                double v0 = 0;
                double x0 = 0;


                double timeCur = 0;


                for (int j = 0; j < n; j++) {
                    double right = 1000000;
                    double left = 0;
                    int index = 0;

                    while (index < 1000) {
                        index++;
                        double mid = (right + left) / 2;

                        if (mid - t[j] < 0) {
                            left = mid;
                            continue;
                        }

                        if (x0 + v0 * mid + a[i] * mid * mid / 2 > x[j] + a[i] * (mid - t[j]) * (mid - t[j]) / 2) {
                            right = mid;
                        } else {
                            left = mid;
                        }
                    }

                    if (x[j] + a[i] * (left - t[j]) * (left - t[j]) / 2 > dist) {
                        continue;
                    }
                    if (j == n - 1) {
                        v0 = a[i] * (left - t[j]);
                        x0 = x[j] + a[i] * (left - t[j]) * (left - t[j]) / 2;
                        timeCur += left;
                        break;
                    }

                    if ((x[j] + a[i] * (left - t[j]) * (left - t[j]) / 2 > x[j + 1])) {
                        continue;
                    }

                    v0 = a[i] * (left - t[j]);
                    x0 = x[j] + a[i] * (left - t[j]) * (left - t[j]) / 2;
                    timeCur += left;
                }

                double right = 1000000;
                double left = 0;
                int index = 0;

                while (index < 1000) {
                    index++;
                    double mid = (right + left) / 2;

                    if (x0 + v0 * mid + a[i] * mid * mid / 2 > dist) {
                        right = mid;
                    } else {
                        left = mid;
                    }
                }


                System.out.println((timeCur + left) + " ");
            }



        }
    }
}
