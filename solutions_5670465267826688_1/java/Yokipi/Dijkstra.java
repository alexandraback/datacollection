package codejam2015;

import java.io.*;
import java.util.*;
import static java.lang.Math.*;


public class Dijkstra {
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st = null;
	
	static Long nextLong() throws Exception {
		if (st == null || !st.hasMoreElements()) {
			String s = in.readLine();
			if (s == null) return null;
			st = new StringTokenizer(s);
		}
		return Long.parseLong(st.nextToken());
	}
	
	static String next() throws Exception {
		if (st == null || !st.hasMoreElements()) {
			String s = in.readLine();
			if (s == null) return null;
			st = new StringTokenizer(s);
		}
		return st.nextToken();
	}
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader(new File("src/codejam2015/c.in")));
		out = new PrintWriter(new FileWriter(new File("src/codejam2015/c.out")));
		
		//System.out.println(Arrays.deepToString(neededleft));
		//System.out.println(Arrays.deepToString(neededright));
		
		long T = nextLong();
		for (int t = 0; t < T; t++) {
			
			int L = (int) (long) nextLong();
			long X = nextLong();
			char[] c = next().toCharArray();
			int[] ch = new int[L];
			for (int i = 0; i < L; i++) {
				ch[i] = c[i] - 'g';
			}
			
			int left[] = new int[L];
			int right[] = new int[L+1];
			left[0] = ch[0];
			right[L] = 1;
			right[L-1] = ch[L-1];
			for (int i = 1; i < L; i++) {
				left[i] = mult(left[i-1], ch[i]);
				right[L-1-i] = mult(ch[L-1-i], right[L-i]);
			}
			
			int order;
			if (right[0] == 1) order = 1;
			else if (right[0] == -1) order = 2;
			else order = 4;
			
			int modded = (int) (X % order);
			
			int dups[] = new int[9];
			Arrays.fill(dups, -1);
			int current = 1;
			for (int i = 0; i < order; i++) {
				dups[current+4] = i;
				current = mult(current, right[0]);
			}
			
			//System.out.println(Arrays.toString(dups));
			
			boolean possible = false;
			for (int i = 0; i < L; i++) {
				int dupsleft = dups[4+neededleft[6][left[i]+4]];
				if (dupsleft == -1 || dupsleft > X-1) continue;
				
				// Same dup case
				int curr = 1;
				for (int j = i+1; j < L; j++) {
					curr = mult(curr, ch[j]);
					if (curr == 3) {
						int dupsright = dups[4+neededright[8][right[j+1]+4]];
						if (dupsright != -1 && (dupsright + dupsleft) <= X-1 && (1+dupsright + dupsleft)%order == modded) {
							possible = true;
							break;
						}
					}
				}
				
				// Different dup case
				if (X < 2) break;
				for (int j = 0; j < L; j++) {
					int dupsright = dups[4+neededright[8][right[j+1]+4]];
					if (dupsright == -1 || (dupsright + dupsleft) > X-2) continue;
					int dupsmid = dups[4+neededleft[neededright[7][right[i+1]+4]+4][left[j]+4]];
					if (dupsmid != -1 && (dupsright + dupsleft + dupsmid) <= X-2 && (2+dupsright + dupsleft + dupsmid)%order == modded) {
						possible = true;
						break;
					}
				}
				
				if (possible) break;
			}
			
			out.printf("Case #%d: %s\n", t+1, possible ? "YES" : "NO");
		}
		
		in.close();
		out.close();
	}
	
	static int[][] quat =  {{1, 2, 3, 4},
							{2, -1, 4, -3},
							{3, -4, -1, 2},
							{4, 3, -2, -1}};
	
	static int[][] neededleft = new int[9][9];
	static int[][] neededright = new int[9][9];
	static {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				int x = i-4, y = j-4;
				if (x != 0 && y != 0) {
					int k = mult(x, y)+4;
					neededleft[k][j] = x;
					neededright[k][i] = y;
				}
			}
		}
	}
	
	static int mult(int a, int b) {
		int x = abs(a), y = abs(b);
		int s = (a*b) > 0 ? 1 : -1;
		return s*quat[x-1][y-1];
	}
}
