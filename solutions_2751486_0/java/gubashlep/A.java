import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

public class A {
    private static String charsetName = "ISO-8859-1";
    private static Locale usLocale = new Locale("en", "US");

    public static void main(String[] args) throws FileNotFoundException {
        String name = "A-small-attempt0.in";

        // String name = "A.in";

        File file = new File(name);
        Scanner in = new Scanner(file, "UTF-8");
        in.useLocale(usLocale);

        int count = in.nextInt();
        String line = in.nextLine();

        Set<Character> vowels = new HashSet<Character>();
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');

        for (int caseNum = 1; caseNum <= count; caseNum++) {
            line = in.nextLine();
            String tokens[] = line.split("\\s");
            String word = tokens[0].trim();
            int N = Integer.parseInt(tokens[1]);

            int result = 0;
            for (int i = 0; i < word.length() - N + 1; i++) {
                for (int j = i + 1; j <= word.length(); j++) {
                    String subName = word.substring(i, j);
                    int curN = 0;
                    for (int k = 0; k < subName.length(); k++) {
                        if (!vowels.contains(subName.charAt(k))) {
                            curN++;
                            if (curN >= N) {
                                break;
                            }
                        } else {
                            curN = 0;
                        }
                    }
                    if (curN >= N) {
                        result++;
                    }
                }
            }
            System.out.print("Case #" + caseNum + ": " + result);
            System.out.print("\n");
            if (!in.hasNextLine()) {
                break;
            }
        }

    }
}
