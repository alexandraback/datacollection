import java.util.*;

public class Technobabble {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			System.out.printf("Case #%d:", t);
			int n = in.nextInt();
			
			ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
			
			int cnt = 0, x = 0, y = 0;
			HashMap<String, Integer> map1 = new HashMap<>();
			HashMap<String, Integer> map2 = new HashMap<>();
			for (int i = 0; i < n; i++) {
				String s1 = in.next(), s2 = in.next();
				int a,b;
				if (map1.containsKey(s1)) {
					a = map1.get(s1);
				} else {
					adj.add(new ArrayList<Integer>());
					map1.put(s1, cnt);
					a = cnt++;
					x++;
				}
				if (map2.containsKey(s2)) {
					b = map2.get(s2);
				} else {
					adj.add(new ArrayList<Integer>());
					map2.put(s2, cnt);
					b = cnt++;
					y++;
				}
				
				adj.get(a).add(b);
			}
			
			BipartiteMatching bm = new BipartiteMatching(adj);
			int mm = bm.findMaxMatching();
			
			int count = 0;
			for (int m = 0; m < bm.match.length; m++) {
				if (bm.match[m] != -1) {
					count += 2;
				}
			}
			
			mm += x + y - count;
			
			
			System.out.printf(" %d\n", n - mm);
		}
	}
	
	public static class BipartiteMatching {
		  int[] match;
		  int matches = 0;
		  boolean[] done;
		  int N;

		  ArrayList<ArrayList<Integer>> adj;

		  // Initialized with Adjacency List.
		  public BipartiteMatching(ArrayList<ArrayList<Integer>> adj) {
		    this.adj = adj;
		    N = adj.size();
		    match = new int[N];
		    Arrays.fill(match, -1);
		  }

		  // Returns matching size and populates match[] with
		  // the details. -1 indicates no match.
		  public int findMaxMatching() {
		    for (int i = 0; i < N; i++) {
		      done = new boolean[N];
		      if (augment(i)) matches++;
		    }
		    return matches;
		  }

		  // Attempt to find an augmenting path.
		  public boolean augment(int at) {
		    if (done[at]) return false;
		    done[at] = true;

		    ArrayList<Integer> edges = adj.get(at);
		    for (int i = 0; i < edges.size(); i++) {
		      int to = edges.get(i);
		      if (match[to] == -1 || augment(match[to])) {
		        match[to] = at;
		        return true;
		      }
		    }
		    return false;
		  }
		}
}
