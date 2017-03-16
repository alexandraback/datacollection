import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

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
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskA {
        int[] d = new int[10];

        private boolean check() {
            for (int i = 0; i < 10; i++)
                if (d[i] == 0)
                    return false;
            return true;
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            for (int i = 0; i < 10; i++)
                d[i] = 0;
            for (int i = 1; i <= 100; i++) {
                String tmp = String.valueOf(i * n);
                for (int j = 0; j < tmp.length(); j++) {
                    d[tmp.charAt(j) - '0'] = 1;
                }
                if (check()) {
                    out.println("Case #" + testNumber + ": " + i * n);
                    return;
                }
            }
            out.println("Case #" + testNumber + ": INSOMNIA");
        }

    }
}

