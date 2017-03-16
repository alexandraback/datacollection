import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;


public class Diamond_Inheritance {

	public static Boolean Solve(int[] in, int[][] graph)
	{
		for(int i=0;i<graph.length;i++)
		{
			if(in[i]==0)
			{
				boolean[] visited=new boolean[in.length];
				Stack<Integer> q=new Stack<Integer>();
				q.push(i);
				
				while(q.size()>0)
				{
					int v=q.pop();
					if(visited[v])
						return true;
					visited[v]=true;
					for(int j=0;j<graph[v].length;j++)
					{
						q.push(new Integer(graph[v][j]));
					}
				}
			}
		}
		return false;
	}
}
/*
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;


public class Program {

	public static void main(String[] args) {
		try {
			FileWriter fileWriter=new FileWriter("A.out");
			FileReader fileReader=new FileReader("A.in");
			BufferedReader in = new BufferedReader(fileReader);

			int T= Integer.parseInt(in.readLine());
			for(int t=1;t<=T;t++)
			{
				int N= Integer.parseInt(in.readLine());
				int[][] graph=new int[N][];
				int[] inputs=new int[N];

				for(int n=0;n<N;n++)
				{
					String[] tokens= in.readLine().split(" ");
					int M= Integer.parseInt(tokens[0]);
					int[] s=new int[M];
					for(int m=0;m<M;m++)
					{
						s[m]= Integer.parseInt(tokens[m+1])-1;
						inputs[s[m]]++;
					}
					graph[n]=s;
				}
				
				boolean ans=Diamond_Inheritance.Solve(inputs, graph);
				
				
				fileWriter.write("Case #"+t +": "+(ans?"Yes":"No")+"\n");
				
			}
			fileWriter.close();
			fileReader.close();	
		} catch (Exception e) {
			System.out.println("Error! Exception: "+e); 
		}

		
	}

}
*/