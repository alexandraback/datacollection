/* Andy Rock
 * April 8, 2016
 * 
 * Qualification Round 2016: Problem C. Coin Jam
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class C
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader in  = new BufferedReader(new FileReader( "in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));

		int T = Integer.parseInt(in.readLine());
		for(int t=1;t<=T;t++)
		{
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			int J = Integer.parseInt(st.nextToken());

			char[] num = new char[N];
			for(int i=0;i<N;i++)
				if(i == 0 || i+1 == N)
					num[i] = '1';
				else
					num[i] = '0';

			out.write("Case #"+t+":\n");
			while(J > 0)
			{
				int[] factors = new int[11];

				boolean good = true;
				for(int i=2;i<=10&&good;i++)
					if(new BigInteger(new String(num), i).isProbablePrime(100))
						good = false;
					else
					{
						for(int j=2;good;j++)
							if(j > 100000)
								good = false;
							else if(new BigInteger(new String(num), i).mod(new BigInteger(Integer.toString(j))).equals(BigInteger.ZERO))
							{
								factors[i] = j;
								break;
							}
					}

				if(good)
				{
					out.write(new String(num)+" ");
					for(int i=2;i<=9;i++)
						out.write(factors[i]+" ");
					out.write(factors[10]+"\n");

					J--;
				}

				num[N-2]++;
				for(int i=N-2;;i--)
					if(num[i] == '2')
					{
						num[i] = '0';
						num[i-1]++;
					}
					else
						break;
			}
		}

		 in.close();
		out.close();
	}
}