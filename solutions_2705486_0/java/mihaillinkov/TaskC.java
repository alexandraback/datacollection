import java.io.*;
import java.net.URL;
import java.util.Date;
import java.util.HashSet;
import java.util.StringTokenizer;

public class TaskC implements Runnable {
    private String line;
    private HashSet<String> set = new HashSet<String>();
    private boolean flag = false;

    public void rec(int errorCount, int lastErrorPosition, String currentLine) {
        if (currentLine.length() == 0) {
            flag = true;
            return;
        }
        for (int i = Math.min(currentLine.length(), 10); i > 0; i--) {
            if (set.contains(currentLine.substring(0, i))) {
                rec(errorCount, lastErrorPosition - i - 1, currentLine.substring(i));
                if (flag) return;
                if (new Date().getTime() - time > 2000L) return;
            }
        }

        if (errorCount > 0) {
            for (int firstError = Math.max(lastErrorPosition + 5, 0); firstError < Math.min(currentLine.length(), 10); firstError++) {
                if (errorCount > 1) {
                    for (int secondError = firstError + 5; secondError < Math.min(currentLine.length(), 10); secondError++) {
                        for (int i = 0; i < 26; i++) {

                            for (int j = 0; j < 26; j++) {
                                if ((char)('a' + i) != currentLine.charAt(firstError)) {
                                    if ((char)('a' + j) != currentLine.charAt(secondError)) {
                                        StringBuilder string = new StringBuilder(currentLine);
                                        string.setCharAt(firstError, (char)('a' + i));
                                        string.setCharAt(secondError, (char)('a' + j));
                                        rec(errorCount - 2, secondError, string.toString());
                                        if (flag) return;
                                        if (new Date().getTime() - time > 2000L) return;
                                    }
                                }
                            }
                        }
                    }
                }
                for (int i = 0; i < 26; i++) {
                    if ((char)('a' + i) != currentLine.charAt(firstError)) {
                        StringBuilder string = new StringBuilder(currentLine);
                        string.setCharAt(firstError, (char)('a' + i));
                        rec(errorCount - 1, firstError, string.toString());
                        if (flag) return;
                        if (new Date().getTime() - time > 2000L) return;
                    }
                }
            }
        }
    }
    private long time;
    public int solve() {
        int errorCount = -1;

        while (true) {
            errorCount++;
            int lastErrorPosition = -5;
            flag = false;
            System.out.println(errorCount + "errors");
            time = new Date().getTime();
            rec(errorCount, lastErrorPosition, line);

            if (flag) return errorCount;
        }

    }
    public void run() {
        try {

            InputReader reader = new InputReader(System.in);
            PrintWriter writer = new PrintWriter(new File("c.txt"));
            URL url = new URL("https://code.google.com/codejam/contest/static/garbled_email_dictionary.txt");

            reader = new InputReader(url.openStream());
            int COUNT = 521196;
            int max = 0;
            while (COUNT > 0) {
                COUNT--;
                String solve = reader.nextLine();
                set.add(solve);
                if (solve.length() > max) {
                    max = solve.length();
                }
            }
            reader = new InputReader(System.in);
            reader.nextLine();
            int testCount = reader.nextInt();
            for (int test = 1; test <= testCount; test++) {
                line = reader.nextLine();
                System.out.println(test);
                writer.println("Case #" + test + ": " + solve());
            }

            writer.close();
        } catch(IOException e) {

        }
    }
    public static void main(String[] args) {
        new TaskC().run();
    }
    private class InputReader {
        BufferedReader reader;
        StringTokenizer token;

        private InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
        }

        private String next() {
            return token.nextToken();
        }

        private int nextInt() {
            return Integer.parseInt(this.next());
        }

        private double nextDouble() {
            return Double.parseDouble(this.next());
        }

        private long nextLong() {
            return Long.parseLong(this.next());
        }


        private String nextLine() {
            String line = "";
            try {
                line = reader.readLine();
                token = new StringTokenizer(line, " ");

            } catch(IOException e) {

            }
            return line;
        }
    }
}
