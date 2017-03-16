import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A {
    private static final String[] map = new String[] {
            "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    };

    public static void main(String[] args) throws FileNotFoundException {
        FileInputStream fin = new FileInputStream("A-small-attempt0.in.txt");
        Scanner scanner = new Scanner(fin);
        FileOutputStream fout = new FileOutputStream("A-small-attempt0.out.txt");
        PrintWriter writer = new PrintWriter(fout);
        int testCount = scanner.nextInt();
        for (int testCase = 1; testCase <= testCount; ++testCase) {
            String input = scanner.next();
            writer.printf("Case #%d: %s\n", testCase, solve(input));
        }
        writer.close();
    }

    private static String solve(String s) {
        Map<Character, Integer> m = new HashMap<>();
        for (int i = 0; i < s.length(); ++i) {
            inc(m, s.charAt(i));
        }

        Map<Character, Integer> r = new HashMap<>();
        fill(m, r, 'Z', 0);
        fill(m, r, 'X', 6);
        fill(m, r, 'G', 8);
        fill(m, r, 'H', 3);
        fill(m, r, 'U', 4);
        fill(m, r, 'W', 2);
        fill(m, r, 'O', 1);
        fill(m, r, 'S', 7);
        fill(m, r, 'F', 5);
        fill(m, r, 'I', 9);

        StringBuilder b = new StringBuilder();
        for (char c = '0'; c <= '9'; ++c) {
            if (!r.containsKey(c)) {
                continue;
            }
            int cnt = r.get(c);
            for (int i = 0; i < cnt; ++i) {
                b.append(c);
            }
        }
        return b.toString();
    }

    private static void inc(Map<Character, Integer> m, char c) {
        if (!m.containsKey(c)) {
            m.put(c, 0);
        }
        m.put(c, m.get(c) + 1);
    }

    private static void dec(Map<Character, Integer> m, char c) {
        int v = m.get(c) - 1;
        if (v == 0) {
            m.remove(c);
        } else {
            m.put(c, v);
        }
    }

    private static void fill(Map<Character, Integer> m, Map<Character, Integer> r, char f, int d) {
        while (m.containsKey(f)) {
            inc(r, (char)(d + '0'));
            String s = map[d];
            for (int i = 0; i < s.length(); ++i) {
                dec(m, s.charAt(i));
            }
        }
    }
}
