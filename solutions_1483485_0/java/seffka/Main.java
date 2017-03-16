import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

public class Main
{
    static String[] plain =
            {
                    "z",
                    "y qee",
                    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
            };

    static String[] encoded =
            {
                    "q",
                    "a zoo",
                    "our language is impossible to understand",
                    "there are twenty six factorial possibilities",
                    "so it is okay if you want to just give up"
            };

    private static Set<Character> allPlain = new LinkedHashSet<Character>();
    private static Set<Character> allEncoded = new LinkedHashSet<Character>();
    private static Map<Character, Character> translateMap = new LinkedHashMap<Character, Character>();

    public static void main(String[] args)
            throws Exception
    {
        learn();
        BufferedReader in = new BufferedReader(new FileReader(args[0]));
        FileWriter out = new FileWriter(args[1]);
        int T = Integer.parseInt(in.readLine());

        for (int t = 1; t <= T; t++)
        {
            String line = in.readLine();
            out.write("Case #" + t + ": " + encode(line) + "\n");
        }

        in.close();
        out.close();
    }

    private static String encode(String line)
    {
        StringBuilder result = new StringBuilder();
        for (int  i = 0; i < line.length(); i++)
        {
            result.append(translateMap.get(line.charAt(i)));
        }

        return result.toString();
    }

    private static void learn()
    {
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            allPlain.add(ch);
            allEncoded.add(ch);
        }

        allPlain.add(' ');
        allEncoded.add(' ');

        for (int i = 0; i < plain.length; i++) {
            for (int pos = 0; pos < plain[i].length(); pos++)
            {
                char p = plain[i].charAt(pos);
                char e= encoded[i].charAt(pos);
                allPlain.remove(p);
                allEncoded.remove(e);
                translateMap.put(p, e);
            }
        }

        if (allPlain.size() > 0)
            throw new IllegalStateException();
    }
}
