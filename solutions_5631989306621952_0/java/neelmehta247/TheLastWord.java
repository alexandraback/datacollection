package RoundOneA;

import java.util.Scanner;

/**
 * Created by neel on 16/04/16 at 6:34 AM.
 */
public class TheLastWord {
    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int num_trials = s.nextInt();
        s.nextLine();
        for (int i = 0; i < num_trials; i++) {
            System.out.println("Case #" + (i + 1) + ": " + getWinningWord(s.nextLine()));
        }
    }

    public static String getWinningWord(String s) {
        String toReturn = s.substring(0, 1);
        for (int i = 1; i < s.length(); i++) {
            char x = s.charAt(i);
            char firstElement = toReturn.charAt(0);

            if (x >= firstElement) {
                toReturn = x + toReturn;
            } else {
                toReturn += x;
            }
        }
        return toReturn;
    }
}
