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
public class R0B {
    final static String PATH = "/Users/eatstreet/Downloads/";

    public static void main(String[] args) throws IOException {
        new R0B().solve();
    }

    private void solve() throws IOException {
        List<String> lines = Files.readAllLines(FileSystems.getDefault().getPath(PATH + "B.test"));
        PrintWriter writer = new PrintWriter(PATH + "B.out", "UTF-8");
        int t = Integer.parseInt(lines.get(0));
        for (int ca=1; ca<=t; ca++) {
            writer.println(String.format("Case #%d: %s", ca, findMinCount(lines.get(ca))));
        }
        writer.close();
    }

    private int findMinCount(String s) {
        s += "+";
        int cnt = 0;
        for (int i=0; i<s.length() - 1; i++) {
            if (s.charAt(i) != s.charAt(i + 1)) {
                cnt ++;
            }
        }
        return cnt;
    }
}
