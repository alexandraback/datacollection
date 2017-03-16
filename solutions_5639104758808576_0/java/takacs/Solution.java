import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Solution
{
	int process(int maxshy, int[] shyness)
	{
		int standing = shyness[0];
		int nfriend = 0;
		
		for (int i = 1; i < shyness.length; i++)
		{
			if (shyness[i] > 0)
			{
				int diff = i - standing;
				if (diff > 0)
				{
					nfriend += diff;
					standing += diff;
				}
				standing += shyness[i];
			}
		}
		
		return nfriend;	
	}
	
	private void execute(String filename) throws Exception
	{
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		String line = null;
		StringTokenizer tokenizer = null;

		line = reader.readLine();
		int nExamples = Integer.parseInt(line);

		int[] results = new int[nExamples];

		for (int k = 0; k < nExamples; k++)
		{
			line = reader.readLine();
			
			int maxshy = -1;
			tokenizer = new StringTokenizer(line);
			maxshy = Integer.parseInt(tokenizer.nextToken());
			
			int[] shyness = new int[maxshy + 1];
			
			String shystr = tokenizer.nextToken();
			
			for (int i = 0; i < maxshy + 1; i++)
			{
				shyness[i] = Character.getNumericValue(shystr.charAt(i));
			}

			int result = this.process(maxshy, shyness);

			results[k] = result;
		}

		// Write result
		this.writeResult(results, filename + ".out");

		// Close
		reader.close();
	}
	
	private void writeResult(int[] results, String filename) throws IOException
	{
		BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
		for (int k = 0; k < results.length; k++)
		{
			int index = k + 1;
			int result = results[k];
			String resstr = Integer.toString(result);
			writer.write("Case #" + index + ": " + resstr + "\r\n");
		}
		writer.flush();
		writer.close();
	}
	
	public static void main(String[] args) throws Exception
	{
		Solution solution = new Solution();
		solution.execute(args[0]);
	}	
}
