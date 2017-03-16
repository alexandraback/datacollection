package con2013Q;

import java.io.*;
import java.util.*;

public class B {
	
	private static final String islarge = "-large";
	private static final String fileName = "results/con2013Q/"+B.class.getSimpleName().toLowerCase()+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	private static final String YES ="YES",	NO="NO";
	
	private void solve() {
		int N = in.nextInt(),
			M = in.nextInt();
		int[][]grid = new int[N][M];
		int[]maxRow = new int[N],
			maxCol = new int[M];
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				grid[i][j]=in.nextInt();
				if(grid[i][j]>maxRow[i])
					maxRow[i]=grid[i][j];
				if(grid[i][j]>maxCol[j])
					maxCol[j]=grid[i][j];
			}
		}
		boolean possible = true;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(maxRow[i]!=grid[i][j] && maxCol[j]!=grid[i][j]){
					possible=false;
					break;
				}
			}
		}
		out.println(possible?YES:NO);
	}

	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new B().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
