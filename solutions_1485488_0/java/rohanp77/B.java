import java.io.*;
import java.util.*;

public class B {
	public static BufferedReader in;
	public static StringTokenizer st;
	
	public static int rows, cols;
	public static int[][] ceils;
	public static int[][] floors;
	public static int water;
	
	public static void main(String[] args) throws IOException{
		in = new BufferedReader(new FileReader("/home/useruser/datacollection/input/1485488_0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("B.out"));
		
		int test = readInt();
		for (int t=1; t<=test; t++){
			out.print("Case #"+t+": ");
			
			water = readInt();
			rows = readInt();
			cols = readInt();
			ceils = new int[rows][cols];
			floors = new int[rows][cols];
			
			for (int i=0; i<rows; i++)
				for (int j=0; j<cols; j++)
					ceils[i][j] = readInt();
			for (int i=0; i<rows; i++)
				for (int j=0; j<cols; j++)
					floors[i][j] = readInt();
			
			//trapped at (0,0)
			boolean[][] vis = new boolean[rows][cols];
			dfs(0,0,vis);
//			for (int i=0; i<rows; i++){
//				for (int j=0; j<cols; j++){
//					System.out.print((vis[i][j]?1:0)+" ");
//				}
//				System.out.println();
//			}
//			System.out.println();
			
			double min = -1;
			for(int i=0; i<rows; i++){
				for (int j=0; j<cols; j++){
					if (!vis[i][j]) continue;
					double ans = comp(i, j);
					//System.out.println();
					if (min==-1 || ans<min) min=ans;
				}
			}
			//System.out.println("---------------------------------");
			out.println(min);
		}
		
		out.close();
		in.close();
	}
	
	public static void dfs(int x, int y, boolean[][] vis){
		if (vis[x][y]) return;
		vis[x][y] = true;
		
		int limiting = max(floors[x][y], water);
		
		for (int dx=-1; dx<=1; dx++)
			for (int dy=-1; dy<=1; dy++){
				if (dx!=0 && dy!=0 || dx==0 && dy==0)
					continue;
				if (x+dx<0 || x+dx>=rows || y+dy<0 || y+dy>=cols) continue;
				int a = max(limiting, floors[x+dx][y+dy]);
				if (a+50>ceils[x+dx][y+dy]) continue;
				if (floors[x+dx][y+dy]+50 > ceils[x][y]) continue;
				dfs(x+dx, y+dy, vis);
			}
	}
	
	public static double comp(int x, int y){
		boolean[][] vis = new boolean[rows][cols];
		PriorityQueue<Loc> q = new PriorityQueue<Loc>();
		
		q.add(new Loc(x, y, 0));
		
		while(!q.isEmpty()){
			Loc curr = q.remove();
			if (vis[curr.x][curr.y]) continue;
			vis[curr.x][curr.y] = true;
			//System.out.println(curr.x+" "+curr.y);
			if (curr.x==rows-1 && curr.y==cols-1)
				return curr.dist;
			
			for (int dx=-1; dx<=1; dx++)
				for (int dy=-1; dy<=1; dy++){
					if (dx!=0 && dy!=0 || dx==0 && dy==0)
						continue;
					if (curr.x+dx<0 || curr.x+dx>=rows || curr.y+dy<0 || curr.y+dy>=cols) continue;
					
					int a = max(floors[curr.x][curr.y], floors[curr.x+dx][curr.y+dy]);
					if (a+50>ceils[curr.x+dx][curr.y+dy]) continue;
					if (floors[curr.x+dx][curr.y+dy]+50 > ceils[curr.x][curr.y]) continue;
					if (vis[curr.x+dx][curr.y+dy]) continue;
					
					double currW = water-10*curr.dist;
					if (currW<0) currW = 0;
					double reqW = ceils[curr.x+dx][curr.y+dy]-50;
					if (reqW<0) continue;
					double cost = curr.dist;
					double w = currW;
					if (reqW<currW){
						cost += (currW-reqW)/10;
						w = reqW;
					}
					
					cost++;
					if (w<floors[curr.x][curr.y]+20)
						cost+=9;
					
					q.add(new Loc(curr.x+dx, curr.y+dy, cost));
				}
		}
		
		return -1;
	}
	
	public static int max(int a, int b){
		return a>b?a:b;
	}
	
	public static String readLine() throws IOException{
		return in.readLine();
	}
	
	public static String readToken() throws IOException{
		if (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine());
		return st.nextToken();
	}
	
	public static int readInt() throws IOException{
		return Integer.parseInt(readToken());
	}
}

class Loc implements Comparable<Loc>{
	int x;
	int y;
	double dist;
	
	public Loc(int xa, int ya, double d){
		x = xa;
		y = ya;
		dist = d;
	}
	
	public int compareTo(Loc other){
		if (dist<other.dist) return -1;
		else if (dist>other.dist) return 1;
		return 0;
	}
}
