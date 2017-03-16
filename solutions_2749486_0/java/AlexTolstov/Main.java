import java.io.*;
import java.util.*;


public class Main extends Thread {
	
	Scanner in;
	PrintWriter out;
	
	static final String path = "C:/gcj2013_r1/";
	static final String problem = "B-small";
	
	boolean used[][];
	
	void solveOne(int test) {
		int x = in.nextInt();
		int y = in.nextInt();
		StringBuilder sb = new StringBuilder();
		String ans = "";
		
		int currX = 0;
		int currY = 0;
		
		int step = 1;
		if (x > 0) {
			while (currX != x) {
				currX += step;
				step++;
				sb.append('E');
				if (currX == x) {
					break;
				}
				currX -= step;
				step++;
				sb.append('W');
				if (currX == x) {
					break;
				}
			}
		} else {
			while (currX != x) {
				currX -= step;
				step++;
				sb.append('W');
				if (currX == x) {
					break;
				}
				currX += step;
				step++;
				sb.append('E');
				if (currX == x) {
					break;
				}
			}
		}
		
		if (y < 0) {
			while (currY != y) {
				currY += step;
				step++;
				sb.append('N');
				if (currY == y) {
					break;
				}
				currY -= step;
				step++;
				sb.append('S');
				if (currY == y) {
					break;
				}
			}
		} else {
			while (currY != y) {
				currY -= step;
				step++;
				sb.append('S');
				if (currY == y) {
					break;
				}
				currY += step;
				step++;
				sb.append('N');
				if (currY == y) {
					break;
				}
			}
		}
		
		
		ans = sb.toString();
		check(ans.length() < 500);
		
		
		out.println("Case #" + test + ": " + ans);
	}
	
	void solve() {
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			solveOne(i + 1);
		}
	}
	
	
	static void check(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(new FileWriter(path + problem + ".out"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new Thread(null, new Main(), "GAVNO", 500000000).start();
	}
}