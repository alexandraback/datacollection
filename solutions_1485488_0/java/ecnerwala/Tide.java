import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Tide {
	
	public static Scanner sc;

	public static void main(String[] args) throws Exception{
		char problem = 'B';
		boolean smallCase = true;
		boolean practice = false;
		sc = new Scanner(new File(problem + "-" + (smallCase ? "small" : "large") + (practice ? "-practice" : "") + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(problem + "-" + (smallCase ? "small" : "large") + (practice ? "-practice" : "") + ".out"));
		int t = sc.nextInt();
		for(int i = 1; i <= t; i++) {
			out.println("Case #" + i + ": " + solve());
		}
		out.close();
		System.exit(0);
	}
	
	//ALL TIMES ARE IN TENTH SECONDS!

	public static String solve() {
		int water = sc.nextInt();
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] ceil = new int[n][m];
		int[][] floor = new int[n][m];
		for(int i = 0; i < n; i++) 
			for(int j = 0; j < m; j++)
				ceil[i][j] = sc.nextInt();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				floor[i][j] = sc.nextInt();
				if(floor[i][j] + 50 > ceil[i][j]) ceil[i][j] = 0;
			}
		}
		boolean[][] visited = new boolean[n][m];
		visited[0][0] = true;
		PriorityQueue<Coord> places = new PriorityQueue<Coord>();
		places.add(new Coord(0,0,0));
		while(true) {
			Coord cur = places.poll();
			visited[cur.x][cur.y] = true;
			if(cur.x + 1 == n && cur.y + 1 == m) return cur.t / 10 + "." + cur.t % 10;
			if (cur.x > 0 && !visited[cur.x - 1][cur.y]
					&& ceil[cur.x - 1][cur.y] >= floor[cur.x][cur.y] + 50
					&& ceil[cur.x][cur.y] >= floor[cur.x - 1][cur.y] + 50) {
				int minTime = water + 50 - ceil[cur.x - 1][cur.y];
				if(cur.t >= minTime) minTime = cur.t;
				places.add(new Coord(cur.x - 1, cur.y, (minTime == 0 ? 0 : (minTime + (water - minTime - floor[cur.x][cur.y]>= 20 ? 10 : 100)))));
			}
			if (cur.x + 1 < n && !visited[cur.x + 1][cur.y]
					&& ceil[cur.x + 1][cur.y] >= floor[cur.x][cur.y] + 50
					&& ceil[cur.x][cur.y] >= floor[cur.x + 1][cur.y] + 50) {
				int minTime = water + 50 - ceil[cur.x + 1][cur.y];
				if(cur.t >= minTime) minTime = cur.t;
				places.add(new Coord(cur.x + 1, cur.y, (minTime == 0 ? 0 : (minTime + (water - minTime - floor[cur.x][cur.y]>= 20 ? 10 : 100)))));
			}
			if (cur.y > 0 && !visited[cur.x][cur.y - 1]
					&& ceil[cur.x][cur.y - 1] >= floor[cur.x][cur.y] + 50
					&& ceil[cur.x][cur.y] >= floor[cur.x][cur.y - 1] + 50) {
				int minTime = water + 50 - ceil[cur.x][cur.y - 1];
				if(cur.t >= minTime) minTime = cur.t;
				places.add(new Coord(cur.x, cur.y - 1, (minTime == 0 ? 0 : (minTime + (water - minTime - floor[cur.x][cur.y]>= 20 ? 10 : 100)))));
			}
			if (cur.y + 1 < m && !visited[cur.x][cur.y + 1]
					&& ceil[cur.x][cur.y + 1] >= floor[cur.x][cur.y] + 50
					&& ceil[cur.x][cur.y] >= floor[cur.x][cur.y + 1] + 50) {
				int minTime = water + 50 - ceil[cur.x][cur.y + 1];
				if(cur.t >= minTime) minTime = cur.t;
				places.add(new Coord(cur.x, cur.y + 1, (minTime == 0 ? 0 : (minTime + (water - minTime - floor[cur.x][cur.y]>= 20 ? 10 : 100)))));
			}
		}
	}
	
	static class Coord implements Comparable<Coord>{
		public int x, y, t;
		
		public Coord(int x, int y, int t) {
			this.x = x;
			this.y = y;
			this.t = t;
		}

		@Override
		public int compareTo(Coord o) {
			return this.t - o.t;
		}
		
		
	}

}
