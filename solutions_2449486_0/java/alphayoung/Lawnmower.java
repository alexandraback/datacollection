package codejam13;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class Lawnmower {
	
	public void solve(String input, String output) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader(input));
		BufferedWriter out = new BufferedWriter(new FileWriter(output));
		String line = in.readLine();
		int T = Integer.parseInt(line);
		int index = 1;
		
		while (T > 0) {
			String[] dims = in.readLine().split(" ");
			int N = Integer.parseInt(dims[0]);
			int M = Integer.parseInt(dims[1]);
			int[][] lawn = new int[N][M];
			
			for (int i = 0; i < N; ++i) {
				String[] heights = in.readLine().split(" ");
				for (int j = 0; j < M; ++j) {
					lawn[i][j] = Integer.parseInt(heights[j]);
				}
			}
			
			boolean isPossible = isPossible(lawn, N, M);
			
			out.write("Case #" + index + ": ");
			out.write(isPossible ? "YES" : "NO");
			out.newLine();
			
			--T;
			++index;
		}
		
		in.close();
		out.close();
	}
	
	public boolean isPossible(int[][] lawn, int N, int M) {
		if (N == 1 || M == 1) {
			return true;
		}
		int[] rowMax = new int[N];
		int[] colMax = new int[M];
		
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (lawn[i][j] > rowMax[i]) {
					rowMax[i] = lawn[i][j];
				}
				if (lawn[i][j] > colMax[j]) {
					colMax[j] = lawn[i][j];
				}
			}
		}
		
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (lawn[i][j] < rowMax[i] && lawn[i][j] < colMax[j]) {
					return false;
				}
			}
		}
		
		return true;
	}
}
