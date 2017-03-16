import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CoinJam {
		public static void main(String[]args)
		{
			try
			{
				Scanner sc = new Scanner(new FileReader("C-large.in"));
				FileWriter fw = new FileWriter(new File("Output.txt"));
				PrintWriter pw = new PrintWriter(fw);
				
				int t = sc.nextInt();
				
				for(int r = 1; r <= t; r++)
				{
					int n = sc.nextInt();
					int j = sc.nextInt();
					int count = 0;
					long code = (long) Math.pow(2, n-1)+1;
					pw.println("Case #" + r + ":");
					while(count < j)
					{
						long[] divisor = new long[9];
						boolean dispose = false;
						for(int i = 2; i <= 10; i++)
						{
							long p = isPrime(Long.toBinaryString(code), i);
							if(p == -1)
							{
								dispose = true;
								break;
							}
							else
							{
								divisor[i-2] = p;
							}
						}
						code += 2;
						if(dispose)
							continue;
						count++;
						pw.print(Long.toBinaryString(code-2));
						for (int k = 0; k <= 8; k++)
						{
							pw.print(" " + divisor[k]);
						}
						pw.println();
					}	
				}
				pw.flush();
				pw.close();
				sc.close();
			}
			catch(IOException ioe)
			{
				System.out.print(ioe);
			}

		}
		public static long isPrime(String n, int base)
		{
			long b = Long.parseLong(n.substring(0,n.length()/2), base);
			long a = Long.parseLong(n.substring(n.length()/2), base);
			for (long i = 2; i <= Math.sqrt(b); i++)
			{
				if (a%i == 0 && b%i == 0)
				{
					return i;
				}
			}
			
			return -1;
		}	
	}

