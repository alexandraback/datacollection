import java.util.*;
import java.io.*;

public class Tide {
	static int[][] C;
	static int[][] F;
	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};
	static int N,M,H;
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(new File("bdata.in"));
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int h = reader.nextInt(); H = h;
			int n = reader.nextInt(); N = n;
			int m = reader.nextInt(); M = m;
			
			C = new int[n][m];
			F = new int[n][m];
			
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					C[i][j] = reader.nextInt();
			
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					F[i][j] = reader.nextInt();
			
			double min = bfs(getStart());
			System.out.printf("Case #%d: %.7f\n", t, min);
		}
	}
	
	public static LinkedList<State> getStart(){
		LinkedList<State> q = new LinkedList<State>();
		LinkedList<State> sol = new LinkedList<State>();
		boolean[][] visited = new boolean[N][M];
		
		q.add(new State(0,0,0));
		visited[0][0] = true;
		
		while(!q.isEmpty()){
			State cur = q.remove();
			sol.add(cur);
			int x = cur.x;
			int y = cur.y;
			
			for(int i = 0; i < 4; i++){
				double add = move(x,y,i,0);
				if(add < 0 || add > 0)
					continue;
				
				if(!visited[x+dx[i]][y+dy[i]]){
					q.add(new State(x+dx[i], y+dy[i], 0));
					visited[x+dx[i]][y+dy[i]] = true;
				}
			}
		}
		
		return sol;
	}
	
	public static double bfs(LinkedList<State> start){
//		System.out.println(start);
		PriorityQueue<State> q = new PriorityQueue<State>();
		boolean[][] visited = new boolean[N][M];
		double search = -1;
		
		q.addAll(start);
		while(!q.isEmpty()){
			State cur = q.remove();
			int x = cur.x;
			int y = cur.y;
			double t = cur.t;
			if(visited[x][y])
				continue;
			visited[x][y] = true;
			
			if(x == N-1 && y == M-1){
				search = t;
				break;
			}
			
			for(int i = 0; i < 4; i++){
				//Try to move into d[i]
				double add = move(x,y,i,t);
				if(add < 0)
					continue;
				double curHeight = Math.max(0, Math.max(H - 10*(t+add), 0)-F[x][y]);
				if(curHeight < 20){
					q.add(new State(x+dx[i], y+dy[i], t+add+10));
				}else{
					q.add(new State(x+dx[i], y+dy[i], t+add+1));
				}
			}
		}
		
		return search;
	}
	
	/*
	The water level, the floor height of your current square, and the floor height of the 
	adjacent square must all be at least 50 centimeters lower than the ceiling height of 
	the adjacent square. Note: this means that you will never be able to enter a square with 
	less than 50 centimeters between the floor and the ceiling.
	
    The floor height of the adjacent square must be at least 50 centimeters below the ceiling 
    height of your current square as well.
    
    You can never move off the edge of the map. 
	 */
	
	public static double move(int x, int y, int d, double t){
		int nx = x+dx[d];
		int ny = y+dy[d];
		if(nx < 0 || nx >= N || ny < 0 || ny >= M || C[nx][ny] - F[nx][ny] < 50 || C[x][y] - F[nx][ny] < 50 || C[nx][ny] - F[x][y] < 50)
			return -1;
		
		double height = Math.max(H - 10*t, 0);
		double curHeight = Math.max(height, F[x][y]);
		double targetHeight = C[nx][ny] - 50;
		double time = (curHeight - targetHeight)/10.;
		
		return Math.max(time, 0);
	}
	
	public static class State implements Comparable<State>{
		int x,y;
		double t;
		public State(int _x, int _y, double _t){
			x = _x;
			y = _y;
			t = _t;
		}
		public int compareTo(State s){
			return (int)Math.signum(t-s.t);
		}
		public String toString(){
			return "("+x+", "+y+": "+t+")";
		}
	}
}