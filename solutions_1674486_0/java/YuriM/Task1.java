package c1;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.*;

public class Task1 {

    static int n;

    static int[][] childs;
    static int[][] inherits;

    static List<List<Integer>> chains = new ArrayList<List<Integer>>();

    public static void chain(List<Integer> chain, int element) {
        chain.add(element);
        chains.add(chain);
        for (int child : childs[element]) {
            chain(new ArrayList<Integer>(chain), child);
        }
    }

    public static boolean checkDiamond(List<Integer> a, List<Integer> b) {
        if (a.size() <= 1 || b.size() <= 1) {
            return false;
        }
        if (a.get(0).equals(b.get(0)) && (a.get(a.size() - 1).equals(b.get(b.size() - 1)))) {
            return ! a.equals(b);
        }
        return false;
    }

    public static void doTheJob(int t, Scanner scanner) {
        n = scanner.nextInt();
        inherits =new int[n][];
        chains.clear();
        ArrayList<Integer> roots = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            int s = scanner.nextInt();
            if (s == 0) {
                roots.add(i);
            }
            inherits[i] = new int[s];
            for (int j = 0; j < s; j++) {
                inherits[i][j] = scanner.nextInt() - 1;
            }
        }
        childs = new int[n][];
        ArrayList<Integer> temp = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            temp.clear();
            for (int j = 0; j < n; j++) {
                for (int el : inherits[j]) {
                    if (el == i) {
                        temp.add(j);
                    }
                }
            }
            childs[i] = new int[temp.size()];
            for (int j = 0; j < temp.size(); j++) {
                childs[i][j] = temp.get(j);
            }
        }
        for (int root : roots) {
            chain(new ArrayList<Integer>(), root);
        }
        boolean ok = false;
        for (int i = 0; i < chains.size(); i++) {
            for (int j = i + 1; j < chains.size(); j++) {
                List<Integer> chain1 = chains.get(i);
                List<Integer> chain2 = chains.get(j);
                if (checkDiamond(chain1, chain2)) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        System.out.println("Case #" + t + ": " + (ok ? "Yes" : "No"));
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new FileInputStream("1b_task1.txt"));
        scanner.useLocale(Locale.US);
        int T = scanner.nextInt();
        for (int i = 0; i < T; i++) {
            doTheJob(i + 1, scanner);
        }
    }
}
