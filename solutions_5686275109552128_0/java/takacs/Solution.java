import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution
{	
	int process(int D, ArrayList<Integer> plates)
	{
		int nplates[] = new int[1001];
		for (int p : plates)
			nplates[p]++;
		
		int sum = 0;
		
		boolean needrepeat = true;
		while(needrepeat)
		{
			needrepeat = false;
			
			int max = -1;
			for (int i = nplates.length - 1; i > 0; i--)
			{
				if (nplates[i] != 0)
				{
					max = i;
					break;
				}
			}
			
			int maxthr = (max / 2) + (max % 2);
			int nshare = 0;
			for (int i = max; i > 0; i--)
			{
				nshare += nplates[i];
				int win = max - (i - 1);
				if (win > max - maxthr) win = max - maxthr;
					
				if (nshare < win)
				{
					needrepeat = true;
					sum += nshare;
					
					for (int j = max; j >= i; j--)
					{
						for (int k = 0; k < nplates[j]; k++)
						{
							nplates[j / 2]++;
							nplates[j / 2 + j % 2]++;
						}
						nplates[j] = 0;
					}
					break;
				}
			}
			
			if (!needrepeat)
			{
				sum += max;
			}
		}
		
		return sum;
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
			int D = -1;
			line = reader.readLine();
			tokenizer = new StringTokenizer(line);
			D = Integer.parseInt(tokenizer.nextToken());
			
			ArrayList<Integer> plates = new ArrayList<Integer>(); 

			line = reader.readLine();
			tokenizer = new StringTokenizer(line);
			for (int i = 0; i < D; i++)
			{
				plates.add(Integer.parseInt(tokenizer.nextToken()));
			}

			int result = this.process(D, plates);
			
			System.out.print(result + ": ");
			for (int i = 0; i < plates.size(); i++)
			{
				System.out.print(plates.get(i) + " ");
			}
			System.out.println();
			
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
