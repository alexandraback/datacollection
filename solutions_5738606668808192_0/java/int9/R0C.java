package gcj;

import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by song on 4/8/16.
 */
public class R0C {
    final static String PATH = "/Users/eatstreet/Downloads/";

    public static void main(String[] args) throws IOException {
        new R0C().solve();
    }

    private void solve() throws IOException {
        List<String> lines = Files.readAllLines(FileSystems.getDefault().getPath(PATH + "C.test"));
        PrintWriter writer = new PrintWriter(PATH + "C.out", "UTF-8");
        int t = Integer.parseInt(lines.get(0));
        for (int ca=1; ca<=t; ca++) {
            final String[] split = lines.get(ca).split(" ");
            writer.println(String.format("Case #%d:", ca));
            final List<String> stringList = findResult(Integer.parseInt(split[0]), Integer.parseInt(split[1]));
            for (String s : stringList) {
                writer.println(s);
            }
        }
        writer.close();
    }

    private List<String> findResult(int n, int c) {
        List<String> list = new ArrayList<>();
        // 11       11
        for (int i=2; i<n-3; i++) {
            for (int j=i+2; j<n-3; j++) {
                {
                    int[] a = new int[n];
                    a[0] = a[1] = a[n - 1] = a[n - 2] = 1;
                    a[i] = a[i + 1] = a[j] = a[j + 1] = 1;
                    final String string = getString(a);
                    list.add(string);
                    if (list.size() == c) {
                        return list;
                    }
                }
                for (int k=j+2; k<n-3; k++) {
                    {
                        int[] a = new int[n];
                        a[0] = a[1] = a[n - 1] = a[n - 2] = 1;
                        a[i] = a[i + 1] = a[j] = a[j + 1] = a[k] = a[k+1] = 1;
                        final String string = getString(a);
                        list.add(string);
                        if (list.size() == c) {
                            return list;
                        }
                    }
                }
            }
            {
                int[] a = new int[n];
                a[0] = a[1] = a[n-1] = a[n-2] = 1;
                a[i] = a[i+1] = 1;
                final String string = getString(a);
                list.add(string);
                if (list.size() == c) {
                    return list;
                }
            }
        }
        throw new RuntimeException("Need more " + list.size());
    }

    private String getString(int[] a) {
        String s = "";
        for (int x : a) {
            s += x;
        }
        for (int i=2; i<=10; i++) {
            s += " " + (i + 1);
        }
        return s;
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
