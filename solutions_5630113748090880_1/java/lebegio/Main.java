import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
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
 * @author lebegio
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
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
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("b.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        MyReader in = new MyReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, MyReader in, PrintWriter out) {
            int n = in.nextInt();
//        int[][] rows = new int[2*n-1][n];
            TaskB.Row[] rowz = new TaskB.Row[2 * n - 1];

            boolean[] H = new boolean[2510];
            int h = 0;
            for (int i = 0; i < 2 * n - 1; i++) {
                rowz[i] = new TaskB.Row(n);
                for (int j = 0; j < n; j++) {
                    rowz[i].arr[j] = in.nextInt();
                    h = rowz[i].arr[j];
                    H[h] ^= true;
                }
            }

            int[] mas = new int[n];
            ArrayList<Integer> heights = new ArrayList<>();
            for (int i = 0; i < H.length; i++) {
                if (H[i]) {
                    heights.add(i);
                }
            }
            Collections.sort(heights);
            out.print("Case #" + testNumber + ": ");
            for (int x : heights)
                out.print(x + " ");
            out.println();
        }

        public static class Row {
            public int[] arr;

            public Row(int n) {
                arr = new int[n];
            }

        }

    }

    static class MyReader {
        private BufferedReader buffReader;
        private StringTokenizer strTokenizer;
        private static final int SIZE = 32768;

        public MyReader(InputStream inputStream) {
            buffReader = new BufferedReader(new InputStreamReader(inputStream), SIZE);
        }

        public String next() {
            if (strTokenizer == null || !strTokenizer.hasMoreTokens()) {
                try {
                    strTokenizer = new StringTokenizer(buffReader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return strTokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}

