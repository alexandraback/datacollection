import java.util.*;
import java.io.*;

class Main
{
	BufferedReader input;
	StringTokenizer token;
	BufferedWriter out;

	void solve() throws IOException
	{
		input = new BufferedReader(new InputStreamReader(System.in));
		out = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = nextInt();
		for(int t = 1; t <= T; t++)
		{
			out.write("Case #" + t + ":");
			out.newLine();
			int N = nextInt();
			int[] s = new int[N];
			for(int i = 0; i < N; i++)
			{
				s[i] = nextInt();
			}
			boolean found = false;
			for(int i = 1; i < (1<<N)-1; i++)
			{
				ArrayList<Integer> A = new ArrayList<Integer>();
				ArrayList<Integer> B = new ArrayList<Integer>();
				for(int j = 0; j < N; j++)
				{
					if( ((1<<j) & i) != 0 ) A.add(s[j]);
						else B.add(s[j]);
				}
				//System.out.println(A);
				//System.out.println(B);
				boolean[] pos = new boolean[2000010];
				boolean[] pos2 = new boolean[2000010];
				int[] m = new int[2000010];
				int[] m2 = new int[2000010];
				int max = 0,max2 = 0;
				pos[0] = true;
				pos2[0] = true;
				for(int k = 0; k < A.size(); k++)
				{
					for(int j = max; j >= 0; j--)if(pos[j])
					{
						int x = A.get(k);
						pos[j+x] = true;
						m[j+x] = m[j] | (1<<k);
						max = Math.max(max,j+x);
					}
				}

				for(int k = 0; k < B.size(); k++)
				{
					for(int j = max2; j >= 0; j--)if(pos2[j])
					{
						int x = B.get(k);
						pos2[j+x] = true;
						m2[j+x] = m2[j] | (1<<k);
						max2 = Math.max(max2,j+x);
					}
				}

				//System.out.println(i+ " "+max+ " "+max2);

				for(int j = Math.min(max,max2); j > 0; j--)
				{
					if(pos[j] && pos2[j])
					{
						found = true;
						int mask = m[j];
						int mask2 = m2[j];
						ArrayList<Integer> ans1 = new ArrayList<Integer>();
						ArrayList<Integer> ans2 = new ArrayList<Integer>();
						for(int k = 0; k < N; k++)
						{
							if( ((1<<k) & mask) != 0 )
							{
								ans1.add(A.get(k));
							}
							if( ((1<<k) & mask2) != 0 )
							{
								ans2.add(B.get(k));
							}
						}
						for(int k = 0; k < ans1.size(); k++)
						{
							out.write(""+ans1.get(k));
							if(k != ans1.size()-1)out.write(" ");
								else out.newLine();
						}
						for(int k = 0; k < ans2.size(); k++)
						{
							out.write(""+ans2.get(k));
							if(k != ans2.size()-1)out.write(" ");
								else out.newLine();
						}
						break;
					}
				}
				if(found)break;
			}
			out.flush();
		}
	}

	int nextInt() throws IOException
	{
		if(token == null || !token.hasMoreTokens())
			token = new StringTokenizer(input.readLine());
		return Integer.parseInt(token.nextToken());
	}

	Long nextLong() throws IOException
	{
		if(token == null || !token.hasMoreTokens())
			token = new StringTokenizer(input.readLine());
		return Long.parseLong(token.nextToken());
	}

	String next() throws IOException
	{
		if(token == null || !token.hasMoreTokens())
			token = new StringTokenizer(input.readLine());
		return token.nextToken();
	}

	public static void main(String[] args) throws Exception
	{
		new Main().solve();
	}
}