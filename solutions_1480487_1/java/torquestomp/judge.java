import java.io.*;
import java.util.*;

public class judge
{

	java.math.BigInteger x;
	
	public static StringTokenizer st;

	public static void main(String[] args)
	{
		try
		{
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("A-large.in")));
			PrintWriter pw = new PrintWriter(new FileWriter("output.out"));
			
			int T = Integer.parseInt(br.readLine());
			
			for (int t = 1; t <= T; t++)
			{
				st = new StringTokenizer(br.readLine(), " ", false);
				
				int N = Integer.parseInt(st.nextToken());
				double[] J = new double[N];
				int X = 0;
				for (int i = 0; i < N; i++)
				{
					J[i] = Integer.parseInt(st.nextToken());
					X += J[i];
				}
				
				// Mutate J until no one is eliminated
				double[] J2 = new double[N];
				for (int i = 0; i < N; i++) J2[i] = J[i];
				
				int rem = X;
				while (rem > 0)
				{
					int min = X;
					int nummin = 0;
					for (int i = 0; i < N; i++)
					{
						if (J2[i] < min)
						{
							min = (int)J2[i];
							nummin = 1;
						}
						else if (J2[i] == min)
							nummin++;
					}
					
					//System.out.println(t+", "+rem+", "+min+", "+nummin);
					
					if (nummin == N)
					{
						for (int i = 0; i < N; i++) J2[i] += (double)rem / (double)N;
						break;
					}
					
					int nextMin = X;
					for (int i = 0; i < N; i++) if (J2[i] > min && J2[i] < nextMin) nextMin = (int)J2[i];
					
					// raise everything until nextMin is hit
					int toRaise = (nextMin-min)*nummin;
					if (toRaise <= rem)
					{
						rem -= toRaise;
						for (int i = 0; i < N; i++) if (J2[i] == min) J2[i] = nextMin;
					}
					else
					{
						double add = (double)rem / (double)nummin;
						for (int i = 0; i < N; i++) if (J2[i] == min) J2[i] = min+add;
						rem = 0;
					}
				}
				
				pw.print("Case #"+t+": ");
				
				java.text.DecimalFormat fmt = new java.text.DecimalFormat("0.000000");
				for (int i = 0; i < N; i++)
				{
					double num;
					if (J2[i] == J[i]) num = 0;
					else num = 100.0*(J2[i]-J[i])/X;
					
					pw.print(fmt.format(num));
					if (i == N-1) pw.println();
					else pw.print(" ");
				}
			}
			pw.flush();
			pw.close();
			br.close();
		}
		catch (IOException ie)
		{
			ie.printStackTrace();
		}
	}
	
}