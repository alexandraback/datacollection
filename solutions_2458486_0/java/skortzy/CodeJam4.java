import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.SortedSet;
import java.util.TreeSet;

/**
 * Created by IntelliJ IDEA.
 * User: skortzy
 * Date: 13.04.2013
 * Time: 13:52
 * To change this template use File | Settings | File Templates.
 */
public class CodeJam4 {

    static int K;
    static int N;
    static int[] availableKeys;
    static int[] openKeys;
    static ArrayList<Integer>[] insideKeys;
    static int[] solution;
    static boolean found = false;
    static boolean[] open;
    static long start;
    static boolean stop = false;

    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String line = br.readLine();
            int T = Integer.parseInt(line);
            for (int i = 1; i <= T; i++) {
                String[] values = br.readLine().split(" ");
                K = Integer.parseInt(values[0]);
                N = Integer.parseInt(values[1]);
                availableKeys = new int[201];
                openKeys = new int[N];
                insideKeys = new ArrayList[N];
                open = new boolean[N];
                values = br.readLine().split(" ");
                for (int j = 0; j < K; j++) {
                    availableKeys[Integer.parseInt(values[j])]++;
                }
                solution = new int[N];
                for (int j = 0; j < N; j++) {
                    solution[j] = -1;
                    open[j] = false;
                    values = br.readLine().split(" ");
                    openKeys[j] = Integer.parseInt(values[0]);
                    int count = Integer.parseInt(values[1]);
                    insideKeys[j] = new ArrayList<Integer>();
                    for (int k = 0; k < count; k++) {
                        insideKeys[j].add(Integer.parseInt(values[k + 2]));
                    }
                }

//                for (int j = 0; j < N; j++) {
//                    System.out.println(openKeys[j]);
//                }
//
//                System.out.println();
                System.out.print("Case #" + i + ":");





                found = false;
                if (ckeck()) {
                    start = System.currentTimeMillis();
                    stop = false;
                    solve(0);
                }
                if (!found) {
                    System.out.println(" IMPOSSIBLE");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    private static boolean ckeck() {
        int total[] = new int[201];
        for (int i = 0; i < 201; i++) {
            total[i] = availableKeys[i];
        }
        for (int i = 0; i < N; i++) {
            for (int key : insideKeys[i]) {
                total[key]++;
            }
            total[openKeys[i]]--;
        }
        for (int i = 0; i < 201; i++) {
            if (total[i] < 0) {
                return false;
            }
        }
        return true;
    }

    private static void solve(int step) {
        if (System.currentTimeMillis() - start > 10000) {
            stop = true;
        }

        if (found || stop) {
            return;
        }

        //printSolution();

        if (step == N) {
            found = true;
            printSolution();
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!open[i]) {
                int key = openKeys[i];
                if (availableKeys[key] > 0) {
                    open[i] = true;
                    availableKeys[key]--;
                    for (int newKey : insideKeys[i]) {
                        availableKeys[newKey]++;
                    }
                    solution[step] = i;
                    solve(step + 1);
                     solution[step] = -1;
                    for (int newKey : insideKeys[i]) {
                        availableKeys[newKey]--;
                    }
                    availableKeys[key]++;
                    open[i] = false;
                }
            }
        }
    }

    private static void printSolution() {
        for (int i = 0; i < N; i++) {
            System.out.print(" " + (solution[i] + 1));
        }
        System.out.println();
    }

}
