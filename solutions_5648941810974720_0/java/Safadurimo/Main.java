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
 *
 * @author safadurimo
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
        int[] counter;
        int[] sol;
        String[] numbers = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            counter = new int[26];
            sol = new int[10];

            String s = in.next();
            for (int i = 0; i < s.length(); i++) {
                counter[s.charAt(i) - 'A']++;
            }

            eliminate(0, 'Z' - 'A');
            eliminate(8, 'G' - 'A');
            eliminate(2, 'W' - 'A');
            eliminate(6, 'X' - 'A');
            eliminate(3, 'T' - 'A');
            eliminate(4, 'R' - 'A');
            eliminate(5, 'F' - 'A');
            eliminate(7, 'V' - 'A');
            eliminate(1, 'O' - 'A');
            eliminate(9, 'I' - 'A');


            out.printf("Case #%d: %s\n", testNumber, getSol());
        }

        private void eliminate(int number, int ch) {
            sol[number] = counter[ch];
            String s = numbers[number];
            for (int i = 0; i < s.length(); i++) {
                counter[s.charAt(i) - 'A'] -= sol[number];
            }
        }

        private String getSol() {
            String s = "";
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < sol[i]; j++) {
                    s += i;
                }
            }
            return s;
        }

    }
}

