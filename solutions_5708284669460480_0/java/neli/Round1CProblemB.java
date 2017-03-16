import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created by Darya Shauchenka on 5/10/2015.
 */
public class Round1CProblemB {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("B-small-attempt1.in"));
        BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
        int testCases = sc.nextInt();
        nextCase:
        for (int t = 0; t < testCases; t++) {
            int k = sc.nextInt();
            int l = sc.nextInt();
            int s = sc.nextInt();
            String keyboard = sc.next();
            String target = sc.next();
            for (int i = 0; i < l; i++) {
                if (keyboard.indexOf(target.charAt(i)) < 0) {
                    out.write("Case #" + (t + 1) + ": 0.0");
                    out.newLine();
                    continue nextCase;
                }
            }
            int repeatPos = l;
            for (int i = 1; i < l; i++) {
                if (target.lastIndexOf(target.substring(0, l - i)) == i) {
                    repeatPos = i;
                    break;
                }
            }
            int totalBananas = 1 + (s - l) / repeatPos;

            char[] typedString = new char[s];
            totalGenerations = 0;
            totalWordsInGenerations = 0;
            generateTyping(typedString, 0, keyboard, target);
            double res = totalBananas -  1.0 * totalWordsInGenerations / totalGenerations;
            out.write("Case #" + (t + 1) + ": " + (double)Math.round(1E7 * res) / 1E7);
            out.newLine();
        }
        out.close();
    }

    private static int totalGenerations;
    private static int totalWordsInGenerations;
    private static void generateTyping(char[] typedString, int currIndex, String keyboard, String word) {
        if (currIndex == typedString.length) {
            totalGenerations++;
            String str = new String(typedString);
            int i = -1;
            while ((i = str.indexOf(word, i + 1)) >= 0) {
                totalWordsInGenerations++;
            }
            return;
        }
        for (int i = 0; i < keyboard.length(); i++) {
            typedString[currIndex] = keyboard.charAt(i);
            generateTyping(typedString, currIndex + 1, keyboard, word);
        }
    }
}
