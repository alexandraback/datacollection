import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

import static java.lang.Math.*;

public class ProblemB {
	String PROBLEM_ID = "problemB";

	enum TestType {
		EXAMPLE, SMALL, LARGE
	}

//	 TestType TYPE = TestType.EXAMPLE;
	 TestType TYPE = TestType.SMALL;
//	TestType TYPE = TestType.LARGE;

	public String getFileName() {
		String result = PROBLEM_ID + "_";
		switch (TYPE) {
		case EXAMPLE:
			result += "example";
			break;
		case SMALL:
			result += "small";
			break;
		case LARGE:
			result += "large";
			break;
		}
		return result;
	}

	public String getInFileName() {
		return getFileName() + ".in";
	}

	public String getOutFileName() {
		return getFileName() + ".out";
	}

	public static void main(String[] args) throws Exception {
		new ProblemB();
	}

	public ProblemB() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int height = scan.nextInt();
			N = scan.nextInt();
			M = scan.nextInt();
			ceiling = new int[N][M];
			for ( int i = 0; i < N; i++) {
				for ( int j = 0; j < M; j++) ceiling[i][j] = scan.nextInt();
			}
			floor = new int[N][M];
			for ( int i = 0; i < N; i++) {
				for ( int j = 0; j < M; j++) floor[i][j] = scan.nextInt();
			}
			int[][] firstEnter = new int[N][M];
			for ( int [] a: firstEnter) Arrays.fill(a, Integer.MAX_VALUE);
			firstEnter[0][0] = 0;
			initialMove(firstEnter, height);
			PriorityQueue<Location> list = new PriorityQueue<Location>();
			for ( int r = 0; r < N; r++) 
				for ( int c = 0; c < M; c++) {
					if ( firstEnter[r][c] == 0 ) {
						list.add(new Location(0, r, c));
					}
				}
			while ( list.size() > 0 ) {
				Location loc = list.poll();
				int r = loc.row;
				int c = loc.col;
				int h = height - loc.time;
				if ( loc.time > firstEnter[r][c]) continue;
				for ( int i = 0; i < 4; i++) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					if ( nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
					// current floor <= adj ceiling - 50
					if ( floor[r][c] > ceiling[nr][nc] - 50) continue;
					// adj floor <= adj ceiling - 50
					if ( floor[nr][nc] > ceiling[nr][nc] - 50) continue;
					// current ceil >= adj floor + 50
					if ( ceiling[r][c] < floor[nr][nc] + 50) continue;
					// water level <= adj ceiling - 50
					int maxH = ceiling[nr][nc] - 50;
					int startH = min(maxH, h	);
					int wait = h - startH;
					int moveTime = startH - floor[r][c] >= 20 ? 10 : 100;
					int nTime = loc.time + wait + moveTime;
					if ( nTime < firstEnter[nr][nc]) {
						firstEnter[nr][nc] = nTime;
						list.add(new Location(nTime, nr, nc));
					}
				}
			}
			
			double a = firstEnter[N-1][M-1]/10.0;
			
			
			String resultStr = String.format("Case #%d: %.1f", test + 1, a);
			// add answer here

			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
	
	int N;
	int M;
	int[][] ceiling;
	int[][] floor;
	int[] dr = new int[] { 1, -1, 0, 0 };
	int[] dc = new int[] { 0, 0, 1, -1 };
	
	int moveCost(int cRow, int cCol, int nRow, int nCol, int h) {
		// water level <= adj ceiling - 50
		if ( h > ceiling[nRow][nCol] - 50) return -1;
		// current floor <= adj ceiling - 50
		if ( floor[cRow][cCol] > ceiling[nRow][nCol] - 50) return -1;
		// adj floor <= adj ceiling - 50
		if ( floor[nRow][nCol] > ceiling[nRow][nCol] - 50 ) return -1;
		// current ceil >= adj floor + 50
		if ( ceiling[cRow][cCol] < floor[nRow][nCol] + 50 ) return -1;
		return h - floor[cRow][cCol] >= 20 ? 1 : 10;
	}
	
	
	void initialMove(int[][] cave, int h) {
		boolean[][] done = new boolean[N][M];
		LinkedList<Integer> list = new LinkedList<Integer>();
		list.add(0);
		done[0][0] = true;
		while ( list.size() > 0 ) {
			int z = list.poll();
			int r = z / 1000;
			int c = z % 1000;
			for ( int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if ( nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
				if ( done[nr][nc]) continue;
				if ( moveCost(r, c, nr, nc, h) > 0 ) {
					cave[nr][nc] = 0;
					done[nr][nc] = true;
					list.add(1000*nr + nc);
				}
			}
		}
	}
	
	public class Location implements Comparable<Location> {
		int time;
		int row;
		int col;

		public Location(int time, int row, int col ) {
			this.time = time;
			this.row = row;
			this.col = col;
		}

		public int compareTo( Location other ) {
			if (time != other.time ) 
				return ( time < other.time ? -1 : 1 );
			return 0;
		}
	}

	
}
