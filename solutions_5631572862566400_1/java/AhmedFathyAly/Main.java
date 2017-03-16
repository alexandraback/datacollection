import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main
{

	/* IO */
	InputReader in;
	StringTokenizer tok;
	StringBuilder ans;
	private int n;
	private int[] next;
	private int max;
	private boolean[] found;
	private int[] level;
	private int maxCycleSize;
	private boolean[] cycle;
	private boolean[] couple;
	private boolean[] hated;
	private int[] maxInto;
	private boolean[] done;
	int gloabalOssama = 0;
	int ossama[];

	/* FIELDS */

	public static void main(String[] args) throws Exception
	{
		Main sol = new Main();
		sol.begin();

	}

	private void begin() throws IOException
	{
		// io
		boolean file = true;
		if (file)
			in = new InputReader(new FileInputStream("C-large.in"));
		else
			in = new InputReader(System.in);
		ans = new StringBuilder();

		// read
		int nCases = in.nextInt();
		for (int cas = 1; cas <= nCases; cas++)
		{
			System.out.println(cas);
			n = in.nextInt();
			next = new int[n];
			hated = new boolean[n];
			Arrays.fill(hated, true);
			for (int i = 0; i < n; i++)
			{
				next[i] = in.nextInt() - 1;
				hated[next[i]] = false;
			}

			ans.append("Case #" + cas + ": ");
			ans.append(solve());
			ans.append("\n");
		}

		// output
		System.out.println("\nOutput: ");
		System.out.println(ans.toString());
		BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
		out.write(ans.toString());
		out.close();

	}

	private int solve()
	{
		// remove cycles
		found = new boolean[n];
		level = new int[n];
		cycle = new boolean[n];
		ossama = new int[n];
		maxCycleSize = 0;
		for (int i = 0; i < n; i++)
			if (!found[i])
			{
				gloabalOssama++;
				found[i] = true;
				level[i] = 0;
				ossama[i] = gloabalOssama;
				dfs(i);
			}

		// detect couples
		couple = new boolean[n];
		for (int i = 0; i < n; i++)
			if (next[next[i]] == i)
			{
				couple[i] = true;
				couple[next[i]] = true;
			}

		// path from hated to couples
		maxInto = new int[n];
		for (int i = 0; i < n; i++)
			if (hated[i])
				goToACouple(i);

		done = new boolean[n];
		int count = 0;
		for (int i = 0; i < n; i++)
			if (couple[i])
			{
				int l = i;
				int r = next[i];
				if (done[r] || done[l])
					continue;

				done[l] = true;
				done[r] = true;
				int length = 2 + maxInto[l] + maxInto[r];
				count += length;
			}

		return Math.max(count, maxCycleSize);

	}

	private void goToACouple(int node)
	{
		int count = 0;
		while (!couple[node])
		{
			if (cycle[node])
				return;
			node = next[node];
			count++;
		}

		maxInto[node] = Math.max(maxInto[node], count);

	}

	private void dfs(int node)
	{
		if (found[next[node]])
		{
			if (ossama[next[node]] == gloabalOssama)
			{
				int cycleLength = level[node] - level[next[node]] + 1;
				maxCycleSize = Math.max(maxCycleSize, cycleLength);
				if (cycleLength > 2)
					removeCycle(node);
			}
		} else
		{
			found[next[node]] = true;
			level[next[node]] = level[node] + 1;
			ossama[next[node]] = gloabalOssama;
			dfs(next[node]);
		}

	}

	private void removeCycle(int node)
	{
		int source = node;
		do
		{
			cycle[node] = true;
			node = next[node];
		} while (node != source);
	}

}

class InputReader
{
	BufferedReader reader;
	StringTokenizer tok;

	public InputReader(InputStream stream)
	{
		reader = new BufferedReader(new InputStreamReader(stream), 32768);
		tok = new StringTokenizer("");
	}

	public String next()
	{
		while (!tok.hasMoreTokens())
			try
			{
				tok = new StringTokenizer(reader.readLine());
			} catch (IOException e)
			{
				e.printStackTrace();
			}
		return tok.nextToken();
	}

	public int nextInt()
	{
		return Integer.parseInt(next());
	}
}