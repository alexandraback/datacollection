import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
			pw.printf("Case #%d:\n", casenum);
			int r = readInt();
			int c = readInt();
			int m = readInt();
			if(r*c-1 == m) {
				for(int i = 0; i < r; i++) {
					for(int j = 0; j < c; j++) {
						if(i == 0 && j == 0) {
							pw.print('c');
						}
						else {
							pw.print('*');
						}
					}
					pw.println();
				}
			}
			else if(r == 1) {
				int numDot = r*c-1-m;
				for(int i = 0; i < c; i++) {
					if(i == 0) {
						pw.print('c');
					}
					else if(numDot-- > 0) {
						pw.print('.');
					}
					else {
						pw.print('*');
					}
				}
				pw.println();
			}
			else if(c == 1) {
				int numDot = r*c-1-m;
				for(int i = 0; i < r; i++) {
					if(i == 0) {
						pw.println('c');
					}
					else if(numDot-- > 0) {
						pw.println('.');
					}
					else {
						pw.println('*');
					}
				}
			}
			else {
				int numWantEmpty = r*c-m;
				boolean[][][] possible = new boolean[r][c+1][numWantEmpty+1];
				State[][][] parent = new State[r][c+1][numWantEmpty+1];
				for(int j = 1; j <= c; j++) {
					int num = 2 * Math.min(c, j+1);
					if(num <= numWantEmpty) {
						possible[0][j][num] = true;
					}
				}
				int retR = -1;
				int retC = -1;
				int retNumWantEmpty = -1;
				outer: for(int i = 0; i < r-1; i++) {
					for(int j = 1; j <= c; j++) {
						for(int k = 0; k <= numWantEmpty; k++) {
							if(!possible[i][j][k]) {
								continue;
							}
							if(k == numWantEmpty) {
								retR = i;
								retC = j;
								retNumWantEmpty = k;
								break outer;
							}
							for(int l = 1; l <= j; l++) {
								int numAdd = Math.min(c, l+1);
								if(k + numAdd <= numWantEmpty && parent[i+1][l][k+numAdd] == null) {
									possible[i+1][l][k+numAdd] = true;
									parent[i+1][l][k+numAdd] = new State(i,j,k);
								}
							}
						}
					}
				}
				if(retNumWantEmpty == -1) {
					pw.println("Impossible");
				}
				else {
					int[] numEmpty = new int[r];
					while(retR >= 0) {
						numEmpty[retR+1] = retC+1;
						if(retR == 0) {
							numEmpty[0] = retC+1;
							break;
						}
						State next = parent[retR][retC][retNumWantEmpty];
						retR = next.x;
						retC = next.y;
						retNumWantEmpty = next.z;
					}
					for(int i = 0; i < r; i++) {
						for(int j = 0; j < c; j++) {
							if(i==0 && j==0) {
								pw.print('c');
							}
							else if(j < numEmpty[i]) {
								pw.print('.');
							}
							else {
								pw.print('*');
							}
						}
						pw.println();
					}
				}
			}
		}
		pw.close();
	}

	static class State {
		public int x,y,z;

		public State(int x, int y, int z) {
			super();
			this.x = x;
			this.y = y;
			this.z = z;
		}
		
	}
	
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}

	public static String readLine() throws IOException	{
		st = null;
		return br.readLine();
	}

}
