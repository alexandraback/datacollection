package tide;

import java.io.BufferedReader;
import java.io.FileReader;

public class Tide 
{	
	public static void print(int[][] arr) {
		for (int i = 0; i < arr.length; ++i) {
			for (int j = 0; j < arr[i].length; ++j) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		String line = in.readLine();
		int T = Integer.parseInt(line);
		for (int i = 0; i < T; ++i) 
		{
			line = in.readLine();
			String[] toks = line.split(" ");
			int H = Integer.parseInt(toks[0]);
			int N = Integer.parseInt(toks[1]);
			int M = Integer.parseInt(toks[2]);
			int[][] C = new int[N][M];
			int[][] F = new int[N][M];
			for (int n = 0; n < N; ++n) 
			{
				toks = in.readLine().split(" ");
				for (int m = 0; m < M; ++m)
				{
					C[n][m] = Integer.parseInt(toks[m]);
				}
			}
			for (int n = 0; n < N; ++n) 
			{
				toks = in.readLine().split(" ");
				for (int m = 0; m < M; ++m)
				{
					F[n][m] = Integer.parseInt(toks[m]);
				}
			}
			Solver solver = new Solver(C, F, H);
			//solver.print();
			System.out.println("Case #"+(i+1)+": "+solver.solve());
		}
	}
}
