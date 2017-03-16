package A;

import org.junit.Assert;
import org.junit.Test;

import java.util.Arrays;
import java.util.Scanner;

public class Small {
    private static final String[] DIG_NAMES = new String[]{
            "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    };

    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            final int testsNum = in.nextInt();
            for (int i = 0; i < testsNum; i++) {
                System.out.println("Case #" + (i + 1) + ": " + solve(in.next()));
            }
        }
    }

    @Test
    public void rands() {
    }

    private static String solve(String S) {
        final int[] freq = getFreqs(S);
        final int[] answer = new int[10];
        
        answer[0] = freq[toInd('Z')];
        answer[2] = freq[toInd('W')];
        answer[4] = freq[toInd('U')];
        answer[5] = freq[toInd('F')] - answer[4];
        answer[6] = freq[toInd('X')];
        answer[7] = freq[toInd('V')] - answer[5]; 
        answer[8] = freq[toInd('G')];
        
        answer[1] = freq[toInd('O')] - answer[0] - answer[2] - answer[4];
        answer[3] = freq[toInd('H')] - answer[8];
        answer[9] = freq[toInd('I')] - answer[5] - answer[6] - answer[8];
        
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < answer[i]; j++) {
                result.append(i);
            }
        }
        return result.toString();
    }

    private static int[] getFreqs(String S) {
        int[] freq = new int[26];
        for (int i = 0; i < S.length(); i++) {
            final char c = S.charAt(i);
            Assert.assertTrue(c >= 'A' && c <= 'Z');
            freq[toInd(c)]++;
        }
        return freq;
    }

    private static int toInd(char c) {
        return c - 'A';
    }
}
