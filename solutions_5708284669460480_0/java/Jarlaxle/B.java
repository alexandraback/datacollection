import com.sun.tools.corba.se.idl.IncludeGen;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class B {
    private static final String inFile = "B-small-attempt0 (1).in";
    private static final String outFile = "B-out.txt";

    private String kbd, tgt;
    private final char[] buff;
    private final Map<Integer, Integer> m = new HashMap<Integer, Integer>();

    public B(int s, String kbd, String tgt) {
        this.kbd = kbd;
        this.tgt = tgt;

        buff = new char[s];
    }

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        String inp = scanner.nextLine();
        int T = Integer.parseInt(inp);
        FileWriter fw = new FileWriter(outFile);

        for (int t = 1; t <= T; ++t) {
            inp = scanner.nextLine();
            String[] p = inp.split(" ");
            int s = Integer.parseInt(p[2]);
            String kbd = scanner.nextLine();
            String tgt = scanner.nextLine();
            B solver = new B(s, kbd, tgt);
            fw.write(String.format("Case #%d: %s\n", t, solver.solve()));
        }
        fw.close();
    }

    private double solve() {
        brute(0);
        int max = 0;
        int tot = 0;
        for (int key : m.keySet()) {
            max = Math.max(max, key);
            tot += m.get(key);
        }
        double res = 0, mul = 1.0 / tot;
        for (int key : m.keySet()) {
            res += mul * (max - key) * m.get(key);
        }
        return res;
    }

    private void brute(int pos) {
        if (pos == buff.length) {
            int cnt = 0;
            for (int i = 0; i <= buff.length - tgt.length(); ++i) {
                boolean m = true;
                for (int j = 0; j < tgt.length(); ++j) {
                    if (buff[i + j] != tgt.charAt(j)) {
                        m = false;
                        break;
                    }
                }
                if (m) ++cnt;
            }
            if (!m.containsKey(cnt)) {
                m.put(cnt, 0);
            }
            m.put(cnt, m.get(cnt) + 1);
        } else {
            for (int i = 0; i < kbd.length(); ++i) {
                buff[pos] = kbd.charAt(i);
                brute(pos + 1);
            }
        }
    }
}
