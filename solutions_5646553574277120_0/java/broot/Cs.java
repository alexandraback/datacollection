import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Paths;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Cs {

//    private static final String FNAME = "test";
    private static final String FNAME = "small-0";
//    private static final String FNAME = "large-0";

    private static int C;
    private static int D;
    private static int V;

    private static List<Integer> denoms = new LinkedList<Integer>();


    public static void main(String[] args) throws IOException {
        String fname = "data/" + "C-" + FNAME + ".";
        Scanner sc = new Scanner(Paths.get(fname + "in"));
        PrintWriter w = new PrintWriter(fname + "out");

        int T = sc.nextInt();
        for (int tc = 0; tc < T; tc++) {

            C = sc.nextInt();
            D = sc.nextInt();
            V = sc.nextInt();

            denoms.clear();
            for (int i = 0; i < D; i++) {
                denoms.add(sc.nextInt());
            }

            int res = 0;
            for (int i = 1; i <= V; i++) {
                if (! isPossible(i, 0, 0)) {
                    res++;
                    denoms.add(i);
                }
            }

            w.printf("Case #%d: %d\n", tc + 1, res);
        }

        w.close();
    }

    private static boolean isPossible(int v, int v2, int pos) {
        if (v == v2) {
            return true;
        }
        if (pos == denoms.size()) {
            return false;
        }
        return isPossible(v, v2, pos + 1) || isPossible(v, v2 + denoms.get(pos), pos + 1);
    }
}
