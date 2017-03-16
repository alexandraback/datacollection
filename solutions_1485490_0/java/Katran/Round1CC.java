import java.io.*;
import java.math.*;
import java.util.*;

public class Round1CC implements Runnable {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	boolean file = true;
	String fileName = "C-small";

	public static void main(String[] args) throws Exception {
		new Round1CC().run();
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
		
		int cases = nextInt();
		for(int step = 1; step <= cases; step++){
			int n = nextInt(), m = nextInt();
			long ans = 0;
			long [][]a = new long[n][2], b = new long[m][2];
			for(int i=0; i<n; i++){
				a[i][0] = nextLong(); a[i][1] = nextLong();
			}
			for(int i=0; i<m; i++){
				b[i][0] = nextLong(); b[i][1] = nextLong();
			}
			
			for(int i=0; i<n; i++){//	checked by one
				long curSum = 0, curRem = a[i][0];
				for(int j=0; j<m; j++){
					if (a[i][1] == b[j][1]){
						curSum += Math.min(curRem, b[j][0]);
						curRem -= b[j][0];
						if (curRem < 0) curRem = 0;
					}
				}
				ans = Math.max(ans, curSum);
			}
			if (n == 3) {
				long xRem = a[0][0], xSum = 0;
				for(int x = 0; x<m; x++){	//	checked all three
					long cellXRem = b[x][0];
					if (b[x][1] == a[0][1]) {
						xSum += Math.min(xRem, b[x][0]);
						if (cellXRem >= xRem) { cellXRem -= xRem; } else cellXRem = 0;
						xRem -= b[x][0];
						if (xRem < 0) xRem = 0;
					}
					long yRem = a[1][0], ySum = 0;
					if (cellXRem > 0 && b[x][1] == a[1][1]) {
						ySum += Math.min(cellXRem, yRem);
						yRem -= cellXRem;
						if (yRem < 0) yRem = 0;
					}
					for(int y = x+1; y<m; y++) {
						long cellYRem = b[y][0];
						if (b[y][1] == a[1][1]) {
							ySum += Math.min(yRem, b[y][0]);
							if (cellYRem >= yRem) { cellYRem -= yRem; } else cellYRem = 0;
							yRem -= b[y][0];
							if (yRem < 0) yRem = 0;
						}
						long zSum = 0, zRem = a[2][0];
						if (cellYRem > 0 && b[y][1] == a[2][1]) {
							zSum += Math.min(cellYRem, zRem);
							zRem -= cellYRem;
							if (zRem < 0) zRem = 0;
						}
						for(int z = y+1; z<m; z++){
							if (b[z][1] == a[2][1]) {
								zSum += Math.min(zRem, b[z][0]);
								zRem -= b[z][0];
								if (zRem < 0)zRem = 0;
								long summ = xSum + ySum + zSum;
								ans = Math.max(ans, summ);
							}
						}
					}
				}
			}
			if (n >= 2){
				long xRem = a[0][0], xSum = 0;
				for(int x=0; x<m; x++){//	x + y
					long cellXRem = b[x][0];
					if (b[x][1] == a[0][1]) {
						xSum += Math.min(xRem, b[x][0]);
						if (cellXRem >= xRem) { cellXRem -= xRem; } else cellXRem = 0;
						xRem -= b[x][0];
						if (xRem < 0) xRem = 0;
					}
					long yRem = a[1][0], ySum = 0;
					if (cellXRem > 0 && b[x][1] == a[1][1]) {
						ySum += Math.min(cellXRem, yRem);
						yRem -= cellXRem;
						if (yRem < 0) yRem = 0;
					}
					for(int y = x+1; y<m; y++){
						if (b[y][1] == a[1][1]) {
							ySum += Math.min(yRem, b[y][0]);
							yRem -= b[y][0];
							if (yRem < 0) yRem = 0;
							long summ = xSum + ySum;
							ans = Math.max(ans, summ);
						}
					}
				}
			}
			if (n == 3){
				long xRem = a[0][0], xSum = 0;
				for(int x=0; x<m; x++){//	x + z
					long cellXRem = b[x][0];
					if (b[x][1] == a[0][1]) {
						xSum += Math.min(xRem, b[x][0]);
						if (cellXRem >= xRem) { cellXRem -= xRem; } else cellXRem = 0;
						xRem -= b[x][0];
						if (xRem < 0) xRem = 0;
					}
					long zSum = 0, zRem = a[2][0];
					if (cellXRem > 0 && b[x][1] == a[2][1]) {
						zSum += Math.min(cellXRem, zRem);
						zRem -= cellXRem;
						if (zRem < 0) zRem = 0;
					}
					for(int z = x+1; z<m;z++){
						if (b[z][1] == a[2][1]) {
							zSum += Math.min(zRem, b[z][0]);
							zRem -= b[z][0];
							if (zRem < 0)zRem = 0;
							long summ = xSum + zSum;
							ans = Math.max(ans, summ);
						}
					}
				}
			}
			if (n == 3){
				long yRem = a[1][0], ySum = 0;
				for(int y = 0; y<m; y++){//	y + z
					long cellYRem = b[y][0];
					if (b[y][1] == a[1][1]) {
						ySum += Math.min(yRem, b[y][0]);
						if (cellYRem >= yRem) { cellYRem -= yRem; } else cellYRem = 0;
						yRem -= b[y][0];
						if (yRem < 0) yRem = 0;
					}
					long zSum = 0, zRem = a[2][0];
					if (cellYRem > 0 && b[y][1] == a[2][1]) {
						zSum += Math.min(cellYRem, zRem);
						zRem -= cellYRem;
						if (zRem < 0) zRem = 0;
					}
					for(int z = y+1; z<m;z++) {
						if (b[z][1] == a[2][1]) {
							zSum += Math.min(zRem, b[z][0]);
							zRem -= b[z][0];
							if (zRem < 0)zRem = 0;
							long summ = ySum + zSum;
							ans = Math.max(ans, summ);
						}
					}
				}
			}
			out.println("Case #"+step+": "+ans);
		}
	}
	
}