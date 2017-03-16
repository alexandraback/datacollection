import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author AlexFetisov
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("input.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("output.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB_GCJ solver = new TaskB_GCJ();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB_GCJ {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String s = in.nextString();
            out.println("Case #" + testNumber + ": " + get(s));
        }

        private int get(String s) {
            List<Integer> l = new ArrayList<Integer>();
            for (char c : s.toCharArray()) {
                int x = c == '-' ? 0 : 1;
                if (l.isEmpty()) {
                    l.add(x);
                } else if (l.get(l.size() - 1) != x) {
                    l.add(x);
                }
            }
            if (l.isEmpty()) return 0;
            if (l.get(l.size() - 1) == 1) {
                return l.size() - 1;
            }
            return l.size();
        }

    }

    static class InputReader {
        private BufferedReader reader;
        private StringTokenizer stt;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        public String nextString() {
            while (stt == null || !stt.hasMoreTokens()) {
                stt = new StringTokenizer(nextLine());
            }
            return stt.nextToken();
        }

        public String next() {
            return nextString();
        }

    }
}

