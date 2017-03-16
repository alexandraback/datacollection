package jam.contest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class D
{
	public static long pow(long a, long i)
	{
		long res = 1;
		for(long j = 0; j < i; j++)
			res *= a;
		return res;
	}
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		BufferedWriter out = new BufferedWriter(new FileWriter(args[1]));
		{
			int nb_cases = Integer.parseInt(in.readLine());
			
			for(int icase = 0; icase < nb_cases; icase++)
			{
				// read input
				String[] line = in.readLine().split(" ");
				int K = Integer.parseInt(line[0]);
				int C = Integer.parseInt(line[1]);
				int S = Integer.parseInt(line[2]);
			
				// write output
				out.write("Case #"+(icase+1)+":");
				if(S == K)
				{
					for(long s = 1; s <= K; s++)
						out.write(" "+s*pow(K,C-1));
				}
				else
				{
					out.write(" IMPOSSIBLE");
				}
				out.write("\n");
			}
		}
		out.close();
		in.close();
	}
}
