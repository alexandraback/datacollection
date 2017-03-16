import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.stream.Collectors;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;
import java.io.StringReader;
import java.io.BufferedReader;
import java.util.Collections;
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
        final String regex = "A-(small|large).*[.]in";
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
        OutputStream outputStream = new FileOutputStream("a.out");
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA(in, out);
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i);
        out.close();
    }

    static class TaskA {
        private final FastScanner in;
        private final PrintWriter out;

        public TaskA(FastScanner in, PrintWriter out) {
            this.in = in;
            this.out = out;
        }

        public void solve(int testNumber) throws IOException {
            char[] digits = in.next().toCharArray();
            out.println("Case #" + testNumber + ": " + realSolve(digits));
        }

        private String realSolve(char[] digits) {
            int[] counts = new int[256];
            for (char digit : digits) {
                counts[digit]++;
            }

            List<Integer> number = new ArrayList<>();
            while (counts['Z'] > 0) {
                number.add(0);

                counts['Z']--;
                counts['E']--;
                counts['R']--;
                counts['O']--;
            }
            while (counts['W'] > 0) {
                number.add(2);

                counts['T']--;
                counts['W']--;
                counts['O']--;
            }
            while (counts['U'] > 0) {
                number.add(4);

                counts['F']--;
                counts['O']--;
                counts['U']--;
                counts['R']--;
            }
            while (counts['X'] > 0) {
                number.add(6);

                counts['S']--;
                counts['I']--;
                counts['X']--;
            }
            while (counts['G'] > 0) {
                number.add(8);

                counts['E']--;
                counts['I']--;
                counts['G']--;
                counts['H']--;
                counts['T']--;
            }
            while (counts['O'] > 0) {
                number.add(1);

                counts['O']--;
                counts['N']--;
                counts['E']--;
            }
            while (counts['T'] > 0) {
                number.add(3);

                counts['T']--;
                counts['H']--;
                counts['R']--;
                counts['E']--;
                counts['E']--;
            }
            while (counts['F'] > 0) {
                number.add(5);

                counts['F']--;
                counts['I']--;
                counts['V']--;
                counts['E']--;
            }
            while (counts['S'] > 0) {
                number.add(7);

                counts['S']--;
                counts['E']--;
                counts['V']--;
                counts['E']--;
                counts['N']--;
            }
            while (counts['N'] > 0) {
                number.add(9);

                counts['N']--;
                counts['I']--;
                counts['N']--;
                counts['E']--;
            }

            Collections.sort(number);
            return number.stream().map(Object::toString).collect(Collectors.joining());
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

