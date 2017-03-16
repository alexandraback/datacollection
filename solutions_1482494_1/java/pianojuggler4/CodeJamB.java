import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class CodeJamB
{
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		int cases = in.nextInt();
		for(int casenum = 1;casenum <= cases;casenum++)
		{
			int N = in.nextInt();
			
			int count = 0;
			boolean toobad = false;
			
			int stars[][] = new int[N][2];
			int levelsfinished = 0;
			int mystars = 0;
			
			for(int n=0;n<N;n++)
			{
				stars[n][0] = in.nextInt();
				stars[n][1] = in.nextInt();
			}
			
			boolean restart = false;
			
			while(levelsfinished < N)
			{
				restart = false;
				
				for(int n=0;n<N;n++)
				{
					if(stars[n][1] <= mystars && stars[n][1] != -1)
					{
						count++;
						levelsfinished++;
						mystars++;
						stars[n][1] = -1;
						if(stars[n][0] != -1)
						{
							mystars++;
							stars[n][0] = -1;
						}
						restart = true;
						break;
					}
				}
				if(restart)
					continue;
				
				int max = 0;
				int maxindex = -1;
				
				for(int n=0;n<N;n++)
				{
					if(stars[n][0] <= mystars  && stars[n][0] != -1)
					{
						if(stars[n][1] > max)
						{
							max = stars[n][1];
							maxindex = n;
						}
//						count++;
//						mystars++;
//						stars[n][0] = -1;
//						restart = true;
//						break;
					}
				}
				
				if(maxindex != -1)
				{
					count++;
					mystars++;
					stars[maxindex][0] = -1;
					restart = true;
				}
					
				
				if(restart)
					continue;
				
				toobad = true;
				break;
			}
			
			//System.out.println(levelsfinished + "\t" + mystars + "\t" + toobad);
			if(toobad)
			{
				out.write("Case #" + casenum + ": Too Bad\n");
			}
			else
				out.write("Case #" + casenum + ": "+count+"\n");
		}
		in.close();
		out.close();
	}
}