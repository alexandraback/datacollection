import java.io.*;
import java.util.*;
import static java.lang.Integer.*;
import static java.lang.Long.*;
import static java.lang.Double.*;
import java.math.*;
class a
{
  	public static void main (String [] args) throws IOException 
  	{	
  		BufferedReader f = new BufferedReader(new FileReader(new File("a.in")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		PrintWriter out = new PrintWriter(new FileWriter(new File("sol.out")));
		long zz = Integer.parseInt(st.nextToken());
		for(int z = 0;z<zz;z++)
		{
			st = new StringTokenizer(f.readLine());
			String name = st.nextToken(); 
			int n = Integer.parseInt(st.nextToken());
			long cnt = 0;
			int last = 0;
			for(int i = 0;i<name.length();i++)
			{
				for(int j = name.length();check(name,i,j,n);j--,cnt++){}
			}
			out.printf("Case #%d: %d%n",z+1,cnt);	
		}
		out.close();
		System.exit(0);
  	}
  	public static boolean check(String str,int start, int end,int n)
  	{
  		int c = 0;
  		for(int i = start;i<end;i++)
  		{
  			if(c==n)
  				return true;
  			if(!"aeiouAEIOU".contains(str.charAt(i)+""))
  				c++;
  			else
  				c=0;
  		}
  		return c>=n;
  	}
}
