package qualA2016;

import java.util.*;

public class C {
	public static void main(String... args) {
		Scanner s = new Scanner(System.in);
		
		final int T = s.nextInt();
		
		for (int t = 1; t <= T; t++) {
			N = s.nextInt();
			bff = new int[N];
			
			for (int i = 0; i < N; i++) bff[i] = s.nextInt() - 1;
			
			System.out.printf("Case #%d: %d\n", t, solve());
		}
		
		s.close();
	}
	
	static int N, ncomps;
	static int[] bff, comps;
	static boolean[] visited;
	static List<Integer> l;
	static List<List<Integer>> ins;
	
	static int solve() {
		ins = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			List<Integer> ll = new ArrayList<>();
			ins.add(ll);
			
			for (int j = 0; j < N; j++) {
				if (bff[j] == i) {
					ll.add(j);
				}
			}
		}
		
		visited = new boolean[N];
		
		l = new ArrayList<>();
		for (int i = 0; i < N; i++) visit(i);
		Collections.reverse(l);
		
		comps = new int[N];
		Arrays.fill(comps, -1);
		
		ncomps = 0;
		for (int i : l) {
			assign(i, i);
		}
		
		// make list of connected component sets
		List<Set<Integer>> ss = new ArrayList<>();
		for (int i = 0; i < N; i++) ss.add(new HashSet<Integer>());
		int[] nc = new int[N];
		for (int i = 0; i < N; i++) {
			nc[comps[i]]++;
			ss.get(comps[i]).add(i);
		}
		
		// find largest "normal" cc
		int max = 0;
		for (int i = 0; i < N; i++) {
			max = (max < nc[i]) ? nc[i] : max;
		}
		
		// check to see if we have a longer cc from a "two way" one
		for (int i = 0; i < N; i++) {
			if (nc[i] == 2) {
				Set<Integer> st = ss.get(i);
				Iterator<Integer> it = st.iterator();
				int a = it.next(), b = it.next();
				
				Arrays.fill(visited, false);
				
				visited[b] = true;
				int l = getDist(a);
				visited[b] = false;
				visited[a] = true;
				int l2 = getDist(b);
				
				int fl = l + l2;
				
				max = (max > fl) ? max : fl;
			}
		}
		
		return max;
	}
	
	static int getDist(int i) {
		if (visited[i]) return 0;
		
		int m = 0;
		for (int x : ins.get(i)) {
			int d = getDist(x);
			m = (m < d) ? d : m;
		}
		
		return m + 1;
	}
	
	static void assign(int u, int root) {
		if (comps[u] != -1) {
			return;
		}
		
		if (u == root) {
			comps[root] = ncomps++;
		}
		
		comps[u] = comps[root];
		
		for (int i : ins.get(u)) {
			assign(i, root);
		}
	}
	
	static void visit(int u) {
		if (visited[u]) return;
		
		visited[u] = true;
		visit(bff[u]);
		l.add(u);
	}
}
