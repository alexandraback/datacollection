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
public class R1A {
    final static String PATH = "/Users/eatstreet/Downloads/";

    public static void main(String[] args) throws IOException {
        new R1A().solve();
    }

    private void solve() throws IOException {
        List<String> lines = Files.readAllLines(FileSystems.getDefault().getPath(PATH + "A-small-attempt0.in"));
        //List<String> lines = Files.readAllLines(FileSystems.getDefault().getPath(PATH + "A.in"));
        PrintWriter writer = new PrintWriter(PATH + "A2.out", "UTF-8");
        int t = Integer.parseInt(lines.get(0));
        for (int ca=1; ca<=t; ca++) {
            String v = lines.get(ca);
            writer.println(String.format("Case #%d: %s", ca, findAns(v)));
        }
        writer.close();
    }

    private String findAns(String v) {
        String t = v.charAt(0) + "";
        for (int i=1; i<v.length(); i++) {
            char c = v.charAt(i);
            String t1 = t + c;
            String t2 = c + t;
            if (t1.compareTo(t2) < 0) {
                t = t2;
            } else {
                t = t1;
            }
        }
        return t;
    }

}
