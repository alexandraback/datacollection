import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class A
{
	static String FILE_IN = "A-small-attempt0.in";
	static String FILE_OUT = "A.out";

	static String solve(BufferedReader in) throws IOException
	{
		char[] s = in.readLine().toCharArray();
		StringBuilder res = new StringBuilder();
		
		char first = s[0], next;
		res.append(first);
		
		
		for(int i = 1; i < s.length; i++)
		{
			next = s[i];
			if(next >= first)
			{
				res.insert(0, next);
				first = next;
			}
			else
				res.append(next);
		}
		
		return res.toString();
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
