import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Solution
{	
	int process(int X, int R, int C)
	{	
		if ((R * C) % X != 0) return 1;
		
		if ((X == 1) || (X == 2) )
		{
			return 0;
		}
		else if (X == 3)
		{
			if (R == 1) return 1;
			if (C == 1) return 1;
			return 0;
		}
		else if (X == 4)
		{
			if (R == 1) return 1;
			if (C == 1) return 1;
			if (R == 2) return 1;
			if (C == 2) return 1;
			return 0;
		}
		else if (X == 5)
		{
			if (R == 1) return 1;
			if (C == 1) return 1;
			if (R == 2) return 1;
			if (C == 2) return 1;
			
			if (C == 3)
			{
				if (R == 5) return 1;
				if (R >= 10) return 0;
			}
			if (R == 3)
			{
				if (C == 5) return 1;
				if (C >= 10) return 0;
			}
			return 0;
		}
		else if (X == 6)
		{
			if (R == 1) return 1;
			if (C == 1) return 1;
			if (R == 2) return 1;
			if (C == 2) return 1;
			if (R == 3) return 1;
			if (C == 3) return 1;
			return 0;
		}
		else if (X >= 7)
		{
			return 1;
		}
		
		return 0;
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
			int X, R, C;
			line = reader.readLine();
			tokenizer = new StringTokenizer(line);
			X = Integer.parseInt(tokenizer.nextToken());
			R = Integer.parseInt(tokenizer.nextToken());
			C = Integer.parseInt(tokenizer.nextToken());
			
			int result = this.process(X, R, C);
			
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
			String resstr = "GABRIEL";
			if (result > 0) resstr = "RICHARD";			
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
