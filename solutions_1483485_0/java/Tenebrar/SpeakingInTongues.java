
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;

/**
 *
 * @author peterboyen
 */
public class SpeakingInTongues {

    public static void main(String[] args) throws Exception {
        char[] mapping = new char[26];

        mapping['y' - 'a'] = 'a';
        mapping['e' - 'a'] = 'o';
        mapping['q' - 'a'] = 'z';

        String s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
        String s2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
        String s3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

        String t1 = "our language is impossible to understand";
        String t2 = "there are twenty six factorial possibilities";
        String t3 = "so it is okay if you want to just give up";

        add(mapping, s1, t1);
        add(mapping, s2, t2);
        add(mapping, s3, t3);

        mapping['z' - 'a'] = 'q';

        BufferedReader br = new BufferedReader(new FileReader("/Users/peterboyen/Downloads/A-small-attempt0.in"));

        String line = br.readLine();

        int testCases = Integer.parseInt(line);

        PrintStream ps = new PrintStream("/Users/peterboyen/Downloads/A-small-attempt0.out");
        for (int i = 1; i <= testCases; i++) {
            line = br.readLine();

            ps.println("Case #" + i + ": " + solve(line, mapping));
        }

        br.close();
        ps.close();
    }

    private static void add(char[] mapping, String s1, String t1) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != ' ') {
                mapping[s1.charAt(i) - 'a'] = t1.charAt(i);
            }
        }
    }

    private static String solve(String line, char[] mapping) {
        String result = "";

        for (int i = 0; i < line.length(); i++) {
            if (line.charAt(i) == ' ') {
                result += " ";
            }
            else
                result += mapping[line.charAt(i) - 'a'];
        }

        return result;
    }
}
