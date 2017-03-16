import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;


public class manageyourenergy {
	  
	public static int t;
	
	public static int e;
	public static int r;
	public static int n;
	public static int[] v;
	
	public static int[] coef;
	
	public static long [][] dc;
	
	public static long engsum()
	{
		long sum = 0L;
		for(int i=0; i< n; i++)
			sum += (long)coef[i]*(long)v[i];	
		return sum;
	}	
	
	public static long calEnergy()
	{
		coef = new int [n];
		Arrays.fill(coef, e);
		
		if(r >= e)
		{
			return engsum();
		}
		
		dc = new long [n][e];
		
		for(int i= n-1; i>=0; i--)
		{
			for(int j=0; j< e; j++)
			{
				
					if(i == 0 && j < e-1)
						continue;
					if(i == n-1)
						dc[i][j] = v[i]*(j+1);
					else
					{		
						dc[i][j] = 0;
						for(int m=0; m<= j+1; m++)
						{
							
							int tmpind = Math.min(e, j+1-m+r);
							long tmpv = v[i]*m + dc[i+1][tmpind-1];
							if(dc[i][j] < tmpv)
								dc[i][j] = tmpv;
						}
					}
			}
		}
		
		long maxeng = 0L;
		for(int i=0; i< e; i++)
		{
			if(maxeng < dc[0][i])
				maxeng = dc[0][i];
		}
		
		/*for(int i=0; i< n; i++)
		{
			for(int j=0; j< e; j++)
			{
				
				System.out.printf("%d,", dc[i][j]);
			}
			System.out.printf("\n");
		}*/
		return maxeng;
	}
	
	public static void main(String[] s) throws IOException
	{
				//BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		
				File file = new File("B-large.in");
				BufferedReader input = new BufferedReader(new FileReader(file));
				
				File outfile = new File("B-large-RA-3.out");
				
				if(!outfile.exists())
					file.createNewFile();
				
				FileWriter fw = new FileWriter(outfile.getAbsoluteFile());
				BufferedWriter bw = new BufferedWriter(fw);
				
				String line = input.readLine();
				
				t = Integer.parseInt(line);
				
				for(int i=0; i< 50; i++)
				{
					/*if(i < 70)
					{
						line = input.readLine();
						continue;
					}*/
					line = input.readLine();
					
					String[] split = line.split(" ");
					
					e = Integer.parseInt(split[0]);
					r = Integer.parseInt(split[1]);
					n = Integer.parseInt(split[2]);
					v = new int[n];
					
					line = input.readLine();
					split = line.split(" ");
					
					for(int j=0; j< n; j++)
						v[j] = Integer.parseInt(split[j]);
					 
					long result = calEnergy();
					String decstr = new Long(result).toString();
					
					 String outstr = "Case #"+ new Integer(i+1).toString()+": ";
					 
					 bw.write(outstr+decstr+"\n");
					 System.out.printf("%d\n", i);
				}
				
				input.close();
				bw.close();
	}
}
