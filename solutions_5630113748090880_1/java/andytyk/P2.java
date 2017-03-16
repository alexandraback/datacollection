import java.io.*;
import java.util.*;

public class P2 {
	
	static int N;
	static ArrayList<Line> lines;
	static int [][] grid;
	static boolean found;
	static int Rskip,Cskip;
	
	public static void solve(int R, int C, int skipped) {
		if(R == N && C == N) {
			found = true;
			return;
		} else {
			Line cl = lines.get(R+C+skipped);
			boolean ok = true;
			boolean [] empty = new boolean[N];
			for(int i = 0; i < N; i++)
				if(!(grid[R][i] == -1 || grid[R][i] == cl.vals[i]))
					ok = false;
			if(ok) {
				for(int i = 0; i < N; i++) {
					empty[i] = (grid[R][i] == -1);
					grid[R][i] = cl.vals[i];
				}
				solve(R+1,C,skipped);
				if(found)
					return;
				for(int i = 0; i < N; i++)
					if(empty[i])
						grid[R][i] = -1;
			}
			ok = true;
			for(int i = 0; i < N; i++)
				if(!(grid[i][C] == -1 || grid[i][C] == cl.vals[i]))
					ok = false;
			if(ok) {
				for(int i = 0; i < N; i++) {
					empty[i] = (grid[i][C] == -1);
					grid[i][C] = cl.vals[i];
				}
				solve(R,C+1,skipped);
				if(found)
					return;
				for(int i = 0; i < N; i++)
					if(empty[i])
						grid[i][C] = -1;
			}
			if(skipped == 0) {
				Rskip = R;
				solve(R+1,C,1);
				if(found)
					return;
				Rskip = -1;
				Cskip = C;
				solve(R,C+1,1);
				if(found)
					return;
				Cskip = -1;
			}
		}
	}
	
	public static void main(String [] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("/Users/andykong/Downloads/gcj2016/R1A/p2.large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("/Users/andykong/Downloads/gcj2016/R1A/p2.large.out"));
		int T = Integer.parseInt(in.readLine());
		for(int cc = 1; cc <= T; cc++) {
			N = Integer.parseInt(in.readLine());
			int [] vals = new int[2501];
			ArrayList<Integer> v = new ArrayList<Integer>();
			for(int i = 0; i < 2*N-1; i++) {
				String [] sp = in.readLine().split(" ");
				for(int j= 0; j <N; j++)
					vals[Integer.parseInt(sp[j])]++;
			}
			for(int i = 0; i < vals.length; i++)
				if(vals[i] % 2 == 1)
					v.add(i);
			
			
//			lines = new ArrayList<Line>();
//			grid = new int[N][N];
//			for(int i = 0; i < N; i++)
//				for(int j = 0; j < N; j++)
//					grid[i][j] = -1;
//			for(int i = 0; i < 2*N -1; i++) {
//				Line l = new Line();
//				l.vals = new int[N];
//				String [] sp = in.readLine().split(" ");
//				for(int j = 0; j < N; j++)
//					l.vals[j] = Integer.parseInt(sp[j]);
//				lines.add(l);
//			}
//			Collections.sort(lines);
//			Rskip = Cskip = -1;
//			found = false;
//			solve(0,0,0);
			out.printf("Case #%d:",cc);
			for(int i = 0; i < v.size(); i++)
				out.printf(" %d",v.get(i));
			out.println();
		}
		in.close();
		out.close();
	}
}

class Line implements Comparable<Line>{
	int [] vals;

	public int compareTo(Line o) {
		for(int i = 0; i < vals.length; i++) {
			if(vals[i] < o.vals[i])
				return -1;
			else if(vals[i] > o.vals[i])
				return 1;
		}
		return 0;
	}
}