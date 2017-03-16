package jam2012.dancers;

import java.io.File;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

import commons.FileUtilities;

public class GoogleDancers {

    public static void main(String[] args) throws IOException {

        List<String> strings = FileUtilities.readFile(new File(
                "B-small-attempt1.in"));

        int number = Integer.parseInt(strings.get(0));

        List<String> result = new LinkedList<String>();

        for (int i = 1; i <= number; i++) {

            Scanner s = new Scanner(strings.get(i));

            int dancers = s.nextInt();
            int surprisingAmount = s.nextInt();
            int atLeast = s.nextInt();

            int[] values = new int[dancers];
            for (int j = 0; j < dancers; j++) {
                values[j] = s.nextInt();
            }
            int[] minvalues = new int[dancers];
            boolean[] cansurprise = new boolean[dancers];
            int tresult = 0;

            // Unsurprising values
            for (int j = 0; j < dancers; j++) {
                int minAmount = values[j] / 3;
                int rest = values[j] - (minAmount * 3);
                if (rest > 0) {
                    minAmount++;
                }
                if (rest != 1 && values[j] > 1 && values[j] < 28) {
                    cansurprise[j] = true;
                }
                minvalues[j] = minAmount;
                if (minAmount >= atLeast) {
                    tresult++;
                }
            }
            for (int j = 0; j < dancers; j++) {
                if (surprisingAmount > 0 && atLeast == minvalues[j] + 1 && cansurprise[j]) {

                    surprisingAmount--;
                    tresult++;
                }
            }
            result.add(Integer.toString(tresult));
        }
        FileUtilities.writeFile(result, new File("B-small-attempt1.out"));
    }
}
