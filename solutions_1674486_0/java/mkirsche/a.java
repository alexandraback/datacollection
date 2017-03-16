import java.util.*;
public class a 
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for(int t = 0; t<T; t++)
		{
			int n = input.nextInt();
			ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>();
			for(int i = 0; i<n; i++)
			{
				adj.add(new ArrayList<Integer>());
				int m = input.nextInt();
				for(int j = 0; j<m; j++)
				{
					int next = input.nextInt();
					adj.get(i).add(next-1);
				}
			}
			boolean found = false;
			for(int i = 0; i<n; i++)
			{
				boolean[] visited = new boolean[n];
				Queue<Integer> q = new LinkedList<Integer>();
				visited[i] = true;
				q.add(i);
				while(!q.isEmpty()){
					int at = q.poll();
					for(int next: adj.get(at))
					{
						if(!visited[next])
						{
							visited[next] = true;
							q.add(next);
						}
						else
							found = true;
					}
				}
			}
			System.out.printf("Case #%d: ", (t+1));
			System.out.println(found? "Yes" : "No");
		}
	}
}
