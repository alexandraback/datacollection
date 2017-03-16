import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

public class diamonds {
	private static int [][] graph;
	private static int n;
	private static boolean solve()
	{
		for(int i = 0; i < n; i++)
		{
			boolean [] closed = new boolean[n];
			Queue<Integer> q = new LinkedList<Integer>();
			q.add(i);
			while(!q.isEmpty())
			{
				int x = q.poll();
				if(closed[x]) return true;
				closed[x] = true;
				for(int j = 0; j < n; j++)
					if(graph[x][j] == 1)
						q.add(j);
			}
		}
		
		return false;
	}
	
	
	
	
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("input"));
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		for(int x = 1; x<= t;x++)
		{
			n = s.nextInt();
			graph = new int[n][n];
			for(int i = 0; i < n; i++)
			{
				int v = s.nextInt();
				for(int j = 0; j < v; j++)
				{
					graph[i][s.nextInt()-1] = 1;
				}
			}
			System.out.println("Case #"+x + (solve()==true?": Yes" : ": No"));
		}

	}
}
