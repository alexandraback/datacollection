import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;


public class Question2 
{
	
	public static void main(String[] args)
	{
		
		StringMatch("C:\\CodeJam\\Round1\\B-small-attempt0.in");
	}

	public static void StringMatch(String filePath)
	{
		try 
		{
			BufferedReader bufferedReader = new BufferedReader(new FileReader(filePath));
	
			boolean firstline = true;
			int testCases  = 0;

			testCases = Integer.parseInt(bufferedReader.readLine());
			int caseNo = 1;

			while (caseNo<=testCases) 
			{
				String line = bufferedReader.readLine();
				StringTokenizer st = new StringTokenizer(line);
				
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				int k = Integer.parseInt(st.nextToken());
				
				int ops = 0;
				
				for(int i=0; i<a; i++)
				{
					for(int j=0; j<b; j++)
					{
						int val = i&j;
						if(val<k)
							ops++;
					}
				}
				
				System.out.println("Case #"+caseNo+": "+ops);
				
				caseNo++;
			}

		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		} 
	}




}
