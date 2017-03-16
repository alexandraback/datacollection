package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;

/**
 * @author Alexander Gulko
 */
@SuppressWarnings("FieldCanBeLocal")
public class A {
    @SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
    private int caseNumber;
    private static Scanner sc;
    private static PrintStream out;
    private static boolean PRINT_TO_CONSOLE = true;
//    private static boolean PRINT_TO_CONSOLE = false;

    void solve() {
        String letters = sc.nextLine();
        if (letters == null || letters.trim().isEmpty()) {
            letters = sc.nextLine();
        }

        Map<Character, Integer> map = toMap(letters);

        String res = "";

        res += checkLetter(0, "ZERO", map, 'Z');
        res += checkLetter(2, "TWO", map, 'W');
        res += checkLetter(4, "FOUR", map, 'U');
        res += checkLetter(6, "SIX", map, 'X');
        res += checkLetter(8, "EIGHT", map, 'G');

        res += checkLetter(3, "THREE", map, 'R');

        res += checkLetter(5, "FIVE", map, 'F');

        res += checkLetter(9, "NINE", map, 'I');

        res += checkLetter(7, "SEVEN", map, 'V');

        res += checkLetter(1, "ONE", map, 'E');

        char[] digits = res.toCharArray();
        Arrays.sort(digits);
        res = new String(digits);

        out.printf("%s\n", res);
    }

    private Map<Character, Integer> toMap(String letters) {
        Map<Character, Integer> map = new HashMap<>();

        for (char c : letters.toCharArray()) {
            Integer count = map.get(c);
            if (count != null) {
                map.put(c, count + 1);
            } else {
                map.put(c, 1);
            }
        }

        return map;
    }

    String checkLetter(int digit, String letters, Map<Character, Integer> map, char letter) {
        Integer countObj = map.get(letter);
        if (countObj == null || countObj == 0) {
            return "";
        }
        int count = countObj;

        for (char digitLetter : letters.toCharArray()) {
            int c = map.get(digitLetter);
            map.put(digitLetter, c - count);
        }

        String res = "";
        for (int i = 0; i < count; ++i) {
            res += digit;
        }

        return res;
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

//        String file = "test";
//        String file = "A-small-attempt0";
        String file = "A-large";

        String outFileName = file + ".out";
        out = PRINT_TO_CONSOLE ? new CJPrintStream(outFileName) : new PrintStream(outFileName);

        String inFile = file + ".in";
        sc = new Scanner(new File(inFile));

        int cases = sc.nextInt();
        for (int caseNumber = 1; caseNumber <= cases; ++caseNumber) {
            out.printf("Case #%s: ", caseNumber);
            A template = new A();
            template.caseNumber = caseNumber;
            template.solve();
            out.flush();
        }

        sc.close();
    }

    static class CJPrintStream extends PrintStream {
        public CJPrintStream(String fileName) throws FileNotFoundException {
            super(fileName);
        }

        @SuppressWarnings("NullableProblems")
        @Override
        public PrintStream printf(String format, Object... args) {
            System.out.printf(format, args);
            return super.printf(format, args);
        }

        @Override
        public void println() {
            System.out.println();
            super.println();
        }

        @Override
        public void flush() {
            System.out.flush();
            super.flush();
        }
    }
}
