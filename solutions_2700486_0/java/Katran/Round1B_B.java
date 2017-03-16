import java.io.*;
import java.math.*;
import java.util.*;

public class Round1B_B implements Runnable {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	boolean file = true;
	String fileName = "B-small";

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new Round1B_B().run();
	}

	private String next() throws Exception {
		if (st == null || !st.hasMoreElements())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	private int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	private long nextLong() throws Exception {
		return Long.parseLong(next());
	}

	private double nextDouble() throws Exception {
		return Double.parseDouble(next());
	}

	public void run() {
		try {
			if (file)
				in = new BufferedReader(new FileReader(fileName+".in"));
			else
				in = new BufferedReader(new InputStreamReader(System.in));
			if (file)
				out = new PrintWriter(new FileWriter(fileName+".out"));
			else
				out = new PrintWriter(System.out);
			solve();
		} catch (Exception ex) {
			throw new RuntimeException(ex);
		} finally {
			out.close();
		}
	}

	public void solve() throws Exception {
		long oo = 100000000000L;
		int cases = Integer.parseInt(in.readLine());
		for(int step = 1; step <= cases; step++){
			int n = nextInt(), x = nextInt(), y = nextInt(), total = (1<<n), hit = 0;
			
			System.out.println("----------------------------------");
			if (y>99)y = 99;
			if (x<-50)x = 0;
			if (x>49)x = 49;
			for(int mask = 0; mask < (1<<n); mask++){
				used = new boolean[100][100];
//				System.out.println("n = "+n+" mask = "+Integer.toBinaryString(mask)+" -----------------");
				for(int i=0; i<n; i++){
					int curY = 30, curX = used[0].length/2;
					while(curY > 0){
						if (!can(curX, curY-2)){
							if (curY == 1 && (curX+curY)%2 != 0){
								curY--;
							}
							boolean canLeft = can(curX-1, curY-1);
							boolean canRight = can(curX+1, curY-1);
							if (canLeft && canRight){
								int dir = (1<<i)&mask;
								if (dir == 0){
									curX--;
								} else{
									curX++;
								}
								curY--;
							} else if (canLeft && !canRight){
								curX--; curY--;
							} else if (!canLeft && canRight){
								curX++; curY--;
							} else if (!canLeft && !canRight){
									break;
								}
						} else {
							curY--;
						}
						
					}
					used[curX][curY] = true;
//					System.out.println("i = "+i+" fell to \tX = "+(curX-50)+"\t+Y = "+curY);
					
				}
				if (used[x+50][y]) hit++;
				
				
			}
			System.out.println("hits = "+hit);
			printAns(step, (1.*hit/total));
		}
	}
	boolean used[][];
	
	boolean can(int x, int y){
		return in(x, y) && !used[x][y];
	}
	boolean in(int x, int y){
		return y >= 0 && x >= 0 && y < used.length && x < used[0].length;
	}
	
	void printAns(int step, double ans){
		out.println("Case #"+step+": "+ans);
//		out.printf("%.6f\n", ans);
	}
	
	public void printArr(int []a, int limit){
		for(int i=0; i<Math.min(a.length, limit); i++)
			System.out.print(a[i]+", ");
		System.out.println();
	}
	
}