import java.io.PrintStream;
import java.util.Scanner;

public class C {

    private static int police;

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt();
        for (int i = 1; i <= T; i++) {
            System.out.println("Case #" + i + ": " + solve(s));
        }
    }

    private static String solve(Scanner sc) {
        int x = sc.nextInt();
        int y = sc.nextInt();
        int z = sc.nextInt();
        police = sc.nextInt();

        if (x == y && y == z && z == 1) {
            return "1\n1 1 1";
        }

        int a, b, c = 0;

        int total = 0;

        StringBuilder out = new StringBuilder();

        int[][] jkMap = new int[y + 1][z + 1];

        for (int i = 1; i <= x; i++) {
            int[] ijMap = new int[y + 1];
            for (int j = 1; j <= y; j++) {
                int[] ikMap = new int[z + 1];
                for (int k = 1; k <= z; k++) {
                    log("ijMap[" + j + "] = " + ijMap[j] + " " + (ijMap[j] < police));
                    log("ikMap[" + k + "] = " + ikMap[k] + " " + (ikMap[k] < police));
                    log("jkMap[" + j + "][" + k + "] = " + jkMap[j][k] + " " + (jkMap[j][k] < police) + '\n');
                    if (ijMap[j] < police && ikMap[k] < police && jkMap[j][k] < police) {
                        out.append("\n").append(i).append(" ").append(j).append(" ").append(k);
                        ijMap[j]++;
                        ikMap[k]++;
                        jkMap[j][k]++;
                        total++;
                    }
                }
            }
        }

        if (total > x * y * z) throw new Error();

        log("===== " + x + " " + y + " " + z + " " + police);

        return "" + total + out.toString();
    }

    static PrintStream notes = System.out;

    public static void log(String msg) {
//        if (notes != null) notes.println(msg);
    }
}
