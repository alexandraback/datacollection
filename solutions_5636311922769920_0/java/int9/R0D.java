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
public class R0D {
    final static String PATH = "/Users/eatstreet/Downloads/";

    public static void main(String[] args) throws IOException {
        new R0D().solve();
    }

    private void solve() throws IOException {
        List<String> lines = Files.readAllLines(FileSystems.getDefault().getPath(PATH + "D.test"));
        PrintWriter writer = new PrintWriter(PATH + "D.out", "UTF-8");
        int t = Integer.parseInt(lines.get(0));
        for (int ca=1; ca<=t; ca++) {
            final String[] split = lines.get(ca).split(" ");
            writer.println(String.format("Case #%d: %s", ca,
                    findResult(Integer.parseInt(split[0]), Integer.parseInt(split[1]), Integer.parseInt(split[2]))));
        }
        writer.close();
    }

    private String findResult(int k, int c, int s) {
        int n = (k - 1) / c + 1;
        if (s < n) {
            return "IMPOSSIBLE";
        }
        String ret = "";
        for (int i=0; i<n; i++) {
            int[] a = new int[c];
            for (int j=0; j<c; j++) {
                a[j] = Math.min(j + i * c, k - 1);
            }
            ret += rad(a, k) + " ";
        }
        return ret.substring(0, ret.length() - 1);
    }

    private String rad(int[] a, int k) {
        BigInteger v = BigInteger.ZERO;
        for (int i=0; i<a.length; i++) {
            v = v.multiply(BigInteger.valueOf(k)).add(BigInteger.valueOf(a[i]));
        }
        v = v.add(BigInteger.ONE);
        return v.toString();
    }
}
