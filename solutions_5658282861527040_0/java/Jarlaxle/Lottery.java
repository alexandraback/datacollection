import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Lottery {
    private static final String inFile = "B-small-attempt0.in";
    private static final String outFile = "B-out.txt";

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        int T = scanner.nextInt();
        FileWriter fw = new FileWriter(outFile);
        for (int t = 1; t <= T; ++t) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            int k = scanner.nextInt();
            fw.write(String.format("Case #%d: %d\n", t, solve(a, b, k)));
        }
        fw.close();
    }

    private static long solve(int a, int b, int k) {
        long res = 0;
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                if ((i & j) < k) {
                    ++res;
                }
            }
        }
        return res;
    }
}
