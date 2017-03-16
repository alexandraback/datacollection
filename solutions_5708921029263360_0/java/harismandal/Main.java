import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.HashMap;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int[] arr = new int[3];
            for (int i = 0; i < 3; ++i)
                arr[i] = in.nextInt();

            int k = in.nextInt();

            HashSet<Integer> worn = new HashSet<>();
            HashMap<Integer, Integer> pair = new HashMap<Integer, Integer>();
            int sec = 100;
            int thi = 1000;

            int sum = 0;
            ArrayList<String> res = new ArrayList<String>();

            while (true) {
                boolean flag = false;
                for (int i = 1; i <= arr[0]; ++i) {
                    for (int j = 1; j <= arr[1]; ++j)
                        for (int c = 1; c <= arr[2]; ++c) {
                            int full = i + j * sec + c * thi;

                            if (worn.contains(full)) continue;

                            int p1 = i + j * sec;
                            int p2 = i + c * thi;
                            int p3 = j * sec + c * thi;

                            if ((pair.containsKey(p1) && pair.get(p1) > k) ||
                                    (pair.containsKey(p2) && pair.get(p2) > k) ||
                                    (pair.containsKey(p3) && pair.get(p3) > k)) continue;

                            worn.add(full);
                            if (!pair.containsKey(p1)) pair.put(p1, 1);
                            else pair.put(p1, pair.get(p1) + 1);

                            if (!pair.containsKey(p2)) pair.put(p2, 1);
                            else pair.put(p2, pair.get(p2) + 1);

                            if (!pair.containsKey(p3)) pair.put(p3, 1);
                            else pair.put(p3, pair.get(p3) + 1);
                            sum += 1;
                            res.add(i + " " + j + " " + c);
                            flag = true;
                        }
                }

                if (flag == false) break;
            }

            out.println("Case #" + testNumber + ": " + sum);
            for (String s : res) {
                out.println(s);
            }
        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

