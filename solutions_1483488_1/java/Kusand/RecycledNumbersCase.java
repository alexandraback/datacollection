package recyclednumbers;

import java.util.ArrayList;

public class RecycledNumbersCase {

    private int min;
    private int max;

    public RecycledNumbersCase(String scoreLine) {

        String[] integers = scoreLine.split(" ");
        if(integers.length > 2 || integers.length < 2) {
            throw new IllegalArgumentException("Exactly two please");
        }

        min = new Integer(integers[0]);
        max = new Integer(integers[1]);
    }

    public int recycledPairCountFromMinToMax() {
        int pairCount = 0;

        for(int i = min; i <= max; i++) {
            pairCount += cycledDigitsInRangeAndGreaterThan(i);
        }
        return pairCount;
    }

    private int cycledDigitsInRangeAndGreaterThan(final int value) {
        int matches = 0;
        final String originalValue = String.valueOf(value);
        String cycledValue = cycleFromBackToFront(originalValue);
        while(!cycledValue.equals(originalValue)) {
            int cycledVal = Integer.valueOf(cycledValue);
            if(cycledVal > value && cycledVal <= max) {
                matches++;
            }
            cycledValue = cycleFromBackToFront(cycledValue);
        }

        return matches;
    }


    public int getMin() {
        return min;
    }

    public int getMax() {
        return max;
    }

    public static String cycleFromBackToFront(String numToCycle) {
        final int numLength = numToCycle.length();
        return numToCycle.substring(numLength - 1) + numToCycle.substring(0, numLength - 1);
    }
}
