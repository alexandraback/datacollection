

import java.awt.Point;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;

public class C implements Runnable{
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok = new StringTokenizer("");
	
	void init() throws FileNotFoundException{
		in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		out = new PrintWriter("output.txt");
	}
	
	String readString() throws IOException{
		while(!tok.hasMoreTokens()){
			try{
				tok = new StringTokenizer(in.readLine());
			}catch (Exception e){
				return null;
			}
		}
		return tok.nextToken();
	}
	
	int readInt() throws IOException{
		return Integer.parseInt(readString());
	}
	
	long readLong() throws IOException{
		return Long.parseLong(readString());
	}
	
	double readDouble() throws IOException{
		return Double.parseDouble(readString());
	}
	
	public static void main(String[] args){
		new Thread(null, new C(), "", 256 * (1L << 20)).start();
	}
	
	long timeBegin, timeEnd;

	void time(){
		timeEnd = System.currentTimeMillis();
		System.err.println("Time = " + (timeEnd - timeBegin));
	}
	
	long memoryTotal, memoryFree;
	

	void memory(){
		memoryFree = Runtime.getRuntime().freeMemory();
		System.err.println("Memory = " + ((memoryTotal - memoryFree) >> 10) + " KB");
	}
	
	void debug(Object... objects){
		if (DEBUG){
			for (Object o: objects){
				System.err.println(o.toString());
			}
		}
	}
	
	public void run(){
		try{
			timeBegin = System.currentTimeMillis();
			memoryTotal = Runtime.getRuntime().freeMemory();
			init();
			solve();
			out.close();
			time();
			memory();
		}catch (Exception e){
			e.printStackTrace(System.err);
			System.exit(-1);
		}
	}
	
	boolean DEBUG = false;

	int n, m, h;
	int[][] f, c;
	
	double[][] t;
	
	void solve() throws IOException{
		int T = readInt();
		
		for (int test = 1; test <= T; test++){
			out.print("Case #" + test + ": ");
			
			h = readInt();
			n = readInt();
			m = readInt();
			
			f = new int[n][m];
			c = new int[n][m];
			
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					c[i][j] = readInt();
				}
			}
			
			for (int i = 0; i < n; i++){
				for (int j = 0; j < m; j++){
					f[i][j] = readInt();
				}
			}
			
			dijkstra();
			
			out.println(t[n-1][m-1]);
		}
	}
	
	class Vertex implements Comparable<Vertex>{
		
		Point p;
		double t;
		
		boolean down;
		public Vertex(int i, int j, double t, boolean down) {
			p = new Point(i, j);
			this.t = t;
			this.down = down;
		}
		@Override
		public int compareTo(Vertex v) {
			if (t < v.t) return -1;
			if (t > v.t) return 1;
			
			return 0;
		}
		
		
	}
	
	int[][] step = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
	boolean check(int x, int lim){
		return (0 <= x && x < lim);
	}
	
	void dijkstra(){
		t = new double[n][m];
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				t[i][j] = Double.MAX_VALUE;
			}
		}
		
		t[0][0] = 0;
		PriorityQueue<Vertex> q = new PriorityQueue<Vertex>();
		q.add(new Vertex(0, 0, 0, false));
		
		while (q.size() > 0){
			Vertex v = q.poll();
			
			if (v.t > t[v.p.x][v.p.y]) continue;
			
			int x = v.p.x;
			int y = v.p.y;
			
			for (int i = 0; i < 4; i++){
				int xx = x + step[i][0];
				int yy = y + step[i][1];
				
				if (!check(xx, n) || !check(yy, m)) continue;
				
				if (c[xx][yy] - f[xx][yy] < 50) continue;
				
				if (f[x][y] + 50 > c[xx][yy]) continue;
				if (f[xx][yy] + 50 > c[x][y]) continue;
				
				double time = v.t;

				double d = c[xx][yy] - (h - v.t * 10);
				boolean down = v.down;
				if (d < 50){
					time += (50 - d) / 10;
					down = true;
				}
				
				if (down){
					if ((h - time * 10) - f[x][y] < 20) time += 10;
					else time++;
				}
				
				if (t[xx][yy] > time){
					t[xx][yy] = time;
					q.add(new Vertex(xx, yy, time, down));
				}
			}
		}
	}
}

