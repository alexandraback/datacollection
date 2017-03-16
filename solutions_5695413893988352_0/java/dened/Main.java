import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.StringReader;
import java.io.IOException;
import java.io.Reader;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        final String regex = "B-(small|large).*[.]in";
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
        OutputStream outputStream = new FileOutputStream("b.out");
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB(in, out);
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i);
        out.close();
    }

    static class TaskB {
        private final FastScanner in;
        private final PrintWriter out;
        private char[] a;
        private char[] b;

        public TaskB(FastScanner in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        public void solve(int testNumber) throws IOException {
            a = in.next().toCharArray();
            b = in.next().toCharArray();
            out.println("Case #" + testNumber + ": " + realSolve());
        }

        private String realSolve() {
            int p = 1;
            for (int i = 0; i < a.length; i++) {
                p *= 10;
            }
            int minDif = 1000000000;
            String resa = "";
            String resb = "";
            for (int x = 0; x < p; x++) {
                for (int y = 0; y < p; y++) {
                    String xs = Integer.toString(x);
                    String ys = Integer.toString(y);
                    while (xs.length() < a.length) {
                        xs = "0" + xs;
                    }
                    while (ys.length() < a.length) {
                        ys = "0" + ys;
                    }
                    if (check(xs, a) && check(ys, b)) {
                        if (Math.abs(x - y) < minDif) {
                            resa = xs;
                            resb = ys;
                            minDif = Math.abs(x - y);
                        }
                    }
                }
            }

            return resa + " " + resb;
        }

        private boolean check(String xs, char[] a) {
            char[] b = xs.toCharArray();
            for (int i = 0; i < a.length; i++) {
                if (a[i] != b[i] && a[i] != '?') {
                    return false;
                }
            }
            return true;
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

