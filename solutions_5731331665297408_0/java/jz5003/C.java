import java.util.*;
import java.io.*;
public class C{
	static int t,n,m,  vis[], vis2[];
	static Zip[] zips;
	static ArrayList<String> ans;
	static boolean ed[][];
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C.out")));
		
		t = i(in.readLine());
		for(int x = 0; x < t; x++)
		{
			//System.out.printf("Case #%d: ",x+1);
			out.printf("Case #%d: ",x+1);
			ans = new ArrayList<String>();
			StringTokenizer st = new StringTokenizer(in.readLine());
			n=i(st.nextToken());
			m = i(st.nextToken());
			zips = new Zip[n+1];
			ed = new boolean[n+1][n+1];
			vis = new int[n+1];
			vis2= new int[n+1];
			for(int i = 1; i <= n; i++)
				zips[i]=new Zip(in.readLine(),i);
			zips[0]=new Zip("",0);
			Arrays.sort(zips, 1, zips.length);
			for(int i = 1; i <= n; i++) ed[0][i] = true;
			for(int a,b,i = 0; i < m; i++)
			{
				st =new StringTokenizer(in.readLine());
				a = i(st.nextToken()); b = i(st.nextToken());
				ed[a][b]= ed[b][a]= true;
			}			
			try
			{
				search(0,0);
			} catch (Exception e)
			{
				for(int i = 0; i < ans.size(); i++)
				{
					for(int j = 0; j < 5; j++)
						out.print(ans.get(i).charAt(j));
				}
			}
			out.println();
		}
		out.close();
		System.exit(0);
	}
	//start node
	static void search(int start, int num) throws Exception
	{
		
		//System.out.println(start); // 
		if(start!=0)
		for(int i = 1; i <= n; i++)
			if(ed[start][i]) vis[i]++;
		if(num==n) throw new Exception();
		for(int i = 1; i <= n; i++)
		{			
			if((start!=0 && (vis[zips[i].id]<=0 || vis2[zips[i].id]!=0)) )continue;
			
				ans.add(zips[i].zip);
				vis2[zips[i].id]=1;
				//System.out.println(zips[i].zip);
				vis2[zips[i].id]=1;
				search(zips[i].id, num+1);
				ans.remove(zips[i].zip);
			
		}
		if(start!=0)
		for(int i = 1; i <= n; i++)
			if(ed[start][i]) vis[i]--;
	}
	static int i(String s)
	{
		return Integer.parseInt(s);
	}
}
class Zip implements Comparable<Zip>
{
	String zip;
	int id;
	public Zip(String z, int i) 
	{
		zip = z; id = i;
	}
	public int compareTo(Zip z)
	{
		return zip.compareTo(z.zip);
	}
}