import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by jouke on 4/13/14.
 */
public class DeceitfulWar {

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(new File("input/D-large.in"));
            BufferedWriter outputWriter = new BufferedWriter(new FileWriter(new File("output/DeceitfulWarOutput")));

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
        int n = scanner.nextInt();

        double[] naomiWeights = new double[n];
        double[] kenWeights = new double[n];

        for (int i = 0; i < n; i++) {
            naomiWeights[i] = scanner.nextDouble();
        }
        for (int i = 0; i < n; i++) {
            kenWeights[i] = scanner.nextDouble();
        }

        //sort by weight
        Arrays.sort(naomiWeights);
        Arrays.sort(kenWeights);

        int w = n, dw = 0;

        for (int i = 0, j = 0; i < n; i++) {
            if (naomiWeights[i] > kenWeights[j]) {
                dw++;
                j++;
            }
        }

        for (int i = 0, j = 0; i < n; i++) {
            if (kenWeights[i] > naomiWeights[j]) {
                w--;
                j++;
            }
        }
        return String.valueOf(dw) + " " + String.valueOf(w);
    }
}
