import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.util.Map;
import java.util.HashMap;


public class dijkstra {
	public static void main(String[] args)
	{
		int [][] multTable = new int [5][5];
		
		multTable[1][1] = 1; 
		multTable[1][2] = 2;
		multTable[1][3] = 3;
		multTable[1][4] = 4;
		
		multTable[2][1] = 2; 
		multTable[2][2] = -1;
		multTable[2][3] = 4;
		multTable[2][4] = -3;
		
		multTable[3][1] = 3; 
		multTable[3][2] = -4;
		multTable[3][3] = -1;
		multTable[3][4] = 2;
		
		multTable[4][1] = 4; 
		multTable[4][2] = 3;
		multTable[4][3] = -2;
		multTable[4][4] = -1;

		
		try
		{
			
			BufferedWriter bw = new BufferedWriter(new FileWriter("dijkstra.out"));
			BufferedReader br = new BufferedReader(new FileReader("dijkstra.in"));
			
			int T, L, X;
			T = Integer.parseInt(br.readLine());
			
			for (int tc=1; tc<= T; tc++)
			{
				String[] line = br.readLine().split(" ");
				L = Integer.parseInt(line[0]);
				X = Integer.parseInt(line[1]);
				//X = X % 16;
				
				int[] LA = new int[L]; 

				String chars = br.readLine();
				
				for (int j=0; j<L; j++)
				{
					LA[j] = chars.charAt(j) - 'i' + 2;
				}
				
				int count = X * L;
				int product = 1;
				boolean found = false;
				for (int i=0; i<count; i++)
				{
					if (product < 0)
						product = -1 * multTable[-product][LA[i % L]];
					else
						product = multTable[product][LA[i % L]];
					
					if (product == 2) // Found i
					{
						product = 1;
						for (int j=i+1; j<count; j++)
						{
							if (product < 0)
								product = -1 * multTable[-product][LA[j % L]];
							else
								product = multTable[product][LA[j % L]];
							
							if (product == 3) // Found j
							{
								product = 1;
								for (int k=j+1; k<count; k++)
								{
									if (product < 0)
										product = -1 * multTable[-product][LA[k % L]];
									else
										product = multTable[product][LA[k % L]];
								}
								if (product == 4) // Found k
									found = true;
								i = j = count;
							}
						}
					}
				}
				if (found)
					bw.write("Case #"+ tc + ": YES");
				else
					bw.write("Case #"+ tc + ": NO");
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
