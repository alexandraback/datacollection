package round1B;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

public class B {

	String solve(Scanner in) throws IOException {
		int h = in.nextInt(), n = in.nextInt(), m = in.nextInt();
		int[][] ceil = new int[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				ceil[i][j] = in.nextInt();
		int[][] floor = new int[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				floor[i][j] = in.nextInt();
		
		PriorityQueue<State> pq = new PriorityQueue<State>();
		int[][] times = new int[n][m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				times[i][j] = 1<<30;
		
		int[] dx = {0,1,0,-1}, dy = {1,0,-1,0};
		
		pq.offer(new State(0,0,0));
		times[0][0] = 0;
		while(!pq.isEmpty()) {
			State cur = pq.poll();
			if(times[cur.x][cur.y] < cur.time)
				continue;

			if(cur.x == n-1 && cur.y == m-1)
				break;
			
			for(int i = 0; i < 4; i++) {
					int tx = cur.x + dx[i], ty = cur.y + dy[i], time = times[cur.x][cur.y], water = h - time;
					if(0 <= tx && tx < n && 0 <= ty && ty < m 
						&& ceil[tx][ty] >= floor[tx][ty]+50 && ceil[tx][ty] >= floor[cur.x][cur.y]+50
						&& ceil[cur.x][cur.y] >= floor[tx][ty]+50) {
						
						int wait = ceil[tx][ty] >= water+50 ? 0 : water+50-ceil[tx][ty];
						int cost = water - wait - floor[cur.x][cur.y] >= 20 ? 10 : 100;
						if(wait == 0 && time == 0)
							cost = 0;
						
						if(time + wait + cost < times[tx][ty]) {
							times[tx][ty] = time + wait + cost;
							pq.offer(new State(tx, ty, times[tx][ty]));
						}
					}
				}
		}
		
		return "" + times[n-1][m-1]/10.0;
	}
	
	class State implements Comparable<State> {
		int x,y,time;
		public State(int x, int y, int time) {this.x = x; this.y = y; this.time = time;}
		public int compareTo(State other) {return this.time - other.time;}
	}
	
/*************************************************************************************************/
	
	public static void main(String[] args) throws IOException {
		for(File f : new File(".").listFiles())
			if(f.isFile() && f.getName().startsWith(B.class.getSimpleName() + "-")
					      && f.getName().endsWith(".in")) {
				
				Scanner in = new Scanner(new FileReader(f));
				PrintWriter out = new PrintWriter(new FileWriter(f.getName() + ".out"));
				
				int cases = in.nextInt(); in.nextLine();
				for(int caseno = 1; caseno <= cases; caseno++)
					out.printf("Case #%d: %s%n", caseno, new B().solve(in));
				
				out.close();
			}
	}
}
