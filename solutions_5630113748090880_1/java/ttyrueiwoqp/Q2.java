import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Q2 {

    public static String solve(List<List<Integer>> inputs) {

        Set<Integer> set = new TreeSet<>();
        for (List<Integer> input : inputs) {
            for (Integer i : input) {
                if (set.contains(i)) {
                    set.remove(i);
                } else {
                    set.add(i);
                }
            }
        }
        String res = "";
        Iterator<Integer> it = set.iterator();
        while (it.hasNext()) {
            res += it.next() + " ";
        }

        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.

        for (int i = 1; i <= t; ++i) {
            int n = in.nextInt();
            in.nextLine();
            List<List<Integer>> input = new ArrayList<>();
            for (int j = 0; j < 2 * n - 1; j++) {
                String row = in.nextLine();
                StringTokenizer stk = new StringTokenizer(row, " ");
                List<Integer> list = new ArrayList<>();

                while (stk.hasMoreTokens()) {
                    list.add(Integer.parseInt(stk.nextToken()));
                }
                input.add(list);
            }
            System.out.println("Case #" + i + ": " + solve(input));
        }
    }
}
