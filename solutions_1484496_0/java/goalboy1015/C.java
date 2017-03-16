
import java.io.File;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class C {

    public static void main(String args[]) throws Exception {
        final String PATH = "/home/goalboy/software installation/codejam-commandline-1.0-beta4/source/";
        final String FILE = "C-small-0";
        Scanner in = new Scanner(new File(PATH + FILE + ".in"));
        PrintWriter out = new PrintWriter(PATH + FILE + ".out");

        int test = in.nextInt();
        for (int t = 1; t <= test; t++) {
            int N = in.nextInt();
            int S[] = new int[N];
            for (int i = 0; i < S.length; i++) {
                S[i] = in.nextInt();
            }
            int limit = 1;
            for (int i = 0; i < N; i++) {
                limit *= 2;
            }
            out.println("Case #" + t + ":");
            HashMap<Integer, HashSet<Integer>> history = new HashMap<Integer, HashSet<Integer>>();
            boolean found = false;
            for (int i = 0; i < limit; i++) {
                boolean choosed[] = decode(i, N);
                int sum = 0;
                HashSet<Integer> set = new HashSet<Integer>();
                for (int j = 0; j < S.length; j++) {
                    if (choosed[j]) {
                        sum += S[j];
                        set.add(S[j]);
                    }
                }
                if (history.containsKey(sum)) {
                    HashSet<Integer> another = history.get(sum);
                    display(another, out);
                    display(set, out);
                    found = true;
                    break;
                } else {
                    history.put(sum, set);
                }
            }
            if (!found) {
                out.println("Impossible");
            }
        }

        out.close();
    }

    static boolean[] decode(int code, int size) {
        boolean choosed[] = new boolean[size];
        for (int i = 0; i < choosed.length; i++) {
            choosed[i] = (code % 2 == 0 ? false : true);
            code /= 2;
        }
        return choosed;
    }

    static void display(HashSet<Integer> s, PrintWriter out) {
        for (int a : s) {
            out.print(a + " ");
        }
        out.println();
    }
}
