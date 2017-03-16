import java.util.*;
import java.io.*;
public class QualProbA {
	

	public static void main(String[] args) throws Exception
	{
		String file = "A-large.in";

		BufferedReader br = new BufferedReader(new FileReader(file));
		PrintWriter writer = new PrintWriter("out.txt", "UTF-8");
		String line;

		int T = Integer.parseInt(br.readLine());
		
		for(int test=0;test<T;test++)
		{
			line=br.readLine();
			String[] parts = line.split(" ");
			int Smax = Integer.parseInt(parts[0]);
			int[] Ss = new int[Smax+1];
			for(int i=0;i<Smax+1;i++)
			{
				Ss[i] = parts[1].charAt(i)-'0';
			}
			
			int numNeeded = 0;
			int numStanding = 0;
			for(int i=0;i<=Smax;i++)
			{
				if(numStanding<i)
				{
					int add = (i-numStanding);
					numNeeded += add;
					numStanding += add;
				}
				numStanding+=Ss[i];
			}
			writer.println("Case #" + (test+1)+": " + numNeeded);
		}
		writer.close();
    }
}
