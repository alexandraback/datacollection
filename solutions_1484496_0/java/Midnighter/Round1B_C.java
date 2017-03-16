package midnighter.googlejam.y2012;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Round1B_C
{
	static final String inFileName = "inputs/C-small-attempt0.in";
	static final String outFileName = "outputs/C-small.out";

	public String oneCase()
	{
		int N = in.nextInt();
		int s[] = new int[N];
		int max[] = new int[100000 * 20];
		List<Integer> contrs[] = new ArrayList[100000 * 20];

		Arrays.fill(max, -1);

		for (int i = 0; i < N; i++)
			s[i] = in.nextInt();

		Arrays.sort(s);

		List<Integer> sums = new ArrayList<Integer>();

		for (int i = 0; i < N; i++)
		{
			sums.add(s[i]);
			contrs[s[i]] = new ArrayList<Integer>();
			contrs[s[i]].add(i);
			max[s[i]] = i;
		}

		for (int l = 0; l < N/2 + 1; l++)
			for (int i = 0; i < sums.size(); i++)
			{
				int sum = sums.get(i);
				for (int k = max[sum] + 1; k < N; k++)
				{
					int nSum = sum + s[k];
					if (max[nSum] != -1 && k < max[nSum])
					{
						String res = "\n";
						StringBuffer str = new StringBuffer();
						for (int j = 0; j < contrs[nSum].size(); j++)
							str.append("" + s[contrs[nSum].get(j)] + " ");
						res += str.toString().trim() + "\n";
						str = new StringBuffer();
						for (int j = 0; j < contrs[sum].size(); j++)
							str.append("" + s[contrs[sum].get(j)] + " ");
						str.append("" + s[k]);
						res += str.toString();
						return res;
					}
					else
					{
						max[nSum] = k;
						contrs[nSum] = new ArrayList<Integer>();
						contrs[nSum].addAll(contrs[sum]);
						contrs[nSum].add(k);
						sums.add(nSum);
					}
				}
			}

		return "\nImpossible";
	}

	public void run() throws Exception
	{
		in = new Scanner(new FileReader(inFileName));
		out = new PrintWriter(new FileWriter(outFileName));

		int nCases = in.nextInt();
		for (int c = 1; c <= nCases; c++)
			out.println("Case #" + c + ": " + oneCase());

		out.flush();
		out.close();
		in.close();
	}

	public static void main(String[] args) throws Exception
	{
		new Round1B_C().run();
	}

	Scanner in;
	PrintWriter out;
}
