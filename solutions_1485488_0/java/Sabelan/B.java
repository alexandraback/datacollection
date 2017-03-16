import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;


public class B {
	static int[][] floor, ceiling;
	static int H;
	public static void main(String[] args) throws IOException {
		PrintWriter out = new PrintWriter(new File("B.out"));
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for(int caseOn = 1; caseOn <= cases; caseOn++) {
			System.out.printf("On case %d\n",caseOn);
			H = in.nextInt();
			int n = in.nextInt();
			int m = in.nextInt();
			ceiling = new int[n][m];
			floor = new int[n][m];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					ceiling[i][j]=in.nextInt();
				}
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					floor[i][j]=in.nextInt();
				}
			}
			boolean[][] starts = new boolean[n][m];
			bfs(starts);
			
			double t = djikstras(starts);
			out.printf("Case #%d: %.7f\n",caseOn,t);
		}
		out.close();
	}
	
	public static double djikstras(boolean[][] starts) {
		int tx = floor[0].length-1;
		int ty = floor.length-1;
		PriorityQueue<state> pq = new PriorityQueue<state>();
		boolean[][] visited = new boolean[floor.length][floor[0].length];
		for(int i = 0; i < visited.length; i++) {
			for(int j = 0; j < visited[0].length; j++) {
				visited[i][j] = starts[i][j];
				if(starts[i][j]) {
					pq.add(new state(0,j,i));
				}
			}
		}
		
//		System.out.printf("Starting PQ: %s\n",pq);
		
		int[] dx = new int[]{0,0,1,-1};
		int[] dy = new int[]{1,-1,0,0};
		
		while(!pq.isEmpty()) {
			state t = pq.poll();
//			System.out.printf("At %s\n",t);
			if(visited[t.y][t.x] && ! starts[t.y][t.x])
				continue;
			visited[t.y][t.x]=true;
			if(t.x == tx && t.y == ty) {
				return t.t;
			}
			for(int d = 0; d < 4; d++) {
				int nx = t.x + dx[d];
				int ny = t.y + dy[d];
//				System.out.printf("Trying (%d, %d)\n",nx,ny);
				if(canMove(t.x,t.y,nx,ny)) {
//					System.out.printf("Can move from %s to (%d, %d)\n",t,nx,ny);
					if(!visited[ny][nx]) {
						pq.add(new state(t.t + delta(t.x,t.y,nx,ny,t.t),nx,ny));
					}
				}
			}
		}
		
		return -1;
	}
	
	static double delta(int x1, int y1, int x2, int y2, double t) {
		double l = 0, h = H;
		while(Math.abs(l-h)>1e-10) {
			double m = (l+h)/2.0;
			if(ceiling[y2][x2]-m>50) {
				l=m;
			} else {
				h=m;
			}
		}
		double waterLevel = (l+h)/2;
		double minTime = (H-waterLevel) / 10.0;
		if(t>=minTime) {
			double curWater = H - t*10.0;
			if(curWater-floor[y1][x1]>=20-1e-9)
				return 1.0;
			return 10.0;
		}
		double del = minTime - t;
		double curWater = H - minTime*10.0;
		if(curWater-floor[y1][x1]>=20-1e-9)
			return 1.0+del;
		return 10.0+del;
	}
	
	static boolean canMove(int x1, int y1, int x2, int y2) {
		if(y2 < 0 || x2 < 0 || y2 >= floor.length || x2 >= floor[0].length)
			return false;
		if(ceiling[y2][x2]-floor[y1][x1]<50)
			return false;
		if(ceiling[y2][x2]-floor[y2][x2]<50)
			return false;
		if(ceiling[y1][x1]-floor[y2][x2]<50)
			return false;
		return true;
	}
	
	static class state implements Comparable<state> {
		double t;
		int x,y;
		public state(double t, int x, int y) {
			this.t = t;
			this.x = x;
			this.y = y;
		}
		
		public int compareTo(state o) {
			return Double.compare(t, o.t);
		}
		
		public String toString() {
			return String.format("(%d, %d) t:%.2f",x,y,t);
		}
	}
	
	public static void bfs(boolean[][] starts) {
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(0);
		q.add(0);
		starts[0][0]=true;
		int[] dx = new int[]{0,0,1,-1};
		int[] dy = new int[]{1,-1,0,0};
		while(!q.isEmpty()) {
			int y = q.poll();
			int x = q.poll();
			for(int d = 0; d < 4; d++) {
				int nx = dx[d]+x;
				int ny = dy[d]+y;
				if(canVisitAtStart(y,x,ny,nx) && !starts[ny][nx]) {
					starts[ny][nx]=true;
					q.add(ny);
					q.add(nx);
				}
			}
		}
	}
	
	public static boolean canVisitAtStart(int y1, int x1, int y2, int x2) {
		if(y2 < 0 || x2 < 0 || y2 >= floor.length || x2 >= floor[0].length)
			return false;
		if(ceiling[y2][x2]-floor[y1][x1]<50)
			return false;
		if(ceiling[y2][x2]-H<50)
			return false;
		if(ceiling[y2][x2]-floor[y2][x2]<50)
			return false;
		if(ceiling[y1][x1]-floor[y2][x2]<50)
			return false;
		return true;
	}
}
