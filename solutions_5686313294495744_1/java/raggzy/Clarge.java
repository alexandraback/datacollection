package codejam.y2016.round1b;

import codejam.template.Runner;
import codejam.template.Solver;

import java.io.PrintStream;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Created by raggzy on 4/30/2016.
 */
public class Clarge extends Solver {
    public Clarge(Scanner in, PrintStream out, int TC) {
        super(in, out, TC);
    }

    int m, n;
    boolean[][] graph;
    boolean seen[];
    int matchL[];
    int matchR[];

    // adopted FROM https://gist.github.com/irpap/3464112
    int maxBpm() {
        matchL = new int[m];
        matchR = new int[n];
        seen = new boolean[n];

        Arrays.fill(matchL, -1);
        Arrays.fill(matchR, -1);

        int count = 0;
        for (int i = 0; i < m; i++) {
            Arrays.fill(seen, false);
            if (bpm(i)) count++;
        }
        return count;
    }

    boolean bpm(int u) {
        //try to match with all vertices on right side
        for (int v = 0; v < n; v++) {
            if (!graph[u][v] || seen[v]) continue;
            seen[v] = true;
            //match u and v, if v is unassigned, or if v's match on the left side can be reassigned to another right vertex
            if (matchR[v] == -1 || bpm(matchR[v])) {
                matchL[u] = v;
                matchR[v] = u;
                return true;
            }
        }
        return false;
    }

    @Override
    public void solve() {
        int N = in.nextInt();
        String[] L = new String[N];
        String[] R = new String[N];
        for (int i = 0; i < N; i++) {
            L[i] = in.next();
            R[i] = in.next();
        }
        // remap and build graph
        List<String> left = new ArrayList<>(Arrays.stream(L).collect(Collectors.toSet()));
        List<String> right = new ArrayList<>(Arrays.stream(R).collect(Collectors.toSet()));
        m = left.size();
        n = right.size();
        graph = new boolean[m][n];
        for (int i = 0; i < N; i++) {
            int l = left.indexOf(L[i]);
            int r = right.indexOf(R[i]);
            graph[l][r] = true;
        }
        maxBpm();
        // adding who matched exactly
        Set<String> realL = new HashSet<>();
        Set<String> realR = new HashSet<>();
        int fakes = N;
        for (int i = 0; i < N; i++) {
            int l = left.indexOf(L[i]);
            int r = right.indexOf(R[i]);
            if (matchL[l] == r) {
                realL.add(L[i]);
                realR.add(R[i]);
                fakes--;
            }
        }
        // adding else who can not be fakes
        for (int i = 0; i < N; i++) {
            if (!(realL.contains(L[i]) && realR.contains(R[i]))) {
                realL.add(L[i]);
                realR.add(R[i]);
                fakes--;
            }
        }
        println(String.format("Case #%d: %d", TC, fakes));
    }

    public static void main(String[] args) throws Exception {
        Runner.main(Clarge.class);
    }
}
