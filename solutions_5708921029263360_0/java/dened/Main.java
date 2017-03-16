import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.io.StringReader;
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
        private byte[] counts;
        private byte[] maxs;
        private int[][] combs;

        public TaskC(FastScanner in, PrintWriter out) {
            this.in = in;
            this.out = out;

            precalc(3, 3, 3);
        }

        public void solve(int testNumber) throws IOException {
            int j = in.nextInt();
            int p = in.nextInt();
            int s = in.nextInt();
            int k = in.nextInt();
            List<int[]> ans = realSolve(j, p, s, k);
            out.println("Case #" + testNumber + ": " + ans.size());
            for (int[] row : ans) {
                for (int x : row) {
                    out.print(x + 1);
                    out.print(' ');
                }
                out.println();
            }
        }

        private void precalc(int jackets, int pants, int shirts) {
            int n = jackets * pants * shirts;
            combs = new int[n][3];

            for (int i = 0; i < jackets; i++) {
                for (int j = 0; j < pants; j++) {
                    for (int k = 0; k < shirts; k++) {
                        int p = i * 3 * 3 + j * 3 + k;
                        combs[p][0] = i;
                        combs[p][1] = j;
                        combs[p][2] = k;
                    }
                }
            }

            counts = new byte[1 << n];
            maxs = new byte[1 << n];

            for (int subset = 0; subset < (1 << n); subset++) {
                int[][] comb01 = new int[jackets][pants];
                int[][] comb02 = new int[jackets][shirts];
                int[][] comb12 = new int[pants][shirts];

                int count = 0;
                int max = 0;
                for (int p = 0; p < n; p++) {
                    if (BitUtils.isSet(subset, p)) {
                        count++;

                        int i = combs[p][0];
                        int j = combs[p][1];
                        int k = combs[p][2];

                        comb01[i][j]++;
                        comb02[i][k]++;
                        comb12[j][k]++;

                        max = Math.max(max, Math.max(comb01[i][j], Math.max(comb02[i][k], comb12[j][k])));
                    }
                }

                counts[subset] = (byte) count;
                maxs[subset] = (byte) max;
            }
        }

        private List<int[]> realSolve(int jackets, int pants, int shirts, int max) {
            int set = 0;
            for (int i = 0; i < jackets; i++) {
                for (int j = 0; j < pants; j++) {
                    for (int k = 0; k < shirts; k++) {
                        int p = i * 3 * 3 + j * 3 + k;
                        set = BitUtils.setBit(set, p);
                    }
                }
            }

            int maxSet = 0;
            for (int subset = set; subset > 0; subset = (subset - 1) & set) {
                if (maxs[subset] <= max && counts[subset] > counts[maxSet]) {
                    maxSet = subset;
                }
            }

            List<int[]> ans = new ArrayList<>();
            for (int p = 0; p < 3 * 3 * 3; p++) {
                if (BitUtils.isSet(maxSet, p)) {
                    ans.add(combs[p]);
                }
            }

            return ans;
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

    static class BitUtils {
        public static boolean isSet(long number, int index) {
            if (index < 0 || index > 62) {
                throw new IndexOutOfBoundsException();
            }
            return (number & (1L << index)) != 0;
        }

        public static int setBit(int number, int index) {
            if (index < 0 || index > 62) {
                throw new IndexOutOfBoundsException();
            }
            return number | (1 << index);
        }

    }
}

