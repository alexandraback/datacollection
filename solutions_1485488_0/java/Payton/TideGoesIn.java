import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

public class TideGoesIn {
	static class Edge{
		int x, y, w;
		double t;
		Edge(int x, int y, int w, double t){
			this.x = x;
			this.y = y;
			this.w = w;
			this.t = t;
		}
		public String toString(){
			return x + " " + y + " " + w + " " + t;
		}
	}
	static class Priority implements Comparator<Edge>{
		public int compare(Edge ito, Edge iyan){
			if(ito.t > iyan.t)
				return 1;
			else if(ito.t < iyan.t)
				return -1;
			return 0;
		}
	}
	static int n, m;
	static boolean inbounds(int x, int y){
		if(0<=x && x<n && 0<=y && y<m)
			return true;
		return false;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for(int ctr=0; ctr<cases; ctr++){
			int startHeight = sc.nextInt();
			double endTime = 0;
			n = sc.nextInt();
			m = sc.nextInt();
			int[][] ceil = new int[n][m];
			int[][] floor = new int[n][m];
			for(int i=0; i<n; i++)
				for(int j=0; j<m; j++)
					ceil[i][j] = sc.nextInt();

			for(int i=0; i<n; i++)
				for(int j=0; j<m; j++)
					floor[i][j] = sc.nextInt();
			
			LinkedList<Edge> initial = new LinkedList<Edge>();
			LinkedList<Edge> queue = new LinkedList<Edge>();
			queue.addLast(new Edge(0,0,startHeight,0));
			int[] dx = {0,0,1,-1};
			int[] dy = {1,-1,0,0};
			boolean[][] vis = new boolean[n][m];
			vis[0][0] = true;
			while(!queue.isEmpty()){
				Edge p = queue.removeFirst();
				initial.addLast(p);
				for(int i=0; i<4; i++){
					int nx = p.x+dx[i];
					int ny = p.y+dy[i];
					if(inbounds(nx, ny) && !vis[nx][ny]){
						int ft = Math.max(floor[p.x][p.y], floor[nx][ny]);
						int ct = ceil[nx][ny];
						int ch = ceil[p.x][p.y];
						if(ft+50 > ct || ft+50 > ch)
							continue;
						
						if(startHeight+50 <= ct){
							vis[nx][ny] = true;
							Edge e = new Edge(nx, ny, p.w, 0);
							queue.addLast(e);
						}
					}
				}
			}
			PriorityQueue<Edge> pq = new PriorityQueue<Edge>(1000, new Priority());
			while(!initial.isEmpty())
				pq.add(initial.removeFirst());
			vis = new boolean[n][m];
			while(!pq.isEmpty()){
				Edge p = pq.poll();
				if(vis[p.x][p.y]){
					continue;
				}
				
				if(p.x == n-1 &&p.y == m-1){
					endTime = p.t;
					break;
				}
				vis[p.x][p.y] = true;
				
				for(int i=0; i<4; i++){
					int nx = p.x+dx[i];
					int ny = p.y+dy[i];
					if(inbounds(nx, ny) && !vis[nx][ny]){
						int ft = Math.max(floor[p.x][p.y], floor[nx][ny]);
						int ct = ceil[nx][ny];
						int ch = ceil[p.x][p.y];
						if(ft+50 > ct || ft+50 > ch)
							continue;
						
						Edge e = new Edge(nx, ny, p.w, p.t);
						if(p.w+50 > ct){
							e.t = (p.w+50-ct)/10.0;
							e.w = Math.max(ct-50, 0);
						}
						
						if(e.w-floor[p.x][p.y] >= 20){
							e.t += 1.0;
							e.w = Math.max(e.w-10, 0);
						}else{
							e.t += 10.0;
							e.w = Math.max(e.w-100, 0);
						}
						
						pq.add(e);
					}
				}
			}
			
			System.out.printf("Case #%d: %.1f\n", ctr+1, endTime);
		}
	}
}
