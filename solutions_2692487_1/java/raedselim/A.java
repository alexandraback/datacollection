import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {

	/**
	 * @param args
	 * @throws IOException
	 * @throws NumberFormatException
	 */
	static int[] m = new int[150];
	static int[] grow = new int[150];
	static int N;

	public static void main(String[] args) throws NumberFormatException,
			IOException
	{
		BufferedReader br = new BufferedReader(new FileReader(
				"A-large.in"));
		// BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter p = new PrintWriter("out.txt");
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			long A = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++)
				m[i] = Integer.parseInt(st.nextToken());
			Arrays.sort(m, 0, N);
			Arrays.fill(grow, 0);
			for (int i = 0; i < N; i++)
				if (A <= m[i])
				{
					int steps = 0;
					if (A == 1)
						steps = 1 << 15;
					else
					{
						while (A <= m[i])
						{
							// add
							A = 2 * A - 1;
							steps++;
						}
						A += m[i];
					}
					grow[i] = steps;
				} else
					A += m[i];
			int op = 1 << 25;
			int g = 0;
			for (int i = 0; i <= N; i++)
			{
				op =  Math.min(g+N-i, op);
				g += grow[i];
			}
			p.println("Case #" + t + ": " + op);
		}
		p.close();
	}
}
