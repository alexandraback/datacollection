import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class Q1 
{

	public static Ob[] obs;
	public static boolean ff = false;
	
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
		
		for(int i = 0; i < num; i ++)
		{
			int numc = sc.nextInt();
			obs = new Ob[numc];
			ff = false;
			
			for(int k = 0; k < numc; k++)
			{
				int numi = sc.nextInt();
				Ob curr = new Ob();
				
				for(int j = 0; j < numi; j++)
				{
					curr.inherit.add(sc.nextInt());
				}
				obs[k] = curr;
			}
			
			boolean r = false;
			
			for(int z = 0; z < numc; z++)
			{
				Ob curre = obs[z];
				bfs(curre);
				for(int u = 0; u < obs.length; u++)
				{
					obs[u].visited = false;
				}
				if(ff)
				{ 
					System.out.println("Case #" + (i+1) + ": Yes"); 
					r = true;
					break;
				} 
				ff = false;
			}
			
			if(r){ continue; }
			System.out.println("Case #" + (i+1) + ": No"); 
		}
	}
	
	public static void bfs(Ob start)
	{
		if(start.visited == true)
		{
			ff = true;
			return;
		}
		start.visited = true;
		
		for(int next : start.inherit)
		{
			bfs(obs[next-1]);
		}
	}

}

class Ob
{
	public boolean visited = false;
	public Set<Integer> inherit = new HashSet<Integer>();
}
