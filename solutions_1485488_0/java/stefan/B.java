import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;


public class B {
	public static final String FILENAME = "B-small";
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("/home/useruser/datacollection/input/1485488_0.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"+FILENAME+".out"));
		Scanner s = new Scanner(in);
		int T = s.nextInt();
		for(int i = 1; i <= T; i++) {
			System.out.println(i);
			int H = s.nextInt();
			int H_start = H;
			int N = s.nextInt();
			int M = s.nextInt();
			PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
			int[][] ceiling = new int[N][M];
			int[][] floor = new int[N][M];
			for(int j = 0; j < N; j++) {
				for(int k = 0; k < M; k++) {
					ceiling[j][k] = s.nextInt();
					if(H > ceiling[j][k] - 50 && !pq.contains(-(ceiling[j][k] - 50))) {
						pq.add(-(ceiling[j][k] - 50));
					}
				}
			}
			for(int j = 0; j < N; j++) {
				for(int k = 0; k < M; k++) {
					floor[j][k] = s.nextInt();
				}
			}
			int[][] reachable = new int[N][M];
			for(int j = 0; j < N; j++) {
				for(int k = 0; k < M; k++) {
					reachable[j][k] = Integer.MAX_VALUE;
				}
			}
			reachable[0][0] = 0;
			Stack<Integer> stack = new Stack<Integer>();
			Stack<Integer> all_reachable = new Stack<Integer>();
			stack.add(0);
			all_reachable.add(0);
			while(!stack.isEmpty()) {
				int tmp = stack.pop();
				int n = tmp / M;
				int m = tmp % M;
				int adj[][] = new int[4][2];
				adj[0][0] = n-1; adj[0][1] = m;
				adj[1][0] = n+1; adj[1][1] = m;
				adj[2][0] = n; adj[2][1] = m-1;
				adj[3][0] = n; adj[3][1] = m+1;
				for(int[] ad : adj) {
					if(0 <= ad[0] && ad[0] < N && 0 <= ad[1] && ad[1] < M) {
						if(reachable[ad[0]][ad[1]] > reachable[n][m]) {
							if(H + 50 <= ceiling[ad[0]][ad[1]] && floor[n][m] + 50 <= ceiling[ad[0]][ad[1]] && floor[ad[0]][ad[1]] + 50 <= ceiling[ad[0]][ad[1]] && floor[ad[0]][ad[1]] + 50 <= ceiling[n][m]) {
								reachable[ad[0]][ad[1]] = reachable[n][m];
								if(!stack.contains(ad[0] * M + ad[1])) {
									stack.add(ad[0] * M + ad[1]);
								}
								if(!all_reachable.contains(ad[0] * M + ad[1])) {
									all_reachable.add(ad[0] * M + ad[1]);	
								}
							}
						}
					}
				}
			}
			int time = 0;
			while(!(pq.isEmpty() || (reachable[N-1][M-1] < Integer.MAX_VALUE && reachable[N-1][M-1] <= time))) {
				H = -pq.poll();
				time = H_start - H;
				stack.addAll(all_reachable);
				while(!stack.isEmpty()) {
					int tmp = stack.pop();
					int n = tmp / M;
					int m = tmp % M;
					int adj[][] = new int[4][2];
					adj[0][0] = n-1; adj[0][1] = m;
					adj[1][0] = n+1; adj[1][1] = m;
					adj[2][0] = n; adj[2][1] = m-1;
					adj[3][0] = n; adj[3][1] = m+1;
					int start = Math.max(reachable[n][m], time);
					for(int[] ad : adj) {
						if(0 <= ad[0] && ad[0] < N && 0 <= ad[1] && ad[1] < M) {
							if(reachable[ad[0]][ad[1]] > start+(H_start - start - floor[n][m] >= 20 ? 10 : 100)) {
								if(H + 50 <= ceiling[ad[0]][ad[1]] && floor[n][m] + 50 <= ceiling[ad[0]][ad[1]] && floor[ad[0]][ad[1]] + 50 <= ceiling[ad[0]][ad[1]] && floor[ad[0]][ad[1]] + 50 <= ceiling[n][m]) {
									reachable[ad[0]][ad[1]] = start+(H_start - start - floor[n][m] >= 20 ? 10 : 100);
									if(!stack.contains(ad[0] * M + ad[1])) {
										stack.add(ad[0] * M + ad[1]);
									}
									if(!all_reachable.contains(ad[0] * M + ad[1])) {
										all_reachable.add(ad[0] * M + ad[1]);	
									}
								}
							}
						}
					}
				}	
				int a = 0;
			}
			
			out.write("Case #"+i+": "+(reachable[N-1][M-1])/10.0+"\n");
		}
		in.close();
		out.close();
	}
}
