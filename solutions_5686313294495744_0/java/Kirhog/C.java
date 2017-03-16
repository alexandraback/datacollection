package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;
import java.util.regex.Pattern;

/**
 * @author Alexander Gulko
 */
@SuppressWarnings("FieldCanBeLocal")
public class C {
    @SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
    private int caseNumber;
    private static Scanner sc;
    private static PrintStream out;
    private static boolean PRINT_TO_CONSOLE = true;
//    private static boolean PRINT_TO_CONSOLE = false;

    private static final Pattern WORD_PATTERN = Pattern.compile("[A-Z]+");
    private Map<String, Integer> words;

    void solve() {
        int n = sc.nextInt();

        words = new HashMap<>();

        int[] first = new int[n];
        int[] second = new int[n];
        for (int i = 0; i < n; ++i) {
            first[i] = getWordNum(sc.next(WORD_PATTERN));
            second[i] = getWordNum(sc.next(WORD_PATTERN));
        }

        int[] notFake = new int[n];
        int notFakeC;
        int[] fake = new int[n];
        int fakeC;

        int max = 0;

        for (int mask = 0, end = 1 << n; mask < end; ++mask) {
            notFakeC = 0;
            fakeC = 0;

            for (int i = 0; i < n; ++i) {
                boolean isFake = ((1 << i) & mask) != 0;
                if (isFake) {
                    fake[fakeC++] = i;
                } else {
                    notFake[notFakeC++] = i;
                }
            }

            if (notFakeC == 0) {
                continue;
            }

            boolean good = true;
            for (int k = 0; k < fakeC && good; ++k) {
                int fakeInd = fake[k];
                boolean foundFirst = false;
                boolean foundSecond = false;
                for (int j = 0; j < notFakeC && (!foundFirst || !foundSecond); ++j) {
                    int notFakeInd = notFake[j];
                    if (first[fakeInd] == first[notFakeInd]) {
                        foundFirst = true;
                    }
                    if (second[fakeInd] == second[notFakeInd]) {
                        foundSecond = true;
                    }
                }

                if (!foundFirst || !foundSecond) {
                    good = false;
                }
            }

            if (good) {
                max = Math.max(max, fakeC);
            }
        }

//        out.printf("%s\n", Arrays.toString(first) + " !!! " + Arrays.toString(second));
        out.printf("%d\n", max);
    }

    int getWordNum(String word) {
        Integer num = words.get(word);
        if (num == null) {
            num = words.size();
            words.put(word, num);
        }

        return num;
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

//        String file = "test";
        String file = "C-small-attempt0";

        String outFileName = file + ".out";
        out = PRINT_TO_CONSOLE ? new CJPrintStream(outFileName) : new PrintStream(outFileName);

        String inFile = file + ".in";
        sc = new Scanner(new File(inFile));

        int cases = sc.nextInt();
        for (int caseNumber = 1; caseNumber <= cases; ++caseNumber) {
            out.printf("Case #%s: ", caseNumber);
            C template = new C();
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
