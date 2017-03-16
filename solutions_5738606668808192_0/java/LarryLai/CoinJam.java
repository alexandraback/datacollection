import java.io.*;
import java.util.*;

public class CoinJam {
		public static void main(String[]args)
		{
			try
			{
				Scanner sc = new Scanner(new FileReader("C-small-attempt0.in"));
				FileWriter fw = new FileWriter(new File("Output.txt"));
				PrintWriter pw = new PrintWriter(fw);
				
				int t = sc.nextInt();
				
				for(int r = 1; r <= t; r++)
				{
					int n = sc.nextInt();
					int j = sc.nextInt();
					int count = 0;
					int code = (int) Math.pow(2, n-1)+1;
					pw.println("Case #" + r + ":");
					while(count < j)
					{
						int[] divisor = new int[9];
						boolean dispose = false;
						for(int i = 2; i <= 10; i++)
						{
							int p = isPrime(Long.parseLong(Integer.toBinaryString(code), i));						
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
						pw.print(Integer.toBinaryString(code-2));
						for (int k = 0; k <= 8; k++)
						{
							pw.print(" " + divisor[k]);
						}
						pw.println();
					}	
				}
				pw.flush();
			}
			catch(IOException ioe)
			{
				System.out.print(ioe);
			}

		}
		public static int isPrime(long n)
		{
			for (int i = 2; i <= (int)Math.sqrt(n); i++)
			{
				if((n % (long)i) == 0)
					return i;			
			}
			return -1;
		}	
	}

