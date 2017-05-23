

import java.awt.Point;
import java.io.BufferedReader;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class R1B_Tide {

	static boolean test = true;

	private void solve() throws Throwable {
		int t = iread();
		for (int i = 0; i < t; i++) {
			solveIt(i+1);
		}
	}
	
	private void solveIt(int casenr) throws Throwable {
		int h = iread(), n = iread(), m = iread();
		
		double[][] ceil = new double[n][m];
		double[][] floor = new double[n][m];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ceil[i][j] = iread();
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				floor[i][j] = iread();
			}
		}
		
		//memstate
		double[][][] timeBest = new double[h+10551][n][m];
		for (int i = 0; i < timeBest.length; i++) {
			for (int j = 0; j < timeBest[i].length; j++) {
				Arrays.fill(timeBest[i][j], Integer.MAX_VALUE);
			}
		}
		
		int[][] dir = new int[][]{{1,0},{0,1},{-1,0},{0,-1}};
		
		//dfs
		Stack<Point> stack = new Stack<Point>();
		stack.push(new Point(0,0));
		boolean[][] visited = new boolean[n][m];
		visited[0][0] = true;
		
		while (stack.size() > 0) {
			Point pop = stack.pop();
			for (int d = 0; d < 4; d++) {
				int x = pop.x;
				int y = pop.y;
				
				int newx = x + dir[d][1];
				int newy = y + dir[d][0];
				
				if(newx >= 0 && newx < m && newy >= 0 && newy < n){
					int waterlevel = Math.max(0, h);
					
					double moveheight = ceil[newy][newx] - Math.max(floor[y][x], waterlevel);
					double backheight = ceil[y][x] - floor[newy][newx];
					double nextHeight = ceil[newy][newx] - Math.max(floor[newy][newx], waterlevel);
					
					if(moveheight >= 50 && backheight >= 50 && nextHeight >= 50 && !visited[newy][newx]){
						stack.push(new Point(newx, newy));
						visited[newy][newx] = true;
					}
				}						
			}
		}
		
		for (int i = 0; i < timeBest.length; i++) {
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < m; x++) {
					if(visited[y][x]){
						timeBest[i][y][x] = i;
					}
				}
			}
		}
		
		// over all states
		for (int i = 0; i < h + 10001; i++) { // tick time
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < m; x++) {
					for (int d = 0; d < 4; d++) {
						
						double myBest = timeBest[i][y][x];
						if(myBest == Integer.MAX_VALUE){
							continue;
						}
						
						int newx = x + dir[d][1];
						int newy = y + dir[d][0];

						if(newx >= 0 && newx < m && newy >= 0 && newy < n){
							int waterlevel = Math.max(0, h - i);
							double waterCurrent = waterlevel - floor[y][x];
							boolean fast = waterCurrent >= 20;
							
							double moveheight = ceil[newy][newx] - Math.max(floor[y][x], waterlevel);
							double backheight = ceil[y][x] - floor[newy][newx];
							double nextHeight = ceil[newy][newx] - Math.max(floor[newy][newx], waterlevel);
														
							if(moveheight >= 50 && backheight >= 50 && nextHeight >= 50){
								int moveTime = 10;
								if(!fast){
									moveTime = 100;
								}
								
								
								double newCandidate =  myBest + moveTime;
								double oldCandidate = timeBest[i + moveTime][newy][newx];
								
								timeBest[i + moveTime][newy][newx] = Math.min(oldCandidate,newCandidate);
							}
						}						
					}
				}
			}
		}
		
		double ans = Integer.MAX_VALUE;
		for (int i = 0; i < timeBest.length; i++) {
			if(timeBest[i][n-1][m-1] != Integer.MAX_VALUE){
				ans = i;
				break;
			}
		}
		
		String answerString = "Case #" + casenr + ": " + ans/10;
		out.write(answerString + "\n");
		System.out.println(answerString);
	}

	public int iread() throws Exception {
		return Integer.parseInt(wread());
	}

	public double dread() throws Exception {
		return Double.parseDouble(wread());
	}

	public long lread() throws Exception {
		return Long.parseLong(wread());
	}

	public String wread() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) throws Throwable {
		new R1B_Tide().solve();
		out.close();
	}

	public R1B_Tide() throws Throwable {
		if (test) {
			in = new BufferedReader(new FileReader("/home/useruser/datacollection/input/1485488_0.in")));
			out = new BufferedWriter(new FileWriter(getClass().getCanonicalName() + "-out.txt"));
		} else {
			new BufferedReader(inp);
		}
	}

	static InputStreamReader inp = new InputStreamReader(System.in);
	static BufferedReader in = new BufferedReader(inp);
	static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

//	static String "/home/useruser/datacollection/input/1485488_0.in" = "testdata.txt";
	static String "/home/useruser/datacollection/input/1485488_0.in" = "B-small-attempt2.in";
}