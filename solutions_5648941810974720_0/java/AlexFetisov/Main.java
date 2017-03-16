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
import java.util.Collections;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.io.InputStream;

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
        TaskA_GCJ_r2 solver = new TaskA_GCJ_r2();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA_GCJ_r2 {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            out.print("Case #" + testNumber + ": ");
            String s = in.nextString();
            List<Integer> res = new ArrayList<Integer>();
            while (search(s, "ZERO")) {
                res.add(0);
                s = remove(s, "ZERO");
            }
            while (search(s, "SIX")) {
                res.add(6);
                s = remove(s, "SIX");
            }
            while (search(s, "EIGHT")) {
                res.add(8);
                s = remove(s, "EIGHT");
            }
            while (search(s, "SEVEN")) {
                res.add(7);
                s = remove(s, "SEVEN");
            }
            while (search(s, "FIVE")) {
                res.add(5);
                s = remove(s, "FIVE");
            }
            while (search(s, "FOUR")) {
                res.add(4);
                s = remove(s, "FOUR");
            }
            while (search(s, "THREE")) {
                res.add(3);
                s = remove(s, "THREE");
            }
            while (search(s, "TWO")) {
                res.add(2);
                s = remove(s, "TWO");
            }
            while (search(s, "ONE")) {
                res.add(1);
                s = remove(s, "ONE");
            }
            while (search(s, "NINE")) {
                res.add(9);
                s = remove(s, "NINE");
            }
            Collections.sort(res);
//        while (!s.isEmpty()) {
//            for (int i = 0; i < 10; ++i) {
//                if (search(s, digits[i])) {
//                    result.append(i);
//                    s = remove(s, digits[i]);
//                    break;
//                }
//            }
//        }
            for (int i : res) {
                out.print(i);
            }
            out.println();
//        out.println(result.toString());
        }

        private String remove(String s, String digit) {
            for (char c : digit.toCharArray()) {
                int idx = s.indexOf(c);
                if (idx == s.length() - 1) {
                    s = s.substring(0, s.length() - 1);
                } else {
                    s = s.substring(0, idx) + s.substring(idx + 1);
                }
            }
            return s;
        }

        private boolean search(String s, String digit) {
            int[] prev = new int[26];
            for (char c : digit.toCharArray()) {
                int idx = s.indexOf(c, prev[c - 'A']);
                if (idx == -1) return false;
                prev[c - 'A'] = idx + 1;
            }
            return true;
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

