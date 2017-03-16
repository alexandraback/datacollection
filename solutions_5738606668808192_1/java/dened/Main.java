import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.stream.IntStream;
import java.util.Set;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.stream.Collectors;
import java.util.HashSet;
import java.util.stream.Stream;
import java.io.StringReader;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Denis Nedelyaev
 */
public class Main {
    public static void main(String[] args) throws Exception {
        Locale.setDefault(Locale.US);
        final String regex = "C-(small|large).*[.]in";
        File directory = new File(".");
        File[] candidates = directory.listFiles(new FilenameFilter() {
            public boolean accept(File dir, String name) {
                return name.matches(regex);
            }
        });
        File toRun = null;
        for (File candidate : candidates) {
            if (toRun == null || candidate.lastModified() > toRun.lastModified())
                toRun = candidate;
        }
        InputStream inputStream = new FileInputStream(toRun);
        OutputStream outputStream = new FileOutputStream("c.out");
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC(in, out);
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i);
        out.close();
    }

    static class TaskC {
        private final FastScanner in;
        private final PrintWriter out;

        public TaskC(FastScanner in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        public void solve(int testNumber) throws IOException {
            int n = in.nextInt();
            int m = in.nextInt();
            out.println("Case #" + testNumber + ":");
            realSolve(n, m);
        }

        private void realSolve(int n, int m) {
            long k = (1L << (n / 2)) | 1;
            String ks = Long.toBinaryString(k);

            String d = IntStream.range(2, 11)
                    .mapToObj(b -> new BigInteger(ks, b))
                    .map(BigInteger::toString)
                    .collect(Collectors.joining(" "));

            Set<String> memo = new HashSet<>();

            for (int x = 0; x < m; x++) {
                long y = (1L << (n / 2 - 1)) | (x << 1) | 1;
                long z = (y << (n / 2)) | y;
                String zs = Long.toBinaryString(z);

                if (zs.charAt(0) != '1') {
                    throw new AssertionError(zs);
                }

                if (zs.charAt(zs.length() - 1) != '1') {
                    throw new AssertionError(zs);
                }

                if (memo.contains(zs)) {
                    throw new AssertionError(zs);
                }

                for (int b = 2; b <= 10; b++) {
                    BigInteger zb = new BigInteger(zs, b);
                    BigInteger db = new BigInteger(ks, b);

                    if (db.compareTo(BigInteger.ONE) <= 0) {
                        throw new AssertionError(zs);
                    }

                    if (db.compareTo(zb) >= 0) {
                        throw new AssertionError(zs);
                    }

                    if (!zb.mod(db).equals(BigInteger.ZERO)) {
                        throw new AssertionError(zs);
                    }
                }

                out.println(zs + " " + d);

                memo.add(zs);
            }
        }

    }

    static class FastScanner {
        private final BufferedReader br;
        private String line;
        private int pos;

        public FastScanner(String s) throws IOException {
            this(new StringReader(s));
        }

        public FastScanner(InputStream is) throws IOException {
            this(new InputStreamReader(is, "UTF-8"));
        }

        public FastScanner(Reader reader) throws IOException {
            this(new BufferedReader(reader));
        }

        public FastScanner(BufferedReader reader) throws IOException {
            br = reader;
            line = br.readLine();
            pos = 0;
        }

        public String next() throws IOException {
            if (!skipWhitespace()) {
                return null;
            }

            int start = pos;

            while (pos < line.length()) {
                char c = line.charAt(pos);

                if (c == ' ' || c == '\t') {
                    break;
                }

                pos++;
            }

            return line.substring(start, pos);
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        private boolean skipWhitespace() throws IOException {
            while (line != null) {
                while (pos < line.length()) {
                    char c = line.charAt(pos);

                    if (c != ' ' && c != '\t') {
                        return true;
                    }

                    pos++;
                }

                line = br.readLine();
                pos = 0;
            }

            return false;
        }

    }
}

