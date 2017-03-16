import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class C
{
	static String FILE_IN = "C-small-attempt0.in";
	static String FILE_OUT = "C.out";

	static String solve(BufferedReader in) throws IOException
	{
		int n = Integer.parseInt(in.readLine());

		HashSet<String> A = new HashSet<String>();
		HashSet<String> B = new HashSet<String>();

		int dupA = 0;
		int dupB = 0;
		
		StringTokenizer st;
		String a, b;
		for (int i = 0; i < n; i++)
		{
			st = new StringTokenizer(in.readLine());
			
			a = st.nextToken();
			b = st.nextToken();
			
			if(A.contains(a))
				dupA++;
			else
				A.add(a);
			
			if(B.contains(b))
				dupB++;
			else
				B.add(b);
		}

		return String.format("%d", Math.min(dupA, dupB));
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
