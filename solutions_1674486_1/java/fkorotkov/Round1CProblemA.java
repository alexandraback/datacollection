import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author fedor.korotkov
 */
public class Round1CProblemA {
    public static void main(String[] args) throws FileNotFoundException {
        final Scanner in = new Scanner(new FileInputStream("in.txt"));
        int t = in.nextInt();
        for (int i = 1; i <= t; ++i) {
            System.out.print("Case #" + i + ": ");
            System.out.println(solve(in));
        }
    }

    private static String solve(Scanner in) {
        final int n = in.nextInt();
        final List<Integer>[] g = new List[n];
        for (int i = 0; i < n; i++){
            g[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < n; i++){
            int m = in.nextInt();
            while (m --> 0){
                g[i].add(in.nextInt() - 1);
            }
        }
        for (int i = 0; i < n; ++i){
            if(check(g, i)){
                return "Yes";
            }
        }
        return "No";
    }

    private static boolean check(List<Integer>[] g, int start) {
        return check(g, start, new boolean[g.length]);
    }

    private static boolean check(List<Integer>[] g, int start, boolean[] mark) {
        if(mark[start]){
            return true;
        }
        mark[start] = true;
        boolean result = false;
        for (Integer to : g[start]){
            result = result || check(g, to, mark);
        }
        return result;
    }
}
