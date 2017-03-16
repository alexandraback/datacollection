package round1a2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ProblemB {
	
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader(new File("src/files/input.txt")));
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File("src/files/output.txt")));
		
		int numcase = Integer.parseInt(br.readLine());
		for(int i=0; i<numcase; i++)
		{
			int numlevels = Integer.parseInt(br.readLine());
			int[][] levelinfo = new int[numlevels][2];
			for(int j=0; j<numlevels; j++)
			{
				String[] vals = br.readLine().split(" ");
				levelinfo[j][0]=Integer.parseInt(vals[0]);
				levelinfo[j][1]=Integer.parseInt(vals[1]);
				
			}
			
			
			
			
			bw.write("Case #"+(i+1)+": ");
			processData(bw,levelinfo);
			bw.newLine();
		}
		
		bw.close();
		
		
	}

	private static void processData(BufferedWriter bw, int[][] levelinfo) throws Exception {
		int numstars =0;
		int numturns =0;
		boolean cantplay=false;
		boolean one;
		while(true)
		{
			cantplay=true;
			one=true;
			int best=-1;
			for(int i=0; i<levelinfo.length; i++)
			{
				if(levelinfo[i][1] == -1)
				{
					continue;
				}
				
				if(levelinfo[i][1] <= numstars)
				{
					if(levelinfo[i][0] != -1)
					{
					numstars+=2;
					}
					else
					{
						numstars++;
					}
					one = false;
					cantplay=false;
					levelinfo[i][1] = -1;
					levelinfo[i][0] = -1;
					break;
				}
				
				if(levelinfo[i][0] != -1 && levelinfo[i][0] <= numstars && (best < 0 || levelinfo[i][1] >= levelinfo[best][1]))
				{
					best =i;
					cantplay=false;
				}
			}
			if(one  &&!cantplay)
			{
				numstars++;
				levelinfo[best][0] = -1;
				
			}
			if(cantplay)
			{
				break;
			}
			numturns++;
			
		}
		
		boolean alldone = true;
		
		for(int i=0; i<levelinfo.length; i++)
		{
			if(levelinfo[i][1] != -1)
			{
				alldone = false;
			}
		}
		
		if(alldone)
		{
			bw.write(numturns+"");
		}
		else
		{
			bw.write("Too Bad");
		}
		
		
	}

}
