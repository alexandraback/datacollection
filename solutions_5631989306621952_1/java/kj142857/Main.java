import java.util.*;
import java.io.*;

public class Main {

    private static final String FORMAT = "Case #%d: %s\n";
    private PrintWriter writer;

    public Main() throws FileNotFoundException {
        writer = new PrintWriter(new FileOutputStream("output"));
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("A-large.in"));
        int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.

        Main main = new Main();

        for (int i = 1; i <= t; ++i) {
            String s = in.next();
            main.solve(i, s);
        }
        main.close();
    }

    private void solve(int num, String s) {

        StringBuilder builder = new StringBuilder();
        for (char ch: s.toCharArray()) {
            if (builder.length() == 0) {
                builder.append(ch);
            } else {
                char first = builder.charAt(0);
                if (ch >= first) {
                    builder.insert(0, ch);
                } else {
                    builder.append(ch);
                }
            }
        }

        writer.printf(FORMAT, num, builder.toString());
    }

    private void close() {
        writer.flush();
        writer.close();
    }
}