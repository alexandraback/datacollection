import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;

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
                if (toRun == null || candidate.lastModified() > toRun.lastModified()) {
                    toRun = candidate;
                }
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
        for (int i = 1; i <= testCount; i++) {
            solver.solve(i, in, out);
        }
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int J = in.nextInt();
            int P = in.nextInt();
            int S = in.nextInt();
            int K = in.nextInt();
            out.print("Case #" + testNumber + ": ");
            Map<String, Integer> jpMap = new HashMap<>();
            Map<String, Integer> psMap = new HashMap<>();
            Map<String, Integer> sjMap = new HashMap<>();

            int total = 0;
            List<String> outList = new ArrayList<>();
            for (int s = 1; s <= S; s++) {
                String res = s + "";
                for (int p = 1; p <= P; p++) {
                    String res1 = p + " " + res;
                    for (int j = 1; j <= J; j++) {
                        String res2 = j + " " + res1;
                        String jp = j + " " + p;
                        String ps = p + " " + s;
                        String sj = s + " " + j;
                        int jpCount = jpMap.get(jp) == null ? 0 : jpMap.get(jp);
                        int psCount = psMap.get(ps) == null ? 0 : psMap.get(ps);
                        int sjCount = sjMap.get(sj) == null ? 0 : sjMap.get(sj);
                        if (jpCount < K && psCount < K && sjCount < K) {
                            total++;
                            outList.add(res2);
                            jpMap.put(jp, jpCount + 1);
                            psMap.put(ps, psCount + 1);
                            sjMap.put(sj, sjCount + 1);
                        }
                    }
                }
            }
            out.println(total);
            for (String str : outList) {
                out.println(str);
            }
        }

    }
}

