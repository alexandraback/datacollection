import java.io.*;
import java.math.*;
import java.util.*;

public class TideInOut
{
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		for(int caseId=1,totalCases=sc.nextInt();caseId<=totalCases;caseId++)
		{
			System.out.print("Case #"+caseId+": ");
			
			//Add logic here
			System.out.println(solveCase());
			
			System.out.flush();
		}
	}
	
	static class Square implements Comparable<Square> {
		int time, row, col;
		boolean inQ = true;
		public Square(int time, int row, int col) {
			this.time = time;
			this.row = row;
			this.col = col;
		}
		public int compareTo(Square s) {
			return time!=s.time ? time - s.time :
				row != s.row ? row - s.row : col - s.col;
		}
	}
	
	public static double solveCase() {
		H = sc.nextInt();
		m = sc.nextInt(); n = sc.nextInt();
		ceil = new int[m][n]; for(int i=0;i<m;i++) for(int j=0;j<n;j++) ceil[i][j] = sc.nextInt();
		floor = new int[m][n]; for(int i=0;i<m;i++) for(int j=0;j<n;j++) floor[i][j] = sc.nextInt();
		
		vis = new boolean[m][n];
		recurse(0, 0);
		
		best = new Square[m][n];
		for(int i=0;i<m;i++) for(int j=0;j<n;j++)
			best[i][j] = new Square(vis[i][j] ? 0 : Integer.MAX_VALUE, i, j);
		
		SortedSet<Square> queue = new TreeSet<Square>();
		for(Square[] arr:best) for(Square s:arr) queue.add(s);
		
		while(queue.size() > 0) {
			Square s = queue.first();
			queue.remove(s);
			s.inQ = false;
			
			assert s.time != Integer.MAX_VALUE;
			//A.spr("Time for "+s.row+", "+s.col+": "+s.time);
			
			if(s.row+1==m && s.col+1==n)
				return s.time / 10.0;
			
			for(int i=0;i<4;i++) {
				int nr = s.row + dr[i];
				int nc = s.col + dc[i];
				if(nr<0 || nr>=m || nc<0 || nc>=n || !best[nr][nc].inQ || 
					floor[nr][nc]+50 > ceil[s.row][s.col] ||
					floor[nr][nc]+50 > ceil[nr][nc] ||
					floor[s.row][s.col]+50 > ceil[nr][nc])
					continue;
				int accessTime = Math.max(0, H - (ceil[nr][nc]-50));
				accessTime = Math.max(accessTime, s.time);
				int reachTime = accessTime + ((H - accessTime - 20) >= floor[s.row][s.col] ? 10 : 100);
				if (best[nr][nc].time > reachTime) {
					queue.remove(best[nr][nc]);
					best[nr][nc].time = reachTime;
					queue.add(best[nr][nc]);
				}
			}
		}
		return -1000;
		
		
	}
	static int H, n, m;
	static int[][] ceil, floor;
	static Square[][] best;
	static boolean[][] vis;
	static int[] dr = new int[] { 1, -1, 0, 0 };
	static int[] dc = new int[] { 0, 0, 1, -1 };
	
	static void recurse(int r, int c) {
		//A.spr("Reaching "+r+":" + c+" before tide out");
		vis[r][c] = true;
		for (int i=0;i<4;i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr<0 || nr>=m || nc<0 || nc>=n ||
				Math.max(floor[nr][nc],H)+50 > ceil[nr][nc] ||
				floor[nr][nc]+50 > ceil[r][c] ||
				floor[r][c]+50>ceil[nr][nc])
				continue;
			if (!vis[nr][nc]) {
				recurse(nr, nc);
			}
		}
	}
	
}
