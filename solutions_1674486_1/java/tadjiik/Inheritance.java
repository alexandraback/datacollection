import java.util.*;

public class Inheritance {

	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();
		for(int ii = 1; ii <= tt; ii++)
		{
			int n = sc.nextInt();
			boolean map[][] = new boolean[n][n];
			for(int i = 0; i < n; i++)
			{
				int m = sc.nextInt();
				for(int j = 0; j < m; j++)
				{
					map[sc.nextInt()-1][i] = true;
				}
			}
						
			Queue<Integer> queue = new LinkedList<Integer>();
			boolean found = false;
			for(int i = 0; !found && i < n; i++)
			{
				boolean visited[] = new boolean[n];
				queue.add(i);
				while(!queue.isEmpty())
				{
					int t = queue.remove();
					for(int j = 0; !found && j < n; j++)
					{
						if(map[t][j])
						{
							if(visited[j])
							{
								found = true;
								break;
							} else {
								visited[j] = true;
								queue.add(j);
							}
						}
					}
				}
			}
			
			System.out.println("Case #" + ii + ": " + (found ? "Yes" : "No"));
		}
	}
}
