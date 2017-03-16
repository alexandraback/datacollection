package oneb;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class QuestionB {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numTests = sc.nextInt();
        for (int numTest = 0; numTest < numTests; numTest++) {
            int numBuildings = sc.nextInt();
            long numPaths = sc.nextLong();
            String answer = solve(numBuildings, BigInteger.valueOf(numPaths));
            System.out.format("Case #%d: %s%n", numTest + 1, answer);
        }
    }

    private static String solve(int numBuildings, BigInteger numPaths) {
        BigInteger maxPossiblePaths = BigInteger.valueOf(2).pow(numBuildings - 2);
        if (numPaths.compareTo(maxPossiblePaths) > 0) {
            return "IMPOSSIBLE";
        }

        StringBuilder answer = new StringBuilder();
        answer.append("POSSIBLE");
        answer.append("\n");
        answer.append('0');
        if (numPaths.equals(maxPossiblePaths)) {
            char[] allSlides = new char[numBuildings - 1];
            Arrays.fill(allSlides, '1');
            answer.append(allSlides);
        } else {
            String numPathsAsBitString = numPaths.toString(2);
            // Pad bit string with 0s. It should have length numBuildings - 2
            StringBuilder prefix = new StringBuilder();
            for (int i = 0; i < (numBuildings - 2) - numPathsAsBitString.length(); i++) {
                prefix.append('0');
            }
            answer.append(prefix);
            answer.append(numPathsAsBitString);
            answer.append('0');
        }
        answer.append("\n");
        for (int numBuilding = 2; numBuilding <= numBuildings; numBuilding++) {
            char[] prefix = new char[numBuilding];
            Arrays.fill(prefix, '0');
            answer.append(new String(prefix));
            if (numBuilding < numBuildings) {
                char[] suffix = new char[numBuildings - numBuilding];
                Arrays.fill(suffix, '1');
                answer.append(new String(suffix));
                answer.append("\n");
            }
        }
        return answer.toString();
    }
}
