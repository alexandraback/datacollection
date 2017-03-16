package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;
import java.util.regex.Pattern;

/**
 * @author Alexander Gulko
 */
@SuppressWarnings("FieldCanBeLocal")
public class BLarge {
    public static final char Q = '?';
    @SuppressWarnings({"FieldCanBeLocal", "UnusedDeclaration"})
    private int caseNumber;
    private static Scanner sc;
    private static PrintStream out;
    private static boolean PRINT_TO_CONSOLE = true;
//    private static boolean PRINT_TO_CONSOLE = false;

    public static final int UNKNOWN = 0;
    public static final int MAX = 1;
    public static final int MIN = 2;

    private static final Pattern WORD_PATTERN = Pattern.compile("[?0-9]+");
    private int n;
    private long best1;
    private long best2;
    private long best;
    private long[] pows10;

    void solve() {
        String pattern1 = sc.next(WORD_PATTERN);
        String pattern2 = sc.next(WORD_PATTERN);

        n = pattern1.length();
        String sFormat = "%0" + n + "d";

        long pow10 = (long) Math.pow(10, n);
        pows10 = new long[n];
        pows10[0] = 1;
        for (int i = 1; i < n; ++i) {
            pows10[i] = pows10[i - 1] * 10;
        }
        best1 = pow10;
        best2 = pow10;
        best = pow10;

        char[] res1 = new char[n];
        Arrays.fill(res1, '0');
        char[] res2 = new char[n];
        Arrays.fill(res2, '0');

        go(0, pattern1.toCharArray(), pattern2.toCharArray(), 0);

        out.printf(sFormat + " " + sFormat + "\n", best1, best2);
//        out.printf("%s %s\n", new String(res1), new String(res2));
    }

    long toLong(char[] ns) {
        long pow = 1;
        long res = 0;
        for (int i = n - 1; i >= 0; --i) {
            res += (ns[i] - '0') * pow;
            pow *= 10;
        }

        return res;
    }

    void go(int i, char[] n1s, char[] n2s, int dir1) {
        if (i == n) {
            long n1 = toLong(n1s);
            long n2 = toLong(n2s);

            long diff = Math.abs(n1 - n2);
            if (diff < best) {
                best = diff;
                best1 = n1;
                best2 = n2;
            } else if (diff == best) {
                if (n1 < best1) {
                    best1 = n1;
                    best2 = n2;
                } else if (n1 == best1) {
                    if (n2 < best2) {
                        best2 = n2;
                    }
                }
            }
            return;
        }

        char c1 = n1s[i];
        char c2 = n2s[i];

        if (c1 == Q && c2 == Q) {
            if (dir1 == UNKNOWN) {
                // 0 0
                n1s[i] = '0';
                n2s[i] = '0';
                go(i + 1, n1s, n2s, dir1);
                if (i < n - 1) {
                    // 1 0 > MIN MAX
                    n1s[i] = '1';
                    n2s[i] = '0';
                    go(i + 1, n1s, n2s, MIN);
                    // 0 1 > MAX MIN
                    n1s[i] = '0';
                    n2s[i] = '1';
                    go(i + 1, n1s, n2s, MAX);
                } else {
                    // 1 0 > MIN MAX
                    n1s[i] = '9';
                    n2s[i] = '0';
                    go(i + 1, n1s, n2s, MIN);
                    // 0 1 > MAX MIN
                    n1s[i] = '0';
                    n2s[i] = '9';
                    go(i + 1, n1s, n2s, MAX);
                }
            } else if (dir1 == MAX) { // dir2 = min
                // 9 0 > MAX MIN
                n1s[i] = '9';
                n2s[i] = '0';
                go(i + 1, n1s, n2s, dir1);
            } else {
                // 0 9 > MIN MAX
                n1s[i] = '0';
                n2s[i] = '9';
                go(i + 1, n1s, n2s, dir1);
            }
        } else if (c1 == Q) {
            if (dir1 == UNKNOWN) {
                // 0
                n1s[i] = c2;
                go(i + 1, n1s, n2s, dir1);
                if (c2 != '9') {
                    // 1 0 > MIN MAX
                    n1s[i] = (char) (c2 + 1);
                    go(i + 1, n1s, n2s, MIN);
                }
                if (c2 != '0') {
                    // 0 1 > MAX MIN
                    n1s[i] = (char) (c2 - 1);
                    go(i + 1, n1s, n2s, MAX);
                }
            } else if (dir1 == MAX) { // dir2 = min
                // 9 0 > MAX MIN
                n1s[i] = '9';
                go(i + 1, n1s, n2s, dir1);
            } else {
                // 0 9 > MIN MAX
                n1s[i] = '0';
                go(i + 1, n1s, n2s, dir1);
            }
        } else if (c2 == Q) {
            if (dir1 == UNKNOWN) {
                // 0
                n2s[i] = c1;
                go(i + 1, n1s, n2s, dir1);
                if (c1 != '9') {
                    // 0 1 > MAX MIN
                    n2s[i] = (char) (c1 + 1);
                    go(i + 1, n1s, n2s, MAX);
                }
                if (c1 != '0') {
                    // 1 0 > MIN MAX
                    n2s[i] = (char) (c1 - 1);
                    go(i + 1, n1s, n2s, MIN);
                }
            } else if (dir1 == MAX) { // dir2 = min
                // 9 0 > MAX MIN
                n2s[i] = '0';
                go(i + 1, n1s, n2s, dir1);
            } else {
                // 0 9 > MIN MAX
                n2s[i] = '9';
                go(i + 1, n1s, n2s, dir1);
            }
        } else {
            if (dir1 == UNKNOWN && c1 != c2) {
                if (c1 < c2) {
                    go(i + 1, n1s, n2s, MAX);
                } else {
                    go(i + 1, n1s, n2s, MIN);
                }
            } else {
                go(i + 1, n1s, n2s, dir1);
            }
        }

        n1s[i] = c1;
        n2s[i] = c2;
    }

    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);

//        String file = "test";
//        String file = "B-small-attempt0";
//        String file = "B-small-attempt1";
        String file = "B-large";

        String outFileName = file + ".out";
        out = PRINT_TO_CONSOLE ? new CJPrintStream(outFileName) : new PrintStream(outFileName);

        String inFile = file + ".in";
        sc = new Scanner(new File(inFile));

        int cases = sc.nextInt();
        for (int caseNumber = 1; caseNumber <= cases; ++caseNumber) {
            out.printf("Case #%s: ", caseNumber);
            BLarge template = new BLarge();
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
