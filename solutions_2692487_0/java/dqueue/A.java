import java.util.*;
import java.io.*;

public class A
{

	public static void main(String[] args) throws Exception 
	{
		File infile = new File("C:\\Users\\dq\\workspace\\CJ1B\\src\\A-small-attempt1.in");
		File outfile = new File("C:\\Users\\dq\\workspace\\CJ1B\\src\\A-output.txt");
		BufferedReader br = new BufferedReader(new FileReader(infile));
		BufferedWriter bw = new BufferedWriter(new FileWriter(outfile));
		String s;
		String[] splits;
		int cases = Integer.parseInt(br.readLine());
		for(int i = 0; i < cases; i++)
		{
			bw.write("Case #" + (i+1) + ": ");
			s = br.readLine();
			splits = s.split(" ");
			int A = Integer.parseInt(splits[0]);
			int N = Integer.parseInt(splits[1]);
			ArrayList<Integer> motes = new ArrayList<Integer>();
			s = br.readLine();
			splits = s.split(" ");
			for(int j = 0; j < N; j++)
			{
				motes.add(Integer.parseInt(splits[j]));
			}
			Collections.sort(motes);
			
			int feeds = 0;
			int best = N;
			
			for(int j = 0; j < N; j++)
			{
				if(A == 1)
				{
					feeds = 9999999;
					break;
				}
				if(A > motes.get(j))
					A += motes.get(j);
				else
				{
					if(feeds + N - j < best)
						best = feeds + N - j;
					while(A <= motes.get(j))
					{
						feeds++;
						A += A - 1;
					}
					A += motes.get(j);
				}
			}
			
			//WRITE ANSWER HERE
			bw.write("" + (best > feeds ? feeds : best));
			if((i + 1) < cases)
			{
				bw.write("\n");
			}
		}
		bw.flush();
	}

}
