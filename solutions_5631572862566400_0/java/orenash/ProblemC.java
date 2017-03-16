import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class ProblemC {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		Scanner s  = new Scanner(System.in);
		
		int T = s.nextInt();
		
		for (int caseNum=1; caseNum<=T; caseNum++) {
			
			int N = s.nextInt();
			int[] bff = new int[N+1];
			for (int i=1; i<=N; i++) bff[i] = s.nextInt();
			
			int max_circle = -1;
			int[] max_chain = new int[N+1];
			
			for (int i=1; i<=N; i++) {
				
				boolean[] visited = new boolean[N+1];
				int cur = i;
				
				int length = 0;
				while (!visited[cur]) {
					visited[cur] = true;
					cur = bff[cur];
					length++;
				}
				
				if (cur==i) {
					max_circle = Math.max(max_circle, length);
				}
				
				if (bff[bff[cur]]==cur) {
					max_chain[cur] = Math.max(max_chain[cur], length);
				}
			}
			
			int total_chain = 0;
			
			for (int i=1; i<=N; i++) {
				if (max_chain[i]>0) {
					total_chain += max_chain[i] + max_chain[bff[i]] - 2;
					max_chain[bff[i]] = 0;
				}
			}
			
			
			System.out.printf("Case #%d: %d\n", caseNum, Math.max(total_chain, max_circle));
		}
	}
}
