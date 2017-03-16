import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class ProblemA {
	static ArrayList<Integer> [] map;
	static boolean [] visited;
	public static boolean dfs(int a){
		if(visited[a])
			return true;
		visited[a]= true;
		for(int i: map[a])
		{
			if(dfs(i))
				return true;
		}
		return false;
	}
	public static void main(String[] args) throws Exception {
		  BufferedReader br = new BufferedReader(new FileReader(new File("A-small-attempt0.in")));
		  PrintWriter pw = new PrintWriter(new File("A-small-attempt0.out"));
		  int t= new Integer(br.readLine());
		  int n , a, b;
		  StringTokenizer st ;
		  
		  for(int c=1; c<=t; c++)
		  {
		   pw.append("Case #"+c+": ");
		   
		   n= new Integer(br.readLine());
		   map= new ArrayList[n];
		   for (int i=0; i< n ; i++)
		   {
			   map[i]= new ArrayList<Integer>();
			   st = new StringTokenizer(br.readLine());
			   a= new Integer(st.nextToken());
			   
			   for (int j=0;j< a; j++)
			   {
				   b = new Integer(st.nextToken())-1;
				   map[i].add(b);
			   }
			   
		   }
		   String res= "No";
		   for(int i=0; i< n ; i++)
		   {
			   visited= new boolean [n];
			   if(dfs(i)){
				   res="Yes";
				   break;
			   }
		   }
		   pw.append(res+'\n');
		  }
		  pw.flush();
		  pw.close();
		  br.close();
		 }
}
