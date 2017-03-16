/* Andy Rock
 * April 8, 2016
 * 
 * Qualification Round 2016: Problem D. Fractiles
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class D
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in  = new BufferedReader(new FileReader( "in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

		int T = Integer.parseInt(in.readLine());
		for(int t=1;t<=T;t++)
		{
			StringTokenizer st = new StringTokenizer(in.readLine());
			int K = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			int S = Integer.parseInt(st.nextToken());

			out.write("Case #"+t+": ");
			for(int i=0;i<S;i++)
			{
				long ans = i;
				for(int j=1;j<C;j++)
					ans = K*ans+i;
				out.write(ans+1+" ");
			}
			out.write("\n");
		}

		 in.close();
		out.close();
	}
}