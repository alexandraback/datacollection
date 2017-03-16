package marro.jp;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigDecimal;
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
			//reader = new FileReader("C:\\Users\\yhirota\\Desktop\\C-large-1.in");
			reader = new FileReader("C:\\Users\\yhirota\\Desktop\\A-small-attempt0.in");
			br = new BufferedReader(reader);
			
			//writer = new FileWriter("C:\\Users\\yhirota\\Desktop\\C-large-1-output.txt");
			writer = new FileWriter("C:\\Users\\yhirota\\Desktop\\A-small-attempt0.out");
			
			String line;
			int numCases = Integer.parseInt(br.readLine());
			for(int i=0; i<numCases; i++)
			{
				line = br.readLine();
				StringTokenizer st = new StringTokenizer(line);
				String name = st.nextToken();
				int n = Integer.parseInt(st.nextToken());
				
				int nCount = 0;
				int start = 0;
				int nValue = 0;
				for(int j= 0; j<name.length(); j++)
				{
					if(!(name.charAt(j) == 'a' || name.charAt(j) == 'i' || name.charAt(j) == 'u' || name.charAt(j) == 'e' || name.charAt(j) == 'o'))
					{
						nCount++;
					}
					else
					{
						nCount = 0;
					}
					
					
					if(nCount == n)
					{
						int before = j + 1 - n - start;
						int after = name.length() - 1 - j;
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
