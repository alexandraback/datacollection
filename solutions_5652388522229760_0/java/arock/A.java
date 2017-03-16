/* Andy Rock
 * April 8, 2016
 * 
 * Qualification Round 2016: Problem A. Counting Sheep
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class A
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in  = new BufferedReader(new FileReader("A.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

		int T = Integer.parseInt(in.readLine());
		for(int t=1;t<=T;t++)
		{
			long N = Integer.parseInt(in.readLine());

			if(N == 0)
				out.write("Case #"+t+": INSOMNIA\n");
			else
			{
				long curr = N;
				for(int i=0;i<0b1111111111;curr+=N)
					for(char c : Long.toString(curr).toCharArray())
						i |= 1 << (c-'0');
				out.write("Case #"+t+": "+(curr-N)+"\n");
			}
		}

		 in.close();
		out.close();
	}
}