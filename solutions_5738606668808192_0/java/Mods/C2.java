package jam.contest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;

public class C2
{
	public static long last_top;
	public static long pow(long a, long i)
	{
		long res = 1;
		for(long j = 0; j < i; j++)
			res *= a;
		return res;
	}
	public static long toBase(boolean[] n, int base)
	{
		long res = 0;
		for(int i = 0; i < n.length; i++)
			res += (n[n.length-1-i] ? 1 : 0)*pow(base,i);
		return res;
	}
	public static boolean isPrime(long n)
	{
		if(n <= 1)
		{
			return false;
		}
		else
		{
			for(long d = 2; d < Math.sqrt(n); d++)
			{
				if(n % d == 0)
					return false;
			}
		}
		return true;
	}
	public static boolean increment(boolean[] candidate)
	{
		int i;
		for(i = candidate.length-2; i >= 1; i--)
		{
			if(!candidate[i])
			{
				candidate[i] = true;
				break;
			}
		}
		
		for(int j = i+1; j <= candidate.length-2; j++)
		{
			candidate[j] = false;
		}
		
		return i > 0;
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
				int N = Integer.parseInt(line[0]);
				int J = Integer.parseInt(line[1]);

				// solve
				boolean[] candidate = new boolean[N];
				candidate[0] = true;
				candidate[N-1] = true;
				for(int i = 1; i < N-2; i++)
					candidate[i] = false;

				List<boolean[]> winners = new LinkedList<boolean[]>();
				{
					do
					{
						boolean win = true;
						for(int base = 2; base <= 10 && win; base++)
						{
							long n = toBase(candidate, base);
							if(n % 2 == 1)
							{
								if(isPrime(n))
									win = false;
							}
						}
						if(win)
						{
							boolean[] winner = new boolean[candidate.length];
							for(int i = 0; i < candidate.length; i++)
								winner[i] = candidate[i];
							winners.add(winner);
							System.out.println("found one");
						}
					}
					while(increment(candidate) && winners.size() < J);
				}
				
				// write output
				out.write("Case #"+(icase+1)+": \n");
				{
					for(boolean[] winner : winners)
					{
						out.write(toBase(winner, 10)+" ");
						for(int base = 2; base < 10; base++)
						{
							long n = toBase(winner, base);
							for(long d = 2; d < Math.sqrt(n); d++)
							{
								if(n % d == 0)
								{
									out.write(d+" ");
									break;
								}
							}
						}
						{
							int base = 10;
							long n = toBase(winner, base);
							for(long d = 2; d < Math.sqrt(n); d++)
							{
								if(n % d == 0)
								{
									out.write(d+"\n");
									break;
								}
							}
						}
					}
				}
			}
		}
		out.close();
		in.close();
	}
}
