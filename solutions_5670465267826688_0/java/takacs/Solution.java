import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Solution
{	
	private boolean plus[] = new boolean[3];
	private int state[] = new int[3];
	
	private final int S1 = 1;
	private final int Si = 2;
	private final int Sj = 3;
	private final int Sk = 4;
	
	
	void nextState(int index, char ch)
	{
		switch(state[index])
		{
			case S1:
				switch (ch)
				{
					case 'i':
						state[index] = Si;
						break;
					case 'j':
						state[index] = Sj;
						break;
					case 'k':
						state[index] = Sk;
						break;
				}
				break;
			case Si:
				switch (ch)
				{
					case 'i':
						state[index] = S1;
						plus[index] = !plus[index];
						break;
					case 'j':
						state[index] = Sk;
						break;
					case 'k':
						state[index] = Sj;
						plus[index] = !plus[index];
						break;
				}
				break;
			case Sj:
				switch (ch)
				{
					case 'i':
						state[index] = Sk;
						plus[index] = !plus[index];
						break;
					case 'j':
						state[index] = S1;
						plus[index] = !plus[index];
						break;
					case 'k':
						state[index] = Si;
						break;
				}
				break;
			case Sk:
				switch (ch)
				{
					case 'i':
						state[index] = Sj;
						break;
					case 'j':
						state[index] = Si;
						plus[index] = !plus[index];
						break;
					case 'k':
						state[index] = S1;
						plus[index] = !plus[index];
						break;
				}
				break;
		}
	}
	
	int process(int N, String input)
	{
		state[0] = 1;
		plus[0] = true;
		
		for (int i = 0; i < N - 2; i++)
		{
			char ch0 = input.charAt(i);
			nextState(0, ch0);
			
			if ( (state[0] == Si) && (plus[0]) )
			{
				state[1] = 1;
				plus[1] = true;
				
				for (int j = i + 1; j < N - 1; j++)
				{
					char ch1 = input.charAt(j);
					nextState(1, ch1);
					if ( (state[1] == Sj) && (plus[1]) )
					{
						state[2] = 1;
						plus[2] = true;
						
						for (int k = j + 1; k < N; k++)
						{
							char ch2 = input.charAt(k);
							nextState(2, ch2);
						}
						
						if ( (state[2] == Sk) && (plus[2]) )
						{
							return 1;
						}
					}
				}
			}
		}	
		
		return -1;
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
			System.out.print(k + 1);
			
			int L, R, N;
			line = reader.readLine();
			tokenizer = new StringTokenizer(line);
			L = Integer.parseInt(tokenizer.nextToken());
			R = Integer.parseInt(tokenizer.nextToken());
			N = L * R;
			
			String seq = reader.readLine();
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < R; i++)
			{
				sb.append(seq);
			}

			System.out.print(" started...");
			
			int result = this.process(N, sb.toString());
			
			System.out.println("OK");
			
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
			String resstr = "NO";
			if (result > 0) resstr = "YES";			
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
