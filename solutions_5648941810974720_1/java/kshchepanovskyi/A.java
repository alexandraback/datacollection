import qualification.FastScanner;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Kostiantyn Shchepanovskyi
 */
public class A {


    private final FastScanner sc;
    private final PrintWriter pw;

    public A(String f) throws FileNotFoundException {
        sc = new FastScanner(new FileInputStream("src/main/resources/" + f + ".in"));
        pw = new PrintWriter("src/main/resources/" + f + ".out");
    }

    public static void main(String[] args) throws FileNotFoundException {
        A a = new A("A-large");
        a.solve();
        a.flush();
    }

    void solve() {

        int tests = sc.nextInt();
        for (int test = 0; test < tests; test++) {
            String s = sc.next();
            printResult(test, solution(s));
        }
    }

    private String solution(String s) {
        String[] names = new String[]{
                "ZERO",
                "ONE",
                "TWO",
                "THREE",
                "FOUR",
                "FIVE",
                "SIX",
                "SEVEN",
                "EIGHT",
                "NINE"
        };
        Map<Character, Integer> digit = new LinkedHashMap<>();
        digit.put('Z', 0); // ZERO
        digit.put('U', 4); // FOUR
        digit.put('X', 6); // SIX
        digit.put('G', 8); // EIGHT
        digit.put('F', 5); // FIVE
        digit.put('S', 7); // SEVEN
        digit.put('I', 9); // NINE
        digit.put('R', 3); // THREE
        digit.put('W', 2); // TWO
        digit.put('N', 1); // ONE

        int[] count = new int[26];
        Arrays.fill(count, 0);
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            count[id(c)]++;
        }
        int total = s.length();
        List<Integer> result = new ArrayList<>();
        while (total > 0) {
            for (Map.Entry<Character, Integer> entry : digit.entrySet()) {
                Character c = entry.getKey();
                Integer d = entry.getValue();
                if (count[id(c)] > 0) {
                    String name = names[d];
                    for (int i = 0; i < name.length(); i++) {
                        count[id(name.charAt(i))]--;
                        total--;
                    }
                    result.add(d);
                    break;
                }
            }
        }
        Collections.sort(result);
        StringBuilder sb = new StringBuilder();
        for (Integer n : result) {
            sb.append(n);
        }
        return sb.toString();
    }

    private int id(char c) {
        return c-'A';
    }


    void flush() {
        pw.close();
    }

    void printResult(int testCase, String result) {
        pw.printf("Case #%d: %s\n", testCase + 1, result);
    }

}
