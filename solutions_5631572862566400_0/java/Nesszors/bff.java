import java.util.*;

public class bff
{
	static Scanner scan;
	static int N, T;
	static int[] id;
	static int[] p;
	static Alist[] edge;
	static boolean[] seen;
	static int max, start;
	
	static class Alist extends ArrayList<Integer>{}
	static void init()
	{
		scan= new Scanner(System.in);
		T= scan.nextInt();
	}
	
	static void dfs(int prev, int index, int depth)
	{
		if(seen[index])
			return;
	
		
		max= Math.max(depth,max);
		seen[index]= true;
	//	System.out.println(index);
		for(Integer next: edge[index])	
		{
			if(prev>0 && prev!=id[index] && next!=id[index])
				continue;
			if(seen[id[next]] && id[next]!=start && id[next]!=index)
				continue;
			dfs(index, next, depth+1);
	//		System.out.println(index+" "+next);
		}
	}
	public static void main(String[] args)
	{
		
		init();
		
		for(int zz=1; zz<=T; zz++)
		{
			N= scan.nextInt();
			id= new int[N+1];
			edge= new Alist[N+1];
			seen= new boolean[N+1];
			max=0;
			
			for(int i=1; i<=N; i++)
				edge[i]= new Alist();
				
			for(int i=1; i<=N; i++)
			{
				id[i]= scan.nextInt();
				
				edge[i].add(id[i]);
				edge[id[i]].add(i);
			}
			
			for(int i=1; i<=N; i++)
			{
				Arrays.fill(seen,false);
				start=i;
				dfs(-1,i,1);
		//		System.out.println();
			}
			
			System.out.println("Case #"+zz+": "+max);
			
		}
	}
}