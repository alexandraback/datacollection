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
import java.util.Scanner;
import java.util.Set;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author safadurimo
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
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {

            int n = in.nextInt();
            String[] first = new String[n];
            String[] second = new String[n];
            for (int i = 0; i < n; i++) {
                first[i] = in.next();
                second[i] = in.next();
            }
            int worst = 0;
            for (int i = 0; i < (1 << n); i++) {
                Set<String> firstWord = new HashSet<String>();
                Set<String> secondWords = new HashSet<String>();
                for (int j = 0; j < n; j++) {
                    if ((i >> j & 1) != 0) {
                        firstWord.add(first[j]);
                        secondWords.add(second[j]);
                    }

                }
                boolean check = true;
                for (int j = 0; j < n; j++) {
                    if ((i >> j & 1) == 0) {
                        if (firstWord.contains(first[j]) && secondWords.contains(second[j])) {

                        } else check = false;
                    }

                }
                if (check) {
                    worst = Math.max(n - Integer.bitCount(i), worst);
                }


            }
            out.printf("Case #%d: %d\n", testNumber, worst);
        }

    }
}

