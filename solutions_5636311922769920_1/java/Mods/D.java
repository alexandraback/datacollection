package jam.contest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class D
{
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
			
				out.write("Case #"+(icase+1)+":");
				if(C == 1)
				{
					if(S != K)
						out.write(" IMPOSSIBLE");
					else
						for(long k = 1; k <= K; k++)
							out.write(" "+k);
				}
				else
				{
					// large input
					long Strue = (K % 2 == 0) ? (K / 2) : (K / 2 + 1);
					if(Strue > S)
						out.write(" IMPOSSIBLE");
					else
					{
						for(long s = 0; s < Strue; s++)
						{
							long k = K*s + K-s;
							out.write(" "+k);
						}
					}
				}
				out.write("\n");
			}
		}
		out.close();
		in.close();
	}
}
