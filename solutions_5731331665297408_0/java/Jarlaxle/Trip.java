import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Trip {
    private static final String inFile = "C-small-attempt0.in";
    private static final String outFile = "C-out.txt";

    private static String[] codes;
    private static boolean[][] conn;

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(new FileReader(inFile));
        int T = scanner.nextInt();
        FileWriter fw = new FileWriter(outFile);
        for (int t = 1; t <= T; ++t) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            codes = new String[n];
            for (int i = 0; i < n; ++i) {
                codes[i] = scanner.next();
            }
            conn = new boolean[n][n];
            for (int i = 0; i < m; ++i) {
                int from = scanner.nextInt() - 1;
                int to = scanner.nextInt() - 1;
                conn[from][to] = conn[to][from] = true;
            }
            fw.write(String.format("Case #%d: %s\n", t, solve()));
        }
        fw.close();
    }

    private static boolean permute(int[] a) {
        int i1 = -1;
        for (int i = a.length - 2; i >= 0; --i) {
            if (a[i] < a[i + 1]) {
                i1 = i;
                break;
            }
        }

        if (i1 < 0) return false;

        int i2 = -1;
        for (int i = a.length - 1 ; i >= 0; i--) {
            if (a[i1] < a[i]) {
                i2 = i;
                break;
            }
        }

        int tmp = a[i1];
        a[i1] = a[i2];
        a[i2] = tmp;

        for (int i = i1 + 1, j = a.length - 1; i < j; i++, j--) {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }

        return true;
    }

    private static String solve() {
        int n = codes.length;
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        String res = "";
        do {
            if (check(p)) {
                String cand = build(p);
                //System.out.println(cand);
                if (res.equals("")) {
                    res = cand;
                } else {
                    if (res.compareTo(cand) > 0) {
                        res = cand;
                    }
                }
            }
        } while (permute(p));
        //System.out.println("---");
        return res;
    }

    private static String build(int[] a) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < a.length; ++i) {
            sb.append(codes[a[i]]);
        }
        return sb.toString();
    }

    private static boolean check(int[] a) {
        int n = a.length;
        int[] parents = new int[n];
        parents[0] = a[0];
        int idx = 0;
        for (int i = 1; i < n; ++i) {
            int parentId = -1;
            for (int j = idx; j >= 0; --j) {
                if (conn[parents[j]][a[i]]) {
                    parentId = j;
                    break;
                }
            }
            if (parentId == -1) {
                return false;
            }
            idx = parentId + 1;
            parents[idx] = a[i];
        }
        return true;
    }
}
