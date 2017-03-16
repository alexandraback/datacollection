import java.io.File;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;

/**
 * @author jrenaut
 */
public class Projeto1 {

    private static final String letters = "abcdefghijklmnopqrstuvwxyz";

    private static final String example1 = "zejp mysljylc kd kxveddknmc re jsicpdrysi";

    private static final String answer1 = "qour language is impossible to understand";

    private static final String example2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";

    private static final String answer2 = "there are twenty six factorial possibilities";

    private static final String example3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

    private static final String answer3 = "so it is okay if you want to just give up";

    private static final Map<Character, Character> map = new TreeMap<Character, Character>();

    private static final Set<Character> exampleLetters = new HashSet<Character>();

    private static final Set<Character> answerLetters = new HashSet<Character>();

    public static void main(String[] args) throws Exception {

        for (int i = 0; i < letters.length(); i++) {
            exampleLetters.add(letters.charAt(i));
            answerLetters.add(letters.charAt(i));
        }

        for (int i = 0; i < example1.length(); i++) {
            char c1 = example1.charAt(i);
            char c2 = answer1.charAt(i);
            exampleLetters.remove(c1);
            answerLetters.remove(c2);
            map.put(c1, c2);
        }
        for (int i = 0; i < example2.length(); i++) {
            char c1 = example2.charAt(i);
            char c2 = answer2.charAt(i);
            exampleLetters.remove(c1);
            answerLetters.remove(c2);
            map.put(c1, c2);
        }
        for (int i = 0; i < example3.length(); i++) {
            char c1 = example3.charAt(i);
            char c2 = answer3.charAt(i);
            exampleLetters.remove(c1);
            answerLetters.remove(c2);
            map.put(c1, c2);
        }

        map.put(exampleLetters.iterator().next(), answerLetters.iterator().next());

        Scanner scan = new Scanner(new File("input"));

        int num = Integer.parseInt(scan.nextLine());
        for (int i = 1; i <= num; i++) {
            String line = scan.nextLine();
            System.out.println("Case #" + i + ": " + translate(line));
        }

    }

    private static String translate(String line) {
        String ret = "";
        for (Character c : line.toCharArray()) {
            ret += map.get(c);
        }
        return ret;
    }
}
