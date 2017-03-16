import java.util.*;
import java.io.*;
public class B {
	static int t,a,b,k,ans;
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
		t = i(in.readLine());
		for(int x = 0; x < t; x++)
		{
			StringTokenizer st = new StringTokenizer(in.readLine());
			//System.out.printf("Case #%d: ",x+1);
			out.printf("Case #%d: ",x+1);
			a = i(st.nextToken());
			b = i(st.nextToken());
			k = i(st.nextToken());
			ans = 0;
			for(int i = 0; i < a; i++)
			{
				for(int j = 0; j < b; j++)
				{
					if((i&j)<k) ans++;						
				}
			}
			//System.out.println(ans);
			out.println(ans);
		}
		out.close();
		System.exit(0);
	}
	static int i(String s)
	{
		return Integer.parseInt(s);
	}
}
