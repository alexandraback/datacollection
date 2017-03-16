package jam.contest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class A
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
				int N = Integer.parseInt(in.readLine());
				
				int NCalled = -1;
				if(N != 0)
				{
					boolean[] digits = new boolean[10];
					for(int i = 0; i < 10; i++)
						digits[i] = false;
					boolean all_digits = false;

					int M = 0;
					while(!all_digits)
					{
						M++;
						NCalled = M*N;
						String number = Integer.toString(NCalled);
						for(int i = 0; i < number.length(); i++)
							digits[Integer.parseInt(number.charAt(i)+"")] = true;
						
						all_digits = true;
						for(int i = 0; i < 10 && all_digits; i++)
							if(!digits[i])
								all_digits = false;
					}
				}
				
				// write output
				out.write("Case #"+(icase+1)+": "+(NCalled >= 0 ? NCalled : "INSOMNIA")+"\n");
			}
		}
		out.close();
		in.close();
	}
}
