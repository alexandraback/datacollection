import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Set;
import java.util.HashSet;
import java.util.Scanner;
 
public class Jam6
{
	private static Graph graph;
 
	public int isCyclic()
	{
		int ans=0;
		boolean[] visited = new boolean[graph.vertices];
		Arrays.fill(visited, false); 
		Set<Integer> recStack = new HashSet<>();
		//System.out.println(graph.vertices);
		for(int i=0;i<graph.vertices;i++)
		{
			if(helper(i, visited, recStack))
					ans= Math.max(recStack.size(),ans);
		}
		return ans;
	}
	public boolean helper(int v, boolean[] visited, Set<Integer> recStack)
	{
		//System.out.println("v: "+v+" set: "+recStack);
		if(!visited[v])
		{
			visited[v] = true;
			recStack.add(v);
			for(int i : graph.adj.get(v))
			{
				if(!visited[i])
				{
					if(helper(i, visited, recStack))
						return true;
				}
				else if(recStack.contains(i))
					return true;
			}
		}
		recStack.remove(v);
		return false;
	}
 
	public static void main(String args[])
	{
		Scanner in=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		Jam6 c=new Jam6();
		int t=in.nextInt();// #case
		in.nextLine();
		
		for(int k=1; k<=t;k++){
			System.out.print("Case #"+ k + ": ");
			
			int n=in.nextInt();//#kids
			in.nextLine();
			graph = new Graph(n);
			//String n = in.nextLine();
		    for(int j=0;j<=n-1;j++){
		    	int bbf=in.nextInt();
		    	graph.addEdge(j, bbf-1);
		    }
		    in.nextLine();
		    
		    System.out.println(c.isCyclic());
		}    
	}
}