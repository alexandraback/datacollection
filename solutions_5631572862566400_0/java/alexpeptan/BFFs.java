package round1A_Problem3;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class BFFs {

	public static void main(String[] args) throws NumberFormatException, IOException {
		PrintWriter writer = new PrintWriter("/Users/alexpeptan/Desktop/Eclipse Workspace/Google Code Jam 2016/src/round1A_Problem3/1A3.out", "UTF-8");
		Scanner scanner = new Scanner(new File("/Users/alexpeptan/Desktop/Eclipse Workspace/Google Code Jam 2016/src/round1A_Problem3/1A3.in"));
		
		int t = scanner.nextInt();
		
		int max = 0;
		
		for(int k=0; k<t; k++){
			int n = scanner.nextInt();
			
			int[] bff = new int[n+1];
			List<Integer>[] ibff = new ArrayList[n+1];
			for(int i=1; i<=n; i++){
				ibff[i] = new ArrayList<Integer>();
			}
			
			for(int i=1; i<=n; i++){
				bff[i] = scanner.nextInt();
				ibff[bff[i]].add(i); // bff[i] can be reached from i
			}
			
			int res = solve(bff, ibff);
			
			writer.println("Case #" + (k+1) + ": " + res);
		}
		writer.close();
	}
	
	private static int max1 = 0, max2 = 0;
	
	private static void dfs1(int st, List<Integer>[] ibff, int lvl, int rr){
		max1 = (int)Math.max(max1, lvl);
		
		for(int inv : ibff[st]){
			if(inv != rr){
				dfs1(inv, ibff, lvl+1, rr);
			}
			
		}
	}
	
	private static void dfs2(int st, List<Integer>[] ibff, int lvl, int rr){
		max2 = (int)Math.max(max2, lvl);
		
		for(int inv : ibff[st]){
			if(inv != rr){
				dfs2(inv, ibff, lvl+1, rr);
			}
			
		}
	}
	
	private static int solve(int[] bff, List<Integer>[] ibff){
		// do we have reciprocals?
		int n = bff.length - 1;
		
		int[][] rec = new int[2][n/2]; // at most
		int nrec = 0;
		for(int i=1; i<=n; i++){
			if(i < bff[i] && bff[bff[i]] == i){ // i and bff[i] are reciprocals - and we count them only once
				rec[0][nrec] = i;
				rec[1][nrec++] = bff[i]; 
			}
		} // in the end there will be nrec reciprocals
		
		// if not - need the longest circuit length
		int res = 0;
		if(nrec == 0){
			for(int st = 1; st<=n; st++){
				int[] order = new int[n+1]; // on what step was person x reached
				for(int i=1; i<=n; i++){ order[i] = -1; }
				Set<Integer> set = new HashSet<Integer>();
				set.add(st);
				int len = 0;
				int cur = st;
				order[cur] = len; // or step
				while(!set.contains(bff[cur])){
					set.add(bff[cur]);
					len++;
					cur = bff[cur];
					order[cur] = len;
				}
				
				int circLen = len - order[bff[cur]] + 1;
				res = (int)Math.max(res, circLen);
			}
		}
		
		// if yes - need the Max(longest circuit length, 1 + Max(a-chain + b-chain)) (where (a,b) are reciprocal bff)
		for(int i=0; i<nrec; i++){
			max1 = 0;
			dfs1(rec[0][i], ibff, 1, rec[1][i]);
			max2 = 0;
			dfs2(rec[1][i], ibff, 1, rec[0][i]);
			
			res = (int)Math.max(res, max1 + max2);
		}
		
		
		return res;
	}

}
