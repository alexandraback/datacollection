import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class CCodeJam
{
	public static boolean isP(int x)
	{
		char[] s = (x + "").toCharArray();
		for (int i = 0, j = s.length - 1; i < j; i++, j--)
			if (s[i] != s[j])
				return false;
		return true;
	}

	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner in = new Scanner(new File("D:\\D\\C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("D:\\D\\output.txt"));
		int t = in.nextInt();
		for (int tc = 1; tc <= t; tc++)
		{
			int A = in.nextInt(), B = in.nextInt();
			int a = (int) Math.sqrt(A), b = (int) Math.sqrt(B);
			int res = 0;
			for (int i = a; i <= b; i++)
				if (isP(i) && i * i >= A && i * i <= B && isP(i * i))
					res++;
			out.printf("Case #%d: %d", tc, res);
			out.println();
		}
		out.close();

	}
}
