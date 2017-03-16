import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class ProblemB {
    private final int[][] a;
    private final int n;

    public ProblemB(int n, int[][] a) {
        this.a = a;
        this.n = n;
    }

    public Set<Integer> solution() {
        Set<Integer> result = new TreeSet<>();
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                int x = a[i][j];
                if (result.contains(x)) {
                    result.remove(x);
                } else {
                    result.add(x);
                }
            }
        }
        return result;
    }

    private static String asString(Set<Integer> set) {
        String result = "";
        for (Integer integer : set) {
            result += " " + integer;
        }
        return result;
    }

    public static void main(String[] args) throws Exception {
//        Scanner in = new Scanner(System.in);
//        PrintStream out = System.out;
        Scanner in = new Scanner(new File("B.in"));
        PrintStream out = new PrintStream("B.out");
        int TOTAL_TESTS = in.nextInt();
        for (int t = 1; t <= TOTAL_TESTS; t++) {
            int n = in.nextInt();
            int[][] a = new int[2 * n - 1][n];
            for (int i = 0; i < a.length; i++) {
                for (int j = 0; j < a[i].length; j++) {
                    a[i][j] = in.nextInt();
                }
            }
            out.println("Case #" + t + ":" + asString(new ProblemB(n, a).solution()));
        }
    }

}
