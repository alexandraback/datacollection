import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class A {

    private static List<Integer>[] m;

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("a.in")));
        PrintStream out = new PrintStream(new FileOutputStream("a.out"));
        long testCaseNumber = readInt(in);
        for (int cas = 0; cas < testCaseNumber; cas++) {
            String[] d = in.readLine().split(" ");
            BigDecimal r = new BigDecimal(Long.parseLong(d[0]));
            BigDecimal t = new BigDecimal(Long.parseLong(d[1]));
            BigDecimal left = new BigDecimal(0);
            BigDecimal right = t;

            BigDecimal two = new BigDecimal(2);
            BigDecimal one = new BigDecimal(1);
            while (!right.equals(left.add(one))) {
                BigDecimal center = left.add(right).divideAndRemainder(two)[0];
                if (center.equals(left)) {
                    center = left.add(one);
                }

                //2*(r) + 1  + ..... 2*(r + 2(center -1)) + 1
                BigDecimal required = r.multiply(two).add(one).multiply(center);
                required = required.add(center.subtract(one).multiply(center).multiply(two));
                if (required.compareTo(t) > 0) {
                    right = center;
                } else {
                    left = center;
                }
            }
            out.print("Case #" + (cas + 1) + ": ");
            out.print(Long.toString(left.longValue()));
            out.println();
        }

        out.flush();
        out.close();
    }

    static int score(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            switch (ch) {
                case '.':
                    ans += -1000000;
                    break;
                case 'T':
                    ans += 239;
                    break;
                case 'O':
                    ans += 1;
                    break;
                case 'X':
                    ans += 239 * 11;
                    break;
            }
        }
        return ans;
    }

    private static long readInt(BufferedReader in) {
        try {
            return Long.parseLong(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
