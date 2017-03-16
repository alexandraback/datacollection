/**
 * Created by wei on 4/11/15.
 */
import java.io.*;
import java.util.*;


public class SolutionD {
    static Scanner scan = new Scanner (System.in);
    static PrintStream out = System.out;

    private static boolean doable(TreeSet<Integer> demo, int C, int value) {
        Iterator iter = demo.descendingIterator();
        while (iter.hasNext()){
            int d = (Integer)(iter.next());
            if (value % d == 0 && value/d <= C)
                return true;

            value -= Math.min (value/d, C) * d;
        }

        return false;
    }

    private static void solve() {
        int C = scan.nextInt(), D = scan.nextInt(), V = scan.nextInt();

        TreeSet<Integer> demo = new TreeSet<Integer>();
        for (int i = 0; i < D; ++i)
            demo.add(scan.nextInt());

        for (int value = 1; value <= V; ++value) {
            if (!doable(demo, C, value)) {
                demo.add(value);
            }
        }

        out.println (demo.size () - D);
    }


    public static void main(String[] args) {
        int T = scan.nextInt();

        for (int i = 1; i <= T; ++i) {
            System.out.print("Case #" + i + ": ");
            solve();
        }

    }
}
