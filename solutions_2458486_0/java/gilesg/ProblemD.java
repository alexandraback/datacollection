// @gilesgardam
import java.util.*;
import static java.lang.Math.*;

public class ProblemD {
    int M = 200;
    boolean[] seen;

    void run() {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int K = sc.nextInt();
            int N = sc.nextInt();
            int[] keys = new int[M];
            int[][] chests = new int[N][];
            int[] chest_types = new int[N];
            seen = new boolean[1 << N];

            for (int i = 0; i < K; ++i) {
                ++keys[sc.nextInt()];
            }

            for (int i = 0; i < N; ++i) {
                chest_types[i] = sc.nextInt();
                int ki = sc.nextInt();
                chests[i] = new int[ki];
                for (int j = 0; j < ki; ++j) {
                    chests[i][j] = sc.nextInt();
                }
            }

            LinkedList<Integer> sol = new LinkedList<Integer>();

            solve(keys, chests, chest_types, sol);

            String answer = "IMPOSSIBLE";
            if (!sol.isEmpty()) {
                answer = "";
                for (int i = 0; i < sol.size(); ++i) {
                    if (i > 0) {
                        answer += " ";
                    }
                    answer += sol.get(i)+1;
                }
            }
            System.out.printf("Case #%d: %s\n", caseNum, answer);
        }
    }

    int set_digest(List<Integer> a) {
        int res = 0;
        for (int x : a) {
            res |= (1 << x);
        }
        return res;
    }

    void solve(int[] keys, int[][] chests, int[] chest_types, LinkedList<Integer> sol) {
        int N = chest_types.length;
        int digest = set_digest(sol);
        if (seen[digest]) {
            return;
        }
        else {
            seen[digest] = true;
        }

        for (int i = 0; i < N; ++i) {
            if (sol.indexOf(i) >= 0) { // already opened
                continue;
            }
            if (keys[chest_types[i]] == 0) { // can't open
                continue;
            }
            // open
            keys[chest_types[i]] -= 1;
            for (int x : chests[i]) {
                ++keys[x];
            }
            sol.add(i);

            // try recursing
            solve(keys, chests, chest_types, sol);
            if (sol.size() == N) {
                break;
            }

            // undo opening
            keys[chest_types[i]] += 1;
            for (int x : chests[i]) {
                --keys[x];
            }
            sol.removeLast();
        }
    }

    boolean debug = false;
    void p(String f, Object...params) {
        System.out.printf(f, params);
    }
    void d(Object...params) {
        if (debug) {
            p("DEBUG: %s\n", Arrays.deepToString(params));
        }
    }
    void die() {
        throw new RuntimeException();
    }
    public ProblemD(String[] args) {
        if (args.length > 0 && args[0].equals("debug")) {
            debug = true;
        }
    }
    public static void main(String[] args) {
        new ProblemD(args).run();
    }
}
