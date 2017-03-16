import java.util.*;
import java.io.*;

public class A {
	public static void main(String[] args)  throws Exception{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for(int caseNo = 1; caseNo <= T; caseNo++) {
			int N = in.nextInt();
			
			int[][] adj = new int[N][N];
			for(int i=0;i<N;i++)Arrays.fill(adj[i],0);
			
			for(int i=0;i<N;i++) {
				int cnt = in.nextInt();
				for(int k=0;k<cnt;k++) {
					int j = in.nextInt()-1;
					adj[i][j] = 1;
				}
			}
			
			for(int k=0;k<N;k++) {
				for(int i=0;i<N;i++){ 
					for(int j=0;j<N;j++) {
						adj[i][j] += adj[i][k] * adj[k][j];
					}
				}
			}
			
			boolean can = false;
			for(int i=0;i<N;i++) {
				for(int j=0;j<N;j++) {
					if (adj[i][j]  > 1) {
						can = true;
						break;
					}
				}
				if (can) break;
			}
			
			System.out.println("Case #"+caseNo+": "+(can ? "Yes" : "No"));
		}
	}
}