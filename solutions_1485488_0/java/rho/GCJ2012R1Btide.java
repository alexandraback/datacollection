import java.util.PriorityQueue;
import java.util.Scanner;


public class GCJ2012R1Btide {
	
	static class vPoint implements Comparable<vPoint>
	{
		int h, x, y;
		public vPoint(int H, int X, int Y)
		{
			h=H;
			x=X;
			y=Y;
		}
		
		public int compareTo(vPoint o) {
			return o.h-h;
		}
		
		@Override
		public String toString() {
			return h+"-("+x+","+y+")";
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		for(int t=1; t<=T; t++)
		{
			int H = sc.nextInt(), N=sc.nextInt(), M=sc.nextInt();
			int[][] ceiling=new int[N][M];
			int[][] floor=new int[N][M];
			for(int i=0; i<N; i++)
				for(int j=0; j<M; j++)
					ceiling[i][j]=sc.nextInt();
			for(int i=0; i<N; i++)
				for(int j=0; j<M; j++)
					floor[i][j]=sc.nextInt();
			PriorityQueue<vPoint> Q = new PriorityQueue<vPoint>();
			Q.add(new vPoint(H, 0, 0));
			int finalH = H+1;
			boolean[][] visited=new boolean[N][M];
			while(!Q.isEmpty())
			{
				vPoint p = Q.poll();
				//System.out.println("("+p+")");
				if(p.x==N-1 && p.y==M-1) //done
				{
					finalH=p.h;
					break;
				}
				if(visited[p.x][p.y])
					continue;
				visited[p.x][p.y]=true;
				
				int[] dx = {0,1,0,-1};
				int[] dy = {1,0,-1,0};
				for(int i=0; i<4; i++)
				{
					//System.out.println("try "+(p.x+dx[i])+", "+(p.y+dy[i]));
					int height = p.h;
					if(!(p.x+dx[i]>=0 && p.x+dx[i]<N && p.y+dy[i]>=0 && p.y+dy[i]<M))//in bounds
						continue;
					//System.out.println("inbounds");
					//System.out.println((floor[p.x][p.y]+50+" "+ceiling[p.x+dx[i]][p.y+dy[i]])+" "+(floor[p.x+dx[i]][p.y+dy[i]]+50+" "+ceiling[p.x+dx[i]][p.y+dy[i]])+" "+(floor[p.x+dx[i]][p.y+dy[i]]+50+" "+ceiling[p.x][p.y]));
					if(!(floor[p.x][p.y]+50<=ceiling[p.x+dx[i]][p.y+dy[i]] && 
					floor[p.x+dx[i]][p.y+dy[i]]+50<=ceiling[p.x+dx[i]][p.y+dy[i]] &&
					floor[p.x+dx[i]][p.y+dy[i]]+50<=ceiling[p.x][p.y]))//can go
						continue;
					//System.out.println("cango");
					if(height==H && height+50<=ceiling[p.x+dx[i]][p.y+dy[i]])//free
						height=H;
					else
					{
						if(height+50>ceiling[p.x+dx[i]][p.y+dy[i]])
							height=ceiling[p.x+dx[i]][p.y+dy[i]]-50;
						if(floor[p.x][p.y]+20<=height)
							height-=10;
						else
							height-=100;
					}
					Q.add(new vPoint(height, p.x+dx[i], p.y+dy[i]));
				}
			}
			if(finalH<=H)
				System.out.printf("Case #%d: %f\n", t, (H-finalH)/10.0);
			else
				System.out.printf("Case #%d: TRAPPED\n", t);
		}
	}
}
