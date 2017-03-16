import java.util.Scanner;


public class DiamondInheritance {
	
	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);

		int cases = input.nextInt();
		for (int c = 1; c <= cases; c++)
		{
			System.out.println("Case #" + c + ": " + (solve(input) ? "Yes" : "No"));
		}
		
		input.close();
	}

	private static boolean solve(Scanner input) {
		
		int h;
		int k;
		int m;
		int p;
		int classes = input.nextInt();
		
		int[][] successors = new int[classes][];
		int[] indegree = new int[classes];
		
		for (h = 0; h < classes; h++)
		{
			m = input.nextInt();
			successors[h] = new int[m];
			for (k = 0; k < m; k++)
			{
				p = input.nextInt() - 1;
				successors[h][k] = p;
				indegree[p]++;
			}
		}
		
		//Use depth-first search and check
		boolean[] seen = new boolean[classes];
		for (h = 0; h < classes; h++)
		{				
			if (indegree[h] == 0)
			{
				for (k = 0; k < classes; k++)
					seen[k] = false;
				
				if (search(h, successors, seen))
					return true;
			}
		}
		
		return false;
	}

	private static boolean search(int node, int[][] successors, boolean[] seen) {
		
		int[] next = successors[node];
		for (int k = 0; k < next.length; k++)
		{
			if (!seen[next[k]])
			{
				seen[next[k]] = true;
				if (search(next[k], successors, seen))
					return true;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

}
