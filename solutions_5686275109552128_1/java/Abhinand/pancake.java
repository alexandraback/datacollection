
import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.util.Map;
import java.util.HashMap;


public class pancake {
	public static void main(String[] args)
	{
		
		try
		{
			BufferedWriter bw = new BufferedWriter(new FileWriter("pancake2.out"));
			BufferedReader br = new BufferedReader(new FileReader("pancake2.in"));
			
			int T, D;
			int[] P;
			T = Integer.parseInt(br.readLine());
			
			for (int i=1; i<= T; i++)
			{
				D = Integer.parseInt(br.readLine());
				P = new int[D];
				String[] line = br.readLine().split(" ");
				int MAX = -1;
				for (int j=0; j<D; j++)
				{
					P[j] = Integer.parseInt(line[j]);
					if (MAX < P[j])
						MAX = P[j];
				}
				
				int minTime = MAX; 
				for (int max=MAX-1; max > 0; max--)
				{
					int special = 0;
					for (int j=0; j<D; j++)
					{
						if (P[j] > max)
						{
							special += (P[j]-1)/max;
						}
					}
					if (special + max < minTime)
						minTime = special + max;
				}
				bw.write("Case #"+i + ": " + minTime);
				
				bw.newLine();
				
			}
			bw.close();
			br.close();
			
		}
		catch (Exception ex) 
		{
			System.out.println(ex.getMessage());
		}
	}
}
