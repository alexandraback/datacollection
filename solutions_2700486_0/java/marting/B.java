import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class B {
    static String _tn = "B";
    static Scanner in = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File(_tn+".in"));
        out = new PrintWriter(new File(_tn+".out"));
        int T = in.nextInt();
        for (int I = 0; I < T; I++) {
            out.printf("Case #%d: %.8f\n", I + 1, solve());
            out.flush();
        }
        out.close();
    }
    static int X, Y;
    static double res = 0;
    static void step(int n, int cx, double p, Map<Integer, Integer> map) {
        if (n<=0) return;
        int y = map.get(cx);
        int yl = map.get(cx-1);
        int yr = map.get(cx+1);
        if (yl>=y && yr>=y) {
            map.put(cx, y+2);
            map.put(cx-1, y+1);
            map.put(cx+1, y+1);
            if (X == cx && y+2 >= Y)
                res += p;
            else
                step(n-1, 0, p, map);
            map.put(cx, y);
            map.put(cx-1, yl);
            map.put(cx+1, yr);
        } else if (yl>=y) {
            step(n, cx+1, p, map);
        } else if (yr>=y) {
            step(n, cx-1, p, map);
        } else {
            step(n, cx-1, p/2, map);
            step(n, cx+1, p/2, map);
        }
    }
    static double solve() {
        int n = in.nextInt();
        X = in.nextInt();
        Y = in.nextInt();
        res = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>() {
            public Integer get(Object key) {
                if (containsKey(key))
                    return super.get(key);
                return -1;
            }
        };
        step(n, 0, 1.0, map);
        return res;
    }
}
