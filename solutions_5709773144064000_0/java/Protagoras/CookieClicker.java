import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;

/**
 * Created by jouke on 4/12/14.
 */
public class CookieClicker {

    private static DecimalFormat format = new DecimalFormat("###.0000000");

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("input/B-small-attempt0.in"));
            BufferedWriter outputWriter = new BufferedWriter(new FileWriter(new File("output/CookieClickerOutput")));

            int testCases = scanner.nextInt();

            for (int i = 0; i < testCases; i++) {
                String output = "Case #" + (i+1) + ": " + handleTestCase(scanner);
                System.out.println(output);
                outputWriter.write(output + "\n");
            }

            scanner.close();
            outputWriter.close();

        } catch (IOException e) {
            System.out.println("IOException !!!");
        }

    }

    public static String handleTestCase(Scanner scanner) {
        double C = scanner.nextDouble();
        double F = scanner.nextDouble();
        double X = scanner.nextDouble();

        double currentProductionRate = 2.0;

        double time = 0.0;

        while (true) {
            double noFarmTime = X/currentProductionRate;
            double farmProductionTime = C/currentProductionRate;
            double farmTime = X/(currentProductionRate + F) + farmProductionTime;

            if (farmTime < noFarmTime) {
                time += farmProductionTime;
                currentProductionRate += F;
            } else {
                time += noFarmTime;
                break;
            }
        }

        return format.format(time);
    }
}
