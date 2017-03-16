import java.util.*;

class A
{
	static boolean dfs(boolean graph[][], int start)
	{
		Stack<Integer> q = new Stack<Integer>();
		q.push(start);
		int [] v = new int[graph.length];
		for(int i=0;i<graph.length;++i)
			v[i] = 0;
		while(q.isEmpty() == false)
		{
			int curr = q.pop();
			v[curr] = 1;
			
			for(int i=0;i<graph[curr].length;++i)
			{
				if(graph[curr][i] == true)
				{
					if(v[i] == 1)
					{
						return true;
					}
					v[i] = 1;
					q.push(i);
				}
			}
		}
		return false;
	}
	
	public static void main(String[] args)
	{
		int t;
		Scanner in = new Scanner(System.in);
		
		boolean graph[][];
		t = in.nextInt();
		for(int casen=1;casen<=t;++casen)
		{
			int n = in.nextInt();
			graph = new boolean[n][n];
			for(int i = 0; i < n; i++) {
  			  Arrays.fill(graph[i], false);
			}
			
			int edges = 0;
			for(int i=0;i<n;++i)
			{
				int numinhen = in.nextInt();
				edges += numinhen;
				for(int k=0;k<numinhen;++k)
				{
					int curr = in.nextInt() - 1;
					graph[i][curr] = true;
				}
			}
			boolean mul = false;
			for(int i=0;i<n;++i)
			{
				mul = dfs(graph,i);
				if(mul)
					break;
			}
			
			if(mul)
				System.out.println("Case #"+casen+": Yes");
			else
				System.out.println("Case #"+casen+": No");
		}
		
		
	}
	
	
}
