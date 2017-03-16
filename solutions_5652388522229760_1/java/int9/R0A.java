package gcj;

import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.util.List;

/**
 * Created by song on 4/8/16.
 */
public class R0A {
    final static String PATH = "/Users/eatstreet/Downloads/";

    public static void main(String[] args) throws IOException {
        new R0A().solve();
    }

    private void solve() throws IOException {
        List<String> lines = Files.readAllLines(FileSystems.getDefault().getPath(PATH + "A-small-attempt0.in"));
        PrintWriter writer = new PrintWriter(PATH + "A.out", "UTF-8");
        int t = Integer.parseInt(lines.get(0));
        for (int ca=1; ca<=t; ca++) {
            int n = Integer.parseInt(lines.get(ca));
            writer.println(String.format("Case #%d: %s", ca, findMinCount(n)));
        }
        writer.close();
    }

    private String findMinCount(int n) {
        if (n == 0) {
            return "INSOMNIA";
        }
        final BigInteger nb = BigInteger.valueOf(n);
        BigInteger v = nb;
        boolean[] digit = new boolean[10];
        int found = 0;
        while (found < 10) {
            for (char c : v.toString().toCharArray()) {
                int d = c - '0';
                if (!digit[d]) {
                    digit[d] = true;
                    found++;
                }
            }
            if (found < 10) {
                v = v.add(nb);
            }
        }
        return v.toString();
    }
}
