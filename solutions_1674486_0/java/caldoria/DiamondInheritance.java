package round1c;

import java.util.*;

public class DiamondInheritance {

	static int[] pre;
	static int[] post;
	static int clock;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		outer: for (int k = 1; k <= T; k++) {
			
			int N = sc.nextInt();
			
			int[][] adjm = new int[N][];
			pre = new int[N];
			post = new int[N];
			for (int i = 0; i < N; i++) {
				adjm[i] = new int[N];
				int M = sc.nextInt();
				for (int j = 0; j < M; j++) {
					int ix = sc.nextInt();
					adjm[i][ix-1] = 1;
				}
				//System.out.println(Arrays.toString(adjm[i]));
			}
			
			clock = 1;
			
			HashSet<Integer> visited = new HashSet<Integer>();
			while (visited.size() < N) {
				for (int i = 0; i < N; i++) {
					if (!visited.contains(i)) {
						HashSet<Integer> thisvisited = new HashSet<Integer>();
						if (explore(adjm, i, visited, thisvisited)) {
							System.out.println("Case #" + k + ": " + "Yes");
							continue outer;
						}
					}
				}
			}
			System.out.println("Case #" + k + ": " + "No");
			
//			System.out.println(Arrays.toString(pre));
//			System.out.println(Arrays.toString(post));
//			
//			for (int i = 0; i < N; i++) {
//				for (int j = 0; j < N; j++) {
//					if (adjm[i][j] != 0) {
//						
//					}
//				}
//			}
//			
//			System.out.println("Case #" + k + ": ");
			
		}
		
	}
	
	public static boolean explore(int[][] adjm, int v, HashSet<Integer> visited, HashSet<Integer> thisvisited) {
		visited.add(v);
		thisvisited.add(v);
		previsit(v);
		for (int i = 0; i < adjm[v].length; i++) {
			if (adjm[v][i] != 0) {
				if (thisvisited.contains(i)) {
					//System.out.println("Second path from " + v + " to " + i);
					return true;
				} else {
					if (!thisvisited.contains(i)) {
						boolean res = explore(adjm, i, visited, thisvisited);
						if (res) return true;
					}
				}
			}
		}
		postvisit(v);
		return false;
	}
	
	public static void previsit(int v) {
		pre[v] = clock++;
	}
	
	public static void postvisit(int v) {
		post[v] = clock++;
	}

}
