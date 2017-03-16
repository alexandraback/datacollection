
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D
{
	static String FILE_IN = "D-large.in";
	static String FILE_OUT = "D.out";

	static String solve(BufferedReader in) throws IOException
	{

		StringTokenizer st = new StringTokenizer(in.readLine());
		int K = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		int S = Integer.parseInt(st.nextToken());

		if (C * S < K)
			return "IMPOSSIBLE";

		int n = 1;
		StringBuilder s = new StringBuilder();

		while(n <= K)
		{
			long open = n;
			for (int i = 1; i < C; i++)
			{
				n++;
				open *= K;
				
				if (n <= K)
					open -= (K - n);
			}
			
			s.append(open).append(" ");
			n++;
		}

		return s.deleteCharAt(s.length() - 1).toString();
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader
				(new FileReader("files/" + FILE_IN));
		PrintWriter out = new PrintWriter(new BufferedWriter
				(new FileWriter("files/" + FILE_OUT)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++)
		{
			String result = solve(in);
			System.out.printf("Case #%d: %s%n", t, result);
			out.printf("Case #%d: %s%n", t, result);
		}

		System.out.println("Complete");
		in.close();
		out.close();
	}
}
