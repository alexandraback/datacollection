import java.util.*;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        int[] counts = new int[10];
        for (int thisNum = 1; thisNum <= numCases; thisNum++) {
            for (int i = 0; i < 10; i++)
                counts[i] = 0;
            int number = in.nextInt();
            int mult = 0;
            while (!done(counts) && mult < 10000000) {
                mult += 1;
                String nextNum = Integer.toString(number * mult);
                for (int i = 0; i < nextNum.length(); i++) {
                    int digit = Integer.parseInt(nextNum.substring(i, i + 1));
                    counts[digit] = 1;
                }
            }

            if (mult == 10000000)
                System.out.format("Case #%d: INSOMNIA\n", thisNum);
            else
                System.out.format("Case #%d: %d\n", thisNum, mult * number);

        }
    }

    private static boolean done(int[] counts) {
        int count = 0;
        for (int i = 0; i < 10; i++)
            count += counts[i];
        return count == 10;
    }

    private static String dedup(String word) {
        if (word.length() <= 1)
            return word;
        char lastChar = word.charAt(0);
        String output = "" + lastChar;
        for (int i = 1; i < word.length(); i++) {
            if (word.charAt(i) != lastChar) {
                lastChar = word.charAt(i);
                output += lastChar;
            }
        }
        return output;
    }
}
