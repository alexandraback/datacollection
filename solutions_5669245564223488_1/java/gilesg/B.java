import java.util.*;
import static java.lang.Math.*;
public class B {
    static final int M = 26;
    static final long P = 1000 * 1000 * 1000 + 7;

	void run() {
		Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int N = sc.nextInt();

            int[][] graph = new int[M][M];
            int[] pure_chunks = new int[M];
            int num_edges = 0;
            int[] used = new int[M];
            for (int i = 0; i < N; ++i) {
                char[] c = sc.next().toCharArray();
                boolean marked = false;
                for (int j = 0; j < c.length; ++j) {
                    int a = c[j] - 'a';
                    used[a] = 1;
                }
                for (int j = 0; j < c.length-1; ++j) {
                    int a = c[j] - 'a';
                    int b = c[j+1] - 'a';
                    if (a != b) {
                        marked = true;
                        ++graph[a][b];
                        ++num_edges;
                    }
                }
                if (!marked)
                    ++pure_chunks[c[0] - 'a'];
            }

            int num_used = 0;
            for (int i = 0; i < M; ++i) {
                num_used += used[i];
            }


            long ANS = solve(graph, pure_chunks, num_used, num_edges);

            p("Case #%d: %d\n", caseNum, ANS);
        }
	}

    int get_next(int[][] graph, int curr) {
        for (int i = 0; i < M; ++i) {
            if (graph[curr][i] > 0)
                return i;
        }
        return -1;
    }

    long solve(int[][] graph, int[] pure_chunks, int num_used, int num_edges) {
        int[] in_deg = new int[M];
        int[] out_deg = new int[M];
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                in_deg[j] += graph[i][j];
                out_deg[i] += graph[i][j];
            }
        }

        // check for repeated occurences of "x precedes y"
        for (int i = 0; i < M; ++i) {
            if (in_deg[i] > 1 || out_deg[i] > 1) {
                return 0;
            }
        }

        // check for cycles
        for (int i = 0; i < M; ++i) {
            int curr = i;
            while (curr >= 0) {
                curr = get_next(graph, curr);
                if (curr == i)
                    return 0; // cycle found
            }
        }

        int num_chains = num_used - num_edges;

        long ret = factorial(num_chains);
        for (int i = 0; i < M; ++i) {
            ret *= factorial(pure_chunks[i]);
            ret %= P;
        }
        return ret;
    }

    long factorial(int M) {
        if (M <= 1)
            return 1;
        return (M * factorial(M-1)) % P;
    }

	boolean debug = true;
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
	void timeout() {
		for (int x = 0; ; ++x);
	}
	public B(String[] args) {
		if (args.length > 0 && args[0].equals("debug")) {
			debug = true;
		}
	}
	public static void main(String[] args) {
		new B(args).run();
	}
}
