package marro.jp;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class Consonants {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		FileReader reader = null;
		BufferedReader br = null;
		
		FileWriter writer = null;
		try
		{
			reader = new FileReader("C:\\Users\\yhirota\\Desktop\\A-large.in");
			//reader = new FileReader("C:\\Users\\yhirota\\Desktop\\A-small-attempt0.in");
			br = new BufferedReader(reader);
			
			writer = new FileWriter("C:\\Users\\yhirota\\Desktop\\A-large.out");
			//writer = new FileWriter("C:\\Users\\yhirota\\Desktop\\A-small-attempt0.out");
			
			String line;
			long numCases = Integer.parseInt(br.readLine());
			for(long i=0; i<numCases; i++)
			{
				line = br.readLine();
				StringTokenizer st = new StringTokenizer(line);
				String name = st.nextToken();
				long n = Integer.parseInt(st.nextToken());
				
				long nCount = 0;
				long start = 0;
				long nValue = 0;
				for(long j= 0; j<name.length(); j++)
				{
					if(!(name.charAt((int)j) == 'a' || name.charAt((int)j) == 'i' || name.charAt((int)j) == 'u' || name.charAt((int)j) == 'e' || name.charAt((int)j) == 'o'))
					{
						nCount++;
					}
					else
					{
						nCount = 0;
					}
					
					
					if(nCount == n)
					{
						long before = j + 1 - n - start;
						long after = name.length() - 1 - j;
						nValue += (before+1)*(after+1);
						nCount--;
						start = j - n + 2;
					}
				
				}
				
				String outStr = "Case #" + (i+1) + ": ";
				outStr += nValue + "\n";
				
				writer.write(outStr);
			}		
		}
		catch(Exception e)
		{
		}
		finally
		{
			try
			{
				if(reader != null)
				{
					reader.close();
					reader = null;
				}
				
				if(br != null)
				{
					br.close();
					br = null;
				}
				
				if(writer != null)
				{
					writer.close();
					writer = null;
				}
				
			}
			catch(Exception e)
			{
				
			}
		}
	}

}
