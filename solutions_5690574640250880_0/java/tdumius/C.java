import java.io.File;
import java.util.Arrays;
import java.util.Formatter;
import java.util.Scanner;

public class C {
    private static final String IMPOSSIBLE = "Impossible\n";
    private static final String ANS = "Case #%s:\n";

    public static void main(String[] args) throws Exception {
        try (Scanner in = new Scanner(new File("io/C/Cs.in.txt")); Formatter out = new Formatter("io/C/Cs.out.txt")) {
            int tests = in.nextInt();
            for (int i = 1; i <= tests; ++i) {
                out.format(ANS, i);
                out.format(new C(in.nextInt(), in.nextInt(), in.nextInt()).solve());
            }
        }
    }

    private int r;
    private int c;
    private int frees;
    private char[][] map;

    public C(int r, int c, int m) {
        this.r = r;
        this.c = c;
        this.frees = r * c - m;
        map = new char[r][c];
        for (char[] row : map) {
            Arrays.fill(row, '*');
        }
    }

    private String solve() {
        if (frees == 1) { return toString(map); }
        if ((r - 1) * (c - 1) == 0) {// 1D map - never impossible
            for (int i = 0; i < frees; ++i) {
                map[i / c][i % c] = '.';
            }
            return toString(map);
        }
        if (Arrays.binarySearch(new int[] { 2, 3, 5, 7 }, frees) >= 0) { return IMPOSSIBLE; }

        int row = 0;
        c = Math.min(2 * c, (frees % 2 == 1 ? frees - 2 : frees)) / 2;
        freeSegment(row++);
        freeSegment(row++);
        while (frees > 0 && row < r) {
            c = frees == c + 1 ? c - 1 : Math.min(c, frees);
            freeSegment(row++);
        }

        return frees == 0 ? toString(map) : IMPOSSIBLE;
    }

    private void freeSegment(int row) {
        Arrays.fill(map[row], 0, c, '.');
        frees -= c;
    }

    private String toString(char[][] map) {
        map[0][0] = 'c';
        StringBuilder sb = new StringBuilder(map.length * (1 + map[0].length));
        for (char[] row : map) {
            sb.append(new String(row)).append('\n');
        }
        return sb.toString();
    }
}
