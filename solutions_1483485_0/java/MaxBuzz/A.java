import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class A {
    private Map<Character, Character> guessMapping(String... pairs) {
        Map<Character, Character> rv = new HashMap<Character, Character>();
        for (int i = 0; i < pairs.length; i += 2) {
            String from = pairs[i];
            String to = pairs[i + 1];
            if (from.length() != to.length()) {
                throw new AssertionError();
            }
            for (int j = 0; j < to.length(); ++j) {
                char f = from.charAt(j);
                char t = to.charAt(j);
                if (rv.containsKey(f) && rv.get(f) != t) {
                    throw new AssertionError();
                } else {
                    rv.put(f, t);
                }
            }
        }
        rv.put('z', 'q');
        rv.put('q', 'z');
        for (char c = 'a'; c <= 'z'; ++c) {
            if (!rv.containsKey(c)) {
                System.out.println("Incomplete mapping: " + c);
                ArrayList<Character> values = new ArrayList<Character>(rv.values());
                Collections.sort(values);
                System.out.println(values);
            }
        }

        return rv;
    }

    public void run(Scanner in, PrintWriter out, int nCase) {
        Map<Character, Character> mapping = guessMapping(
                "ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand",
                "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities",
                "de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up"
        );

        String line = in.nextLine();
        out.print("Case #" + nCase + ": ");
        for (int i = 0; i < line.length(); ++i) {
            out.print(mapping.get(line.charAt(i)));
        }
        out.println();
    }

    public static void main(String[] args) throws FileNotFoundException {
        String filename = A.class.getSimpleName().toLowerCase();

        Scanner in = new Scanner(new File(filename + ".in"));
        PrintWriter out = new PrintWriter(filename + ".out");

        int nCases = in.nextInt(); in.nextLine();

        for (int i = 1; i <= nCases; ++i) {
            new A().run(in, out, i);
        }

        out.close();
        in.close();
    }
}
