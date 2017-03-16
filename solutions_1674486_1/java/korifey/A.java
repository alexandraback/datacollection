package gcj2012.round1c;


import java.util.Arrays;
import java.util.Comparator;

import common.AbstractRunner;
import common.AbstractRunner.SIZE;

public class A extends AbstractRunner {
	
	
	int[][] inherit; 
	boolean[] root;
	boolean[] marked;
	
	private boolean dfs(int x) {
		if (marked[x]) return true;
		marked[x] = true;		
		for (int i=0; i<inherit[x].length; i++) {
			if (dfs(inherit[x][i])) return true;
		}
		return false;
	}
	
	@Override
	public void handleCase(int caseNumber) throws Exception {		
		int n = scanner.nextInt();
		inherit = new int[n][];
		root = new boolean[n];
		Arrays.fill(root, true);
		for (int i=0; i<n; i++) {
			inherit[i] = new int[scanner.nextInt()];
			for (int j=0; j<inherit[i].length; j++) {
				inherit[i][j] = scanner.nextInt()-1;
				root[inherit[i][j]] = false;
			}
		}
		
		marked = new boolean[n];
		for (int i=0; i<n; i++) {
			if (root[i]) {
				Arrays.fill(marked, false);
				if (dfs(i)) {
					out.write("Yes\n");
					return;
				}
			}
		}
		out.write("No\n");
	}
	
	public static void main(String[] args) throws Exception {
		new A().init(SIZE.large).execute();
	}
}

