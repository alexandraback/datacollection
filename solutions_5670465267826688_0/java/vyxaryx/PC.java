import java.io.*;
import java.util.StringTokenizer;

public class PC implements Runnable {
    static String PROBLEM_NAME = PC.class.getSimpleName().toLowerCase();
    static String INPUT_FILE_NAME = PROBLEM_NAME + ".in";
    static String OUTPUT_FILE_NAME = PROBLEM_NAME + ".out";

    static class InputReader {
        final BufferedReader rd;
        StringTokenizer tok = null;

        public InputReader(String filename) throws IOException {
            rd = new BufferedReader(new FileReader(new File(filename)));
        }

        public void close() {
            try {
                rd.close();
            } catch (IOException e) {
            }
        }

        public String nextToken() throws IOException {
            while (tok == null || !tok.hasMoreTokens()) {
                tok = new StringTokenizer(rd.readLine());
            }
            return tok.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(nextToken());
        }

        public String readLine() throws IOException {
            tok = null;
            return rd.readLine();
        }

        public long nextLong() throws IOException {
            return Long.parseLong(nextToken());
        }
    }

    public static void main(String[] args) {
        try {
            new Thread(new PC()).start();
        } catch (Exception e) {
        }
    }

    @Override
    public void run() {
        try {
            solve();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    static final int[][] multiplyKind = new int[][]{
        { 0, 1, 2, 3 },
        { 1, 0, 3, 2 },
        { 2, 3, 0, 1 },
        { 3, 2, 1, 0 },
    };
    static final int[][] multiplySign = new int[][]{
        { 1, 1, 1, 1 },
        { 1,-1, 1,-1 },
        { 1,-1,-1, 1 },
        { 1, 1,-1,-1 },
    };

    static class Term {
        public int sign;
        public int kind;

        private Term(int sign, int kind) {
            this.sign = sign;
            this.kind = kind;
        }

        public static Term one() {
            return new Term(1, 0);
        }

        public static Term termI() {
            return new Term(1, 1);
        }

        public static Term termJ() {
            return new Term(1, 2);
        }

        public static Term termK() {
            return new Term(1, 3);
        }

        public Term negate() {
            return new Term(-sign, kind);
        }

        public Term multiply(Term other) {
            return new Term(sign * other.sign * multiplySign[kind][other.kind], multiplyKind[kind][other.kind]);
        }

        public boolean eq(Term other) {
            return sign == other.sign && kind == other.kind;
        }
    }

    private void solve() throws IOException {
        InputReader rd = new InputReader(INPUT_FILE_NAME);
        PrintWriter wr = new PrintWriter(new FileWriter(new File(OUTPUT_FILE_NAME)));

        int t = rd.nextInt();
        for (int ti = 0; ti < t; ++ti) {
            int l = rd.nextInt();
            long x = rd.nextLong();
            String s = rd.nextToken().trim().toLowerCase();
            Term[] terms = new Term[l];
            for (int i = 0; i < l; ++i) {
                switch (s.charAt(i)) {
                    case 'i':
                        terms[i] = Term.termI();
                        break;
                    case 'j':
                        terms[i] = Term.termJ();
                        break;
                    case 'k':
                        terms[i] = Term.termK();
                        break;
                }
            }

            boolean result = subsolve(terms, x);
            wr.println(String.format("Case #%d: %s", ti + 1, result ? "YES" : "NO"));
        }

        rd.close();
        wr.close();
    }

    private boolean subsolve(Term[] terms, long x) {
        int l = terms.length;

        Term span = Term.one();
        for (int i = 0; i < l; ++i) {
            span = span.multiply(terms[i]);
        }
        Term total = Term.one();
        for (int i = 0; i < (int)(x % 4); ++i) {
            total = total.multiply(span);
        }

        if (!total.eq(Term.one().negate())) {  // i * j * k == -1
            return false;
        }

        int bestI = -1;

        Term c = Term.one();
        for (int i = 0; i < (int)Math.min(x * l, l * 4); ++i) {
            c = c.multiply(terms[i % l]);
            if (c.eq(Term.termI())) {
                bestI = i;
                break;
            }
        }

        int bestK = -1;

        c = Term.one();
        for (int i = 0; i < (int)Math.min(x * l, l * 4); ++i) {
            c = terms[(l * 4 - i - 1) % l].multiply(c);
            if (c.eq(Term.termK())) {
                bestK = i;
                break;
            }
        }

        if (bestI == -1 || bestK == -1) {
            return false;
        }

        return bestI + bestK < x * l;
    }
}
