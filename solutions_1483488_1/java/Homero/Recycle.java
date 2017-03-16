package br.com.feasoft.jam;

import java.io.IOException;
import java.util.*;

/**
 * User: Homer
 * Date: 4/13/12
 * Time: 9:30 PM
 */
public class Recycle {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int numberOfCases = scanner.nextInt();

        for (int i = 0; i < numberOfCases; i++) {
            int number1 = scanner.nextInt();
            int number2 = scanner.nextInt();
            int answer = 0;

            Map<Integer, Set<Integer>> pairs = new HashMap<Integer, Set<Integer>>();
            for ( int j = number1; j <= number2; j++) {
                int size = Double.valueOf(Math.log10(j)).intValue();
                for (int k = 1; k <= size; k++) {
                    int number = shift(j, k);
                    if(pairs.get(j) == null) {
                        pairs.put(j, new HashSet<Integer>());
                    }
                    if (number != j && number >= number1 && number <= number2 && !pairs.get(j).contains(number)) {
                        answer++;
                        if(pairs.get(number) == null) {
                            pairs.put(number, new HashSet<Integer>());
                        }
                        pairs.get(j).add(number);
                        pairs.get(number).add(j);
                    }
                }
            }
            System.out.printf("Case #%d: %d\n", i + 1, answer);
        }
    }

    public static int shift(int number, int quantity) {
        int digits = Double.valueOf(Math.log10(number)).intValue()+1;
        int lastDigitsGoingForward = Double.valueOf(number % Math.pow(10, quantity)).intValue();
        int newFirstPart = Double.valueOf(lastDigitsGoingForward * Math.pow(10, digits-quantity)).intValue();
        int firstDigitsGoingBack = Double.valueOf(number / Math.pow(10, quantity)).intValue();
        return newFirstPart + firstDigitsGoingBack;
    }
}
