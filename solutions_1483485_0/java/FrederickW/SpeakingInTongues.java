import java.io.*;
import java.util.*;
import java.util.Map.Entry;

/**
 * Created with IntelliJ IDEA.
 * User: Frederick
 * Date: 4/14/12
 * Time: 8:03 AM
 * To change this template use File | Settings | File Templates.
 */
public class SpeakingInTongues {

    private static final Map<Character, Character> mapping = new HashMap<Character, Character>();

    static {
        Map<String, String> samples = new HashMap<String, String>();
        samples.put("y qee", "a zoo");
        samples.put("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
        samples.put("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
        samples.put("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

        for (Entry<String, String> entry : samples.entrySet()) {
            char[] googlerese = entry.getKey().replaceAll(" ", "").toCharArray();
            char[] english = entry.getValue().replaceAll(" ", "").toCharArray();
            for (int i = 0; i < googlerese.length; i++) {
                mapping.put(googlerese[i], english[i]);
            }
        }

        char missingKey = ' ', missingValue = ' ';
        for (char c = 'a'; c <= 'z'; c++) {
             if (!mapping.containsKey(c)) {
                 missingKey = c;
             }
            if (!mapping.containsValue(c)) {
                missingValue = c;
            }
        }
        mapping.put(missingKey, missingValue);
    }

    private static String translate(String s) {
        StringBuffer translation = new StringBuffer();
        for (char c : s.toCharArray()) {
            if (c != ' ') {
                translation.append(mapping.get(c));
            } else {
                translation.append(' ');
            }
        }
        return translation.toString();
    }

    public static void main(String[] args) throws IOException {
        File input = new File("C:\\Users\\Frederick\\Downloads\\A-small-attempt0.in");
        File output = new File(input.getAbsolutePath() + ".out");
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(input)));
        PrintStream out = new PrintStream(output);
        int cases = Integer.parseInt(in.readLine());
        for (int i = 1; i <= cases; i++) {
            String googlerese = in.readLine();
            String english = translate(googlerese);
            out.println("Case #" + i + ": " + english);
        }
    }

}
