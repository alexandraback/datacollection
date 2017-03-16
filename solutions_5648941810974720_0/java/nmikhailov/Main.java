import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Nikita Mikhailov
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
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
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("a.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            String token = in.readToken();
            HashMap<Character, Integer> map = new HashMap<>();
            for (int i = 0; i < token.length(); i++) {
                char c = token.charAt(i);
                if (map.containsKey(c)) {
                    map.put(c, map.get(c) + 1);
                } else {
                    map.put(c, 1);
                }
            }

            String[] CHARS = new String[]{
                    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
            };

            int[] sub = new int[]{
                    6, 4, 2, 0,
                    7,
                    5,
                    3,
                    8,
                    1,
                    9
            };
            char[] dec = new char[]{
                    'X', 'U', 'W', 'Z',
                    'S',
                    'V',
                    'R',
                    'G',
                    'O',
                    'E'
            };

            ArrayList<Integer> result = new ArrayList<>();
            for (int i = 0; i < sub.length; i++) {
                int val = sub[i];
                char valChar = dec[i];
                String rep = CHARS[val];

                int x = Integer.MAX_VALUE;

                for (int j = 0; j < rep.length(); j++) {
                    if (!map.containsKey(rep.charAt(j))) {
                        x = 0;
                        break;
                    }
                    x = Math.min(x, map.get(rep.charAt(j)));
                }

                for (int j = 0; j < rep.length(); j++) {
                    if (!map.containsKey(rep.charAt(j))) {
                        continue;
                    }
                    map.put(rep.charAt(j), map.get(rep.charAt(j)) - x);
                }

                for (int j = 0; j < x; j++) {
                    result.add(val);
                }
            }

            result.sort((o1, o2) -> o1 - o2);
            out.print("Case #" + testNumber + ": ");
            result.forEach(out::print);
            out.println();
        }

    }

    static class FastScanner {
        private StringTokenizer st;
        private BufferedReader in;

        public FastScanner(final InputStream in) {
            this.in = new BufferedReader(new InputStreamReader(in));
        }

        public String readToken() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(in.readLine());
                } catch (final IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        public String next() {
            return readToken();
        }

    }
}

