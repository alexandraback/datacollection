
import java.io.*;

public class ProblemA {

    private static final String INPUT = "A-small-attempt0.in";

    public static void main(String[] args) throws IOException {
        try (BufferedReader in = new BufferedReader(new InputStreamReader(ProblemA.class.getResourceAsStream(INPUT)));
                FileWriter out = new FileWriter(INPUT.replaceAll("\\.in$", ".out"))) {

            int t = Integer.parseInt(in.readLine());
            for (int i = 1; i <= t; i++) {
                out.write("Case #" + i + ": " + process(in.readLine()));
                if (i != t) {
                    out.write("\n");
                }
            }
        }
    }

    private static String process(String line) {
        StringBuilder buf = new StringBuilder(line.length());
        for (char c : line.toCharArray()) {
            if (buf.length() == 0) {
                buf.append(c);
            } else if (c >= buf.charAt(0)) {
                buf.insert(0, c);
            } else {
                buf.append(c);
            }
        }

        return buf.toString();
    }
}
