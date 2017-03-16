import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class D {
    private static final String inFile = "D-small-attempt3.in";
    private static final String outFile = "D-out.txt";

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        int T = scanner.nextInt();
        FileWriter fw = new FileWriter(outFile);
        for (int t = 1; t <= T; ++t) {
            int x = scanner.nextInt();
            int r = scanner.nextInt();
            int c = scanner.nextInt();
            boolean g = good(x, r, c);
            fw.write(String.format("Case #%d: %s\n", t, g ? "RICHARD" : "GABRIEL"));
        }
        fw.close();
    }

    public static boolean good(int x, int r, int c) {
        if (r > c) {
            int t = r;
            r = c;
            c = t;
        }
        if (0 != (r * c) % x) return true;
        if (2*r + 1 <= x) return true;
        if (c < x) return true;
        if (4 == x && r == 2) return true;
        return false;
    }
}
