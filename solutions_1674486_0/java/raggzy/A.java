import sun.awt.geom.AreaOp;
import sun.rmi.log.LogInputStream;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.*;

public class A {

    private static boolean checkDiamond(int[][] inherits, Set<Integer>[] hasInheritance, int v) {
        for (int i = 0; i < inherits[v].length; i++) {
            int next = inherits[v][i];
            Set<Integer> tmp = new HashSet<Integer>();
            tmp.add(v);
            tmp.addAll(hasInheritance[v]);
            tmp.retainAll(hasInheritance[next]);
            hasInheritance[next].addAll(hasInheritance[v]);
            hasInheritance[next].add(v);
            if (tmp.size() > 0) {
                return true;
            }
            if (checkDiamond(inherits, hasInheritance, next)) {
                return true;
            }
        }
        return false;
    }

    private static boolean isDiamond(int[][] inherits) {
        Set<Integer> heads = new HashSet<Integer>();
        Set<Integer>[] hasInheritance = new Set[inherits.length];

        for (int i = 0; i < inherits.length; i++) {
            heads.add(i);
            hasInheritance[i] = new HashSet<Integer>();
        }
        for (int i = 0; i < inherits.length; i++) {
            for (int j = 0; j < inherits[i].length; j++) {
                heads.remove(inherits[i][j]);
            }
        }

        for (int v : heads) {
            for (int i = 0; i < hasInheritance.length; i++) {
                hasInheritance[i].clear();
            }
            if (checkDiamond(inherits, hasInheritance, v)) {
                return true;
            }
        }

        return false;
    }

    private static void solve(Scanner in, PrintWriter out) {
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            int[][] inherits = new int[N][];
            for (int i = 0; i < N; i++) {
                int l = in.nextInt();
                inherits[i] = new int[l];
                for (int j = 0; j < l; j++) {
                    inherits[i][j] = in.nextInt()-1;
                }
            }
            out.println(String.format("Case #%d: %s", t, isDiamond(inherits) ? "Yes" : "No"));
        }

    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("/home/raggzy/temp/gcj/in.txt"));
        PrintWriter out = new PrintWriter(new FileOutputStream("/home/raggzy/temp/gcj/out.txt"));
        solve(in, out);
        in.close();
        out.close();
    }
}
