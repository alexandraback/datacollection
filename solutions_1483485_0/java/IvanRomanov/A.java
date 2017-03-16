import java.io.*;
import java.util.*;

/**
 * @author Ivan Romanov
 */
public class A {

    private String SAMPLE_GOOGLERESE = "ejp mysljylc kd kxveddknmc re jsicpdrysi" +
            "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" +
            "de kr kd eoya kw aej tysr re ujdr lkgc jv";

    private String SAMPLE_ENGLISH = "our language is impossible to understand" +
            "there are twenty six factorial possibilities" +
            "so it is okay if you want to just give up";

    private Map<Character, Character> dictionary;

    private String solve() throws IOException {
        String line = reader.readLine();
        StringBuilder res = new StringBuilder();
        for (char ch : line.toCharArray()) {
            if (!dictionary.containsKey(ch)) {
                throw null;
            }
            res.append(dictionary.get(ch));
        }
        return res.toString();
    }

    private void prepare() {
        dictionary = new HashMap<Character, Character>();
        if (SAMPLE_ENGLISH.length() != SAMPLE_GOOGLERESE.length()) {
            throw null;
        }
        dictionary.put('y', 'a');
        dictionary.put('e', 'o');
        dictionary.put('q', 'z');
        for (int i = 0; i < SAMPLE_GOOGLERESE.length(); i++) {
            if ((SAMPLE_ENGLISH.charAt(i) == ' ') ^ (SAMPLE_GOOGLERESE.charAt(i) == ' ')) {
                throw null;
            }
            if (dictionary.containsKey(SAMPLE_GOOGLERESE.charAt(i)) &&
                    dictionary.get(SAMPLE_GOOGLERESE.charAt(i)) != SAMPLE_ENGLISH.charAt(i)) {
                throw null;
            }
            dictionary.put(SAMPLE_GOOGLERESE.charAt(i), SAMPLE_ENGLISH.charAt(i));
        }
        Set<Character> latin = new HashSet<Character>();
        for (char ch = 'a'; ch <= 'z'; ch++) {
            latin.add(ch);
        }
        latin.removeAll(dictionary.values());
        if (latin.size() != 1) {
            throw null;
        }
        dictionary.put('z', latin.iterator().next());
        if (dictionary.size() != 27) {
            throw null;
        }
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        String problem = "A-small-attempt1";
        reader = new BufferedReader(new FileReader(problem + ".in"));
        PrintWriter writer = new PrintWriter(new File(problem + ".out"));
        try {
            prepare();
            int tc = nextInt();
            int i = 1;
            while (i <= tc) {
                writer.print("Case #" + i + ": ");
                writer.println(solve());
                i++;
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new A().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}