import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

 
public class A {
	
	
	static class Scanner
	{
		BufferedReader rd;
		StringTokenizer tk;
		public Scanner() throws IOException
		{
			rd=new BufferedReader(new InputStreamReader(System.in));
			tk=new StringTokenizer(rd.readLine());
		}
		public String next() throws IOException
		{
			while (!tk.hasMoreTokens())
				tk=new StringTokenizer(rd.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException
		{
			return Integer.valueOf(this.next());
		}
	}
	
	
	
	static class Node
	{
		int n;
		LinkedList<Integer> ve=new LinkedList<Integer>();
		int visited;
		public Node(int a)
		{
			n=a;
			ve=new LinkedList<Integer>();
			visited=-1;
		}
	}
	
	static int N;
	static Node[] array=new Node[1010];
	static int times=0;
	
	
	
	
	static boolean dfs(Node a,int color)
	{
		if (a.visited==color)
			return true;
		a.visited=color;
		for(int v: a.ve)
		{
			if (dfs(array[v],color))
				return true;
		}
		return false;
	}
	
	public static void main(String args[]) throws IOException
	{
		Scanner sc=new Scanner();
		int T=sc.nextInt();
		for(int caso=1;caso<=T;caso++)
		{
			N=sc.nextInt();
			for(int i=0;i<N;i++)
			{
				array[i]=new Node(i);
				int c=sc.nextInt();
				for(int j=0;j<c;j++)
					array[i].ve.add(sc.nextInt()-1);
			}
			System.out.print("Case #"+caso+": ");
			boolean flag=false;
			int color=1;
			for(int i=0;i<N;i++)
			{
				if (dfs(array[i],color))
				{
					flag=true;
					break;
				}
				color++;
			}
			if (flag)
				System.out.println("Yes");
			else
				System.out.println("No");
		}
	}

}