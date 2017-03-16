import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class CodeJamA {

    private static final String INPUT = "/opt/dev/TopCoder/src/A-small-attempt3.in";
    private static final String OUTPUT = "/opt/dev/TopCoder/src/out.txt";

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter writer = new PrintWriter(OUTPUT, "UTF-8");
        solve(br, writer);
        br.close();
        writer.close();
    }

    private static void solve(BufferedReader reader, PrintWriter writer) throws Exception {
        int t = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < t; i++) {
            String[] val = reader.readLine().trim().split(" ");
            int r = Integer.parseInt(val[0]);
            int c = Integer.parseInt(val[1]);
            int w = Integer.parseInt(val[2]);

            writer.println("Case #" + (i + 1) + ": " + resolve(r, c, w));
        }
    }

    private static String resolve(int r, int c, int w) {
        if (c % w == 0) {
            return Integer.toString((c / w) * r + w - 1);
        } else {
            return Integer.toString((c / w) * r + w);
        }
    }
}
