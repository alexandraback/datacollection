package jam.contest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class C3
{
	public static BigInteger toBase(boolean[] n, BigInteger base)
	{
		BigInteger res = BigInteger.ZERO;
		for(int i = 0; i < n.length; i++)
			if(n[n.length-1-i])
				res = res.add(base.pow(i));
		return res;
	}
	public static boolean isPrime(BigInteger n)
	{
		if(n.compareTo(BigInteger.ONE) <= 0)
		{
			return false;
		}
		else
		{
			for(BigInteger d = BigInteger.valueOf(2); d.multiply(d).compareTo(n) <= 0; d = d.add(BigInteger.valueOf(1)))
			{
				if(n.mod(d).equals(BigInteger.ZERO))
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
				List<boolean[]> winners = new LinkedList<boolean[]>();
				Set<BigInteger> winners_int = new TreeSet<BigInteger>();
				
				// fast checking
				{
					boolean[] candidate = new boolean[N];
					candidate[0] = true;
					candidate[N-1] = true;
					for(int i = 1; i < N-2; i++)
						candidate[i] = false;
					
					do
					{
						boolean win = true;
						for(long base = 2; base <= 10 && win; base++)
						{
							BigInteger n = toBase(candidate, BigInteger.valueOf(base));
							if(!n.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO)
									&& !n.mod(BigInteger.valueOf(3)).equals(BigInteger.ZERO)
									&& !n.mod(BigInteger.valueOf(5)).equals(BigInteger.ZERO)
									&& !n.mod(BigInteger.valueOf(7)).equals(BigInteger.ZERO)
									&& !n.mod(BigInteger.valueOf(11)).equals(BigInteger.ZERO)
									&& !n.mod(BigInteger.valueOf(13)).equals(BigInteger.ZERO))
								win = false;
						}
						if(win)
						{
							boolean[] winner = new boolean[candidate.length];
							for(int i = 0; i < candidate.length; i++)
								winner[i] = candidate[i];
							winners.add(winner);

							BigInteger n = toBase(winner, BigInteger.valueOf(10));
							winners_int.add(n);
							
							System.out.println("found "+winners.size());
						}
					}
					while(increment(candidate) && winners.size() < J);
				}

				// slow checking to complete if needed
				{
					boolean[] candidate = new boolean[N];
					candidate[0] = true;
					candidate[N-1] = true;
					for(int i = 1; i < N-2; i++)
						candidate[i] = false;
					
					while(winners.size() < J)
					{
						BigInteger n = toBase(candidate, BigInteger.valueOf(10));
						if(!winners_int.contains(n))
						{
							boolean win = true;
							for(long base = 2; base <= 10 && win; base++)
							{
								n = toBase(candidate, BigInteger.valueOf(base));
								if(isPrime(n))
									win = false;
							}
							if(win)
							{
								boolean[] winner = new boolean[candidate.length];
								for(int i = 0; i < candidate.length; i++)
									winner[i] = candidate[i];
								winners.add(winner);
								System.out.println("found "+winners.size());
							}
						}
						if(!increment(candidate))
							break;
					}
				}
				
				// write output
				out.write("Case #"+(icase+1)+": \n");
				{
					for(boolean[] winner : winners)
					{
						out.write(toBase(winner, BigInteger.valueOf(10))+" ");
						for(long base = 2; base < 10; base++)
						{
							BigInteger n = toBase(winner, BigInteger.valueOf(base));
							for(BigInteger d = BigInteger.valueOf(2); d.multiply(d).compareTo(n) <= 0; d = d.add(BigInteger.valueOf(1)))
							{
								if(n.mod(d).equals(BigInteger.ZERO))
								{
									out.write(d+" ");
									break;
								}
							}
						}
						{
							long base = 10;
							BigInteger n = toBase(winner, BigInteger.valueOf(base));
							for(BigInteger d = BigInteger.valueOf(2); d.multiply(d).compareTo(n) <= 0; d = d.add(BigInteger.valueOf(1)))
							{
								if(n.mod(d).equals(BigInteger.ZERO))
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
