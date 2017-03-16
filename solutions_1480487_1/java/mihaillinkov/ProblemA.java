import java.util.Scanner;

/**
 * @Author Mikhail Linkov
 * Date: 05.05.12
 */
public class ProblemA {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);


        int testCount = scanner.nextInt();

        for (int test = 1; test < testCount + 1; test++) {

            int eliminatedCount = scanner.nextInt();

            int [] point = new int[eliminatedCount];

            int sum = 0;

            for (int i = 0; i < eliminatedCount; i++) {
                point[i] = scanner.nextInt();
                sum += point[i];
            }

            double [] percent = new double[eliminatedCount];

            double left = 0;
            double right = 10000;
            int index = 0;
            while (index < 1000) {
                index++;

                double mid = (right + left) / 2;

                double percentSum = 0.0;

                for (int i = 0; i < eliminatedCount; i++) {
                    percent[i] = (mid - point[i]) / sum;
                    if (percent[i] < 0.0) {
                        percent[i] = 0.0;
                    }
                    percentSum += percent[i];
                }

                if (percentSum > 1) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            System.out.print("Case #" + test +": ");
            for (int i = 0; i < eliminatedCount; i++) {
                System.out.print(percent[i] * 100 + " ");
            }
            System.out.println();
        }
    }
}
