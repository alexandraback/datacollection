import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.util.Hashtable;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            String s = in.next();
            int n = s.length(), i, j;
            Hashtable<Character, Integer> table = new Hashtable<>();
            for (i = 0; i < 26; i++) {
                table.put((char) (i + 'A'), 0);
            }
            for (i = 0; i < n; i++) {
                table.put(s.charAt(i), table.get(s.charAt(i)) + 1);
            }
            int ans[] = new int[10];
            //ZERO
            ans[0] = table.get('Z');
            table.put('E', table.get('E') - ans[0]);
            table.put('R', table.get('R') - ans[0]);
            table.put('O', table.get('O') - ans[0]);
            table.put('Z', table.get('Z') - ans[0]);
            //TWO
            ans[2] = table.get('W');
            table.put('T', table.get('T') - ans[2]);
            table.put('O', table.get('O') - ans[2]);
            table.put('W', table.get('W') - ans[2]);
            //FOUR
            ans[4] = table.get('U');
            table.put('F', table.get('F') - ans[4]);
            table.put('O', table.get('O') - ans[4]);
            table.put('R', table.get('R') - ans[4]);
            table.put('U', table.get('U') - ans[4]);
            //SIX
            ans[6] = table.get('X');
            table.put('X', table.get('X') - ans[6]);
            table.put('S', table.get('S') - ans[6]);
            table.put('I', table.get('I') - ans[6]);
            //EIGHT
            ans[8] = table.get('G');
            table.put('E', table.get('E') - ans[8]);
            table.put('I', table.get('I') - ans[8]);
            table.put('G', table.get('G') - ans[8]);
            table.put('H', table.get('H') - ans[8]);
            table.put('T', table.get('T') - ans[8]);
            //ONE
            ans[1] = table.get('O');
            table.put('O', table.get('O') - ans[1]);
            table.put('N', table.get('N') - ans[1]);
            table.put('E', table.get('E') - ans[1]);
            //THREE
            ans[3] = table.get('H');
            table.put('T', table.get('T') - ans[3]);
            table.put('H', table.get('H') - ans[3]);
            table.put('R', table.get('R') - ans[3]);
            table.put('E', table.get('E') - ans[3]);
            table.put('E', table.get('E') - ans[3]);
            //FIVE
            ans[5] = table.get('F');
            table.put('F', table.get('F') - ans[5]);
            table.put('I', table.get('I') - ans[5]);
            table.put('V', table.get('V') - ans[5]);
            table.put('E', table.get('E') - ans[5]);
            //SEVEN
            ans[7] = table.get('V');
            table.put('S', table.get('S') - ans[7]);
            table.put('E', table.get('E') - ans[7]);
            table.put('V', table.get('V') - ans[7]);
            table.put('E', table.get('E') - ans[7]);
            table.put('N', table.get('N') - ans[7]);
            //NINE
            ans[9] = table.get('I');
            table.put('N', table.get('N') - ans[9]);
            table.put('I', table.get('I') - ans[9]);
            table.put('N', table.get('N') - ans[9]);
            table.put('E', table.get('E') - ans[9]);
            StringBuffer x = new StringBuffer("");
            for (i = 0; i < 10; i++) {
                while (ans[i] > 0) {
                    x.append(i);
                    ans[i]--;
                }
            }
            out.printLine("Case #" + testNumber + ": " + x);
        }

    }

    static class InputReader {
        BufferedReader in;
        StringTokenizer tokenizer = null;

        public InputReader(InputStream inputStream) {
            in = new BufferedReader(new InputStreamReader(inputStream));
        }

        public String next() {
            try {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                    tokenizer = new StringTokenizer(in.readLine());
                }
                return tokenizer.nextToken();
            } catch (IOException e) {
                return null;
            }
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}

