import java.io.BufferedReader;
import java.io.*;
import java.util.*;

public class gc_2016_1b_c {
    static int maxn = 10000;

    static Scanner scanner;
    static int tests, test;


    static int n, nodes, m, ans, maxmatch;
    static Map<String, Integer> map = new HashMap<String, Integer>();
    static Set<Integer> left = new HashSet<Integer>();
    static Set<Integer> right = new HashSet<Integer>();
    static int[][] adjL;
    static int[] match;
    static boolean[] visit;

    public static boolean dfs(int now) {
        for (int i = 1; i <= adjL[now][0]; ++i) {
            int j = adjL[now][i];
            if (!visit[j]) {
                visit[j] = true;
                if (match[j] == -1 || dfs(match[j])) {
                    match[j] = now;
                    return true;
                }
            }
        }
        return false;
    }

    public static void solve() {
        maxmatch = 0;
        Arrays.fill(match, -1);
        for (int i = 0; i < m; ++i) {
            Arrays.fill(visit, false);
            if (dfs(i))
                ++maxmatch;
        }
    }

    public static int getNum(String word) {
        if (!map.containsKey(word))
            map.put(word, m++);
        return map.get(word);
    }

    public static void init() {
        m = 0;

        adjL = new int[maxn][];
        for (int i = 0; i < maxn; ++i)
            adjL[i] = new int[maxn];
        match = new int[maxn];
        visit = new boolean[maxn];
    }

    public static void clearV() {
        left.clear();
        right.clear();
        map.clear();
        m=0;
        for (int i = 0; i < maxn; ++i)
            adjL[i][0] = 0;

    }

    public static void main(String args[]) throws IOException {
        final String f = "C-large";
        init();
        BufferedReader in = new BufferedReader(new FileReader(f + ".in"));
        scanner = new Scanner(in);
        tests = scanner.nextInt();
        PrintWriter out = new PrintWriter(f + ".out");

        for (test = 1; test <= tests; ++test) {
            n = scanner.nextInt();

            clearV();

            for (int i = 0; i < n; ++i) {
                int n1 = getNum(scanner.next());
                int n2 = getNum(scanner.next());
                left.add(n1);
                right.add(n2);
                adjL[n1][ ++adjL[n1][0] ] = n2;
            }

            solve();

            // min edge cover = #nodes - max match

            nodes = left.size() + right.size();
            int minEC = nodes - maxmatch;
            ans = n - minEC;


			System.out.printf("max match: %d\n", maxmatch);
			System.out.printf("nodes: %d\n", nodes);
			System.out.printf("min edge cover: %d\n", minEC);


            out.printf("Case #%d: %d\n", test, ans);
        }
        in.close();
        out.close();
    }
}
