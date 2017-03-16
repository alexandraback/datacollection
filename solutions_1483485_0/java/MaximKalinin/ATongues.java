import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ATongues {
    public static void main(String[] args) throws IOException {
        Map<Character, Character> translate = new HashMap<Character, Character>();
        translate.put('y', 'a');
        translate.put('e', 'o');
        translate.put('q', 'z');
        String[] googlerese = new String[]{"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
        String[] english = new String[]{"our language is impossible to understand",
                "there are twenty six factorial possibilities",
                "so it is okay if you want to just give up"};

        for (int i = 0; i < 3; ++i) {
            populateMap(googlerese[i], english[i], translate);
        }

        char from = ' ', to = ' ';
        for (char i = 'a'; i <= 'z'; ++i) {
            if (!translate.containsKey(i)) {
                from = i;
            }
            if (!translate.containsValue(i)) {
                to = i;
            }
        }
        if (from == ' ' || to == ' ') {
            throw new RuntimeException("???");
        }
        translate.put(from, to);
        translate.put(' ', ' ');

        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("asmall.in")));

        PrintWriter out = new PrintWriter("asmall.out");
        int T = Integer.parseInt(in.readLine());
        for (int i = 1; i <= T; ++i) {
            String g = in.readLine();
            String e = gToE(g, translate);
            out.println("Case #" + i + ": " + e);
        }

        out.close();
    }

    private static String gToE(String g, Map<Character, Character> translate) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < g.length(); ++i) {
            sb.append(translate.get(g.charAt(i)));
        }
        return sb.toString();
    }

    private static void populateMap(String g, String e, Map<Character, Character> translate) {
        if (g.length() != e.length()) {
            throw new RuntimeException(g + "->" + e);
        }
        for (int i = 0; i < g.length(); ++i) {
            if ( (g.charAt(i) == ' ') != (e.charAt(i) == ' ')) {
                throw new RuntimeException("Unmatched spaces");
            }
            if (g.charAt(i) != ' ') {
                char from = g.charAt(i), to = e.charAt(i);
                Character toChecked = translate.get(from);
                if (toChecked != null && !toChecked.equals(to)) {
                    throw new RuntimeException("Mismatched: " + from + " " + toChecked + " " + to);
                }
                translate.put(from, to);
            }
        }
    }
}
