package br.com.feasoft.jam;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * User: Homer
 * Date: 4/13/12
 * Time: 9:15 PM
 */
public class Dance {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int numberOfCases = scanner.nextInt();

        for (int i = 0; i < numberOfCases; i++) {
            int numberOfGooglers = scanner.nextInt();
            int surprisingScore = scanner.nextInt();
            int floorScore = scanner.nextInt();

            List<Integer> scores = new ArrayList<Integer>();
            for (int j = 0; j < numberOfGooglers; j++) {
                scores.add(scanner.nextInt());
            }

            int answer = solve(surprisingScore, floorScore, scores);
            System.out.printf("Case #%d: %d\n", i + 1, answer);
        }
    }

    private static int solve(int surprisingScoresMaxQuantity, int floorScore, List<Integer> scores) {
        int surprisingFound = 0;
        int surprisingMinScore = floorScore + 2*(floorScore-2);
        int nonSurprisingMinScore = floorScore + 2*(floorScore-1);

        if (surprisingMinScore < 0) {
            surprisingMinScore = floorScore;
        }
        if (nonSurprisingMinScore < 0) {
            nonSurprisingMinScore = floorScore;
        }

        int count = 0;
        
        for (Integer totalScore : scores) {
            if (totalScore >= nonSurprisingMinScore) {
                count++;
            } else if (totalScore >= surprisingMinScore && surprisingScoresMaxQuantity > surprisingFound) {
                count++;
                surprisingFound++;
            }
        }
        return count;
    }


}
