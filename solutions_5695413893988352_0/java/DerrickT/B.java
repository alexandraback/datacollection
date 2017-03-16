import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class B
{
	static String FILE_IN = "B-small-attempt4.in";
	static String FILE_OUT = "B.out";

	static boolean canMake(String s, int n, String format)
	{
		int l = s.length();

		String sn = String.format(format, n);

		for (int i = 0; i < l; i++)
		{
			char c = s.charAt(i);
			if (c != '?')
				if (sn.charAt(i) != c)
					return false;
		}

		return true;
	}

	static String solve(BufferedReader in) throws IOException
	{
		StringTokenizer st = new StringTokenizer(in.readLine());

		String A = st.nextToken();
		String B = st.nextToken();

		int l = A.length();

		ArrayList<Integer> al = new ArrayList<Integer>();
		ArrayList<Integer> bl = new ArrayList<Integer>();

		int max = (int) Math.pow(10, l) - 1;
		String format = "%0" + l + "d";

		for (int i = 0; i <= max; i++)
		{
			if (canMake(A, i, format))
				al.add(i);
			if (canMake(B, i, format))
				bl.add(i);
		}

		int minD = Integer.MAX_VALUE;
		int minA = 0, minB = 0;

		int as = al.size();
		int bs = bl.size();

		for (int i = 0; i < as; i++)
		{
			for (int j = 0; j < bs; j++)
			{
				int curA = al.get(i);
				int curB = bl.get(j);
				int diff = Math.abs(curA - curB);

				if (diff <= minD)
				{
					if (diff < minD)
					{
						minD = diff;
						minA = curA;
						minB = curB;
					}
					else
					{
						if (curA == minA)
						{
							if (curB < minB)
							{
								minD = diff;
								minA = curA;
								minB = curB;
							}
						}
						else if (curA < minA)
						{
							minD = diff;
							minA = curA;
							minB = curB;
						}
					}
				}
			}
		}

		return String.format(format + " " + format, minA, minB);
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
