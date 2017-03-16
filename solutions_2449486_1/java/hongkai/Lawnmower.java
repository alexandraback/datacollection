import java.util.*;
import java.io.*;

public class Lawnmower {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("file")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int cases = Integer.parseInt(st.nextToken());
		
		for(int i=1; i<= cases; i++){
			st = new StringTokenizer(in.readLine());
			int rows = Integer.parseInt(st.nextToken());
			int cols = Integer.parseInt(st.nextToken());
			
			int[][] grid= new int[rows][cols];
			
			for(int j=0; j < rows; j++){
				st = new StringTokenizer(in.readLine());
				for(int k=0; k < cols; k++)
					grid[j][k] = Integer.parseInt(st.nextToken());
			}
			
			int[] rowMax = new int[rows];
			int[] colMax = new int[cols];
			
			for(int r=0; r < rows; r++)
				for(int c=0; c < cols; c++){
					if(grid[r][c] > rowMax[r])
						rowMax[r] = grid[r][c];
					if(grid[r][c] > colMax[c])
						colMax[c] = grid[r][c];
				}
			boolean canCreate = true;
			for(int r=0; r < rows; r++)
				for(int c=0; c < cols; c++)
					if(grid[r][c] < rowMax[r] && grid[r][c] < colMax[c])
						canCreate = false;
			
			out.print("Case #" + i + ": ");
			if(canCreate)
				out.println("YES");
			else
				out.println("NO");
		}
		out.close();
	}
}
