import java.util.*;
import java.io.*;

public class CJ2B
{
	public static int search(int E, int EMax, int R, int N, int[] gain, int cur, int curGain)
	{
		if (cur == N-1)
		{
			//System.out.println("curgain:" + curGain + " E:" + E);
			return curGain + E * gain[cur];
		}
		int max = 0;
		int val;
		for (int i = 0; i <= E; i++)
		{
			val = search(((E - i + R) > EMax ? EMax : (E - i + R)), EMax, R, N, gain, cur + 1, curGain + i * gain[cur]);
			if (val > max)
				max = val;
		}
		return max;
	}

	public static void main(String[] args) throws Exception 
	{
		File infile = new File("/Users/dennisqin/Downloads/CodeJam/B-small-attempt0.in.txt");
		File outfile = new File("/Users/dennisqin/Downloads/CodeJam/outputB.txt");
		BufferedReader br = new BufferedReader(new FileReader(infile));
		BufferedWriter bw = new BufferedWriter(new FileWriter(outfile));
		String s;
		int cases = Integer.parseInt(br.readLine());
		for(int i = 0; i < cases; i++)
		{
			s = br.readLine();
			String[] splits = s.split(" ");
			int E = Integer.parseInt(splits[0]);
			int R = Integer.parseInt(splits[1]);
			int N = Integer.parseInt(splits[2]);
			int[] gain = new int[N];
			s = br.readLine();
			splits = s.split(" ");
			for(int j = 0; j < N; j++)
			{
				gain[j] = Integer.parseInt(splits[j]);
			}

			int val = search(E, E, R, N, gain, 0, 0);
			
			bw.write("Case #" + (i+1) + ": " + val);
			if((i + 1) < cases)
			{
				bw.write("\n");
			}
			bw.flush();
		}
	}

}