import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class С {
    private static final String inFile = "C-small-attempt0 (1).in";
    private static final String outFile = "C-out.txt";

    private static final String[] tbl = {
        "+ijk-IJK",
        "i-kJI+Kj",
        "jK-iJk+I",
        "kjI-KJi+",
        "-IJK+ijk",
        "I+Kji-kJ",
        "Jk+IjK-i",
        "KJi+kjI-"
    };

    private static final String lookup = tbl[0];

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        int T = scanner.nextInt();
        FileWriter fw = new FileWriter(outFile);

        for (int t = 1; t <= T; ++t) {
            scanner.nextInt();
            long x = scanner.nextLong();
            String s = scanner.next();
            fw.write(String.format("Case #%d: %s\n", t, solve(x, s) ? "YES" : "NO"));
        }
        fw.close();
    }

    private static boolean solve(long x, String s) {
        String ps = build(x, s);
        long len = x * s.length();
        long start = findStart(ps, len);
        long end = findEnd(ps, len);
        if (start >= end) {
            return false;
        }
        char tot = '+';
        for (int i = 0; i < s.length(); ++i) {
            tot = mult(tot, s.charAt(i));
        }
        tot = pow(tot, x);
        return tot == '-';
    }

    static char pow(char c, long x) {
        char res = '+';
        char p = c;
        while (x > 0) {
            if (x % 2 == 1) {
                res = mult(res, p);
            }
            p = mult(p, p);
            x /= 2;
        }
        return res;
    }

    static long findStart(String s, long lastIdx) {
        char c = '+';
        for (int i = 0; i < s.length(); ++i) {
            c = mult(c, s.charAt(i));
            if (c == 'i') {
                return i;
            }
        }
        return lastIdx;
    }

    static long findEnd(String s, long lastIdx) {
        int n = s.length();
        char c = '+';
        for (int i = 0; i < s.length(); ++i) {
            c = mult(s.charAt(n - i - 1), c);
            if (c == 'k') {
                return lastIdx - i;
            }
        }
        return 0;
    }

    static String build(long x, String s) {
        StringBuilder sb = new StringBuilder();
        int u = (int)Math.max(x, 5);
        for (int i = 0; i < u; ++i) {
            sb.append(s);
        }
        return sb.toString();
    }

    static char mult(char x, char y) {
        int i = lookup.indexOf(x);
        int j = lookup.indexOf(y);
        return tbl[i].charAt(j);
    }
}
