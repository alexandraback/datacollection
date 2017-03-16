import java.io.FileNotFoundException;
import java.io.FileReader;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.HashMap;
import java.util.Locale;
import java.util.Scanner;

/**
 * CodeJam 2015: Round1C-B
 * User: Mitesh, 5/10/15
 */
public class Problem1B {
    private static final boolean DEBUG = false;

    final static DecimalFormat formatter = new DecimalFormat("#.#######", DecimalFormatSymbols.getInstance(Locale.ENGLISH));

    public static void main(String[] args) throws FileNotFoundException {
        Problem1B prog = new Problem1B();

        Scanner in = new Scanner(new FileReader(args[0]));
        final int cntCases = in.nextInt();
        in.nextLine();

        for (int caseNum = 1; caseNum <= cntCases && in.hasNextLine(); caseNum++) {
            final int numK = in.nextInt();
            final int cntL = in.nextInt();
            final int maxPress = in.nextInt();
            in.nextLine(); //discard!
            final String keyset = in.nextLine();
            final String target = in.nextLine();

            double ans = prog.solve(keyset, target, maxPress);
            System.out.println("Case #" + caseNum + ": " + prog.formatFloat(ans));
        }
    }

    private double solve(String keyset, String target, int maxPress) {
        HashMap<Character, Integer> keyMap = new HashMap<>();

        for (Character key : keyset.toCharArray()) {
            int cnt = 0;
            if (keyMap.containsKey(key)) {
                cnt = keyMap.get(key);
            }
            keyMap.put(key, cnt+1);
        }

        double chances = 1.0;
        for (char c : target.toCharArray()) {
            int cnt = 0;
            if (keyMap.containsKey(c)) {
                cnt = keyMap.get(c);
            }

            double freq = ((double)cnt) / ((double)keyset.length());
            chances *= freq;
        }

        if (Math.abs(Double.compare(chances, 0.0000000)) <= 0.0000001 || (maxPress < target.length())) {
            //if no chance, then bring no bananas.
            return 0.0;
        }

        int maxFit = maxPress / target.length(); //max times you can succeed.
        int overlaps = countCharsOverlapping(target);
        if (overlaps > 0) {
            int newTargLen = target.length() - overlaps;
            newTargLen = Math.max(newTargLen, 1); //at least 1 char.
            int repeaters = (maxPress - target.length()) / newTargLen;
            maxFit = 1 + repeaters;
            //override maxFit
        }

        chances *= maxFit;

        return maxFit - chances;
    }

    private int countCharsOverlapping(String word) {

        boolean areAllSame = true;
        char c = word.charAt(0);
        for (int i = 0; i < word.length(); i++) {
            areAllSame &= (c == word.charAt(i));
        }
        if (areAllSame) return word.length();

        for (int i = (word.length()/2)-1; i > 0; i--) {
            String left = word.substring(0, i+1);
            //String right = word.substring(i, word.length());
            if (word.endsWith(left)) {
                return left.length();
            }
        }

        return 0;
    }

    private String formatFloat(double d) {
        String fmt = formatter.format(d);
        return fmt.contains(".") ? fmt : fmt + ".0";
    }
}
