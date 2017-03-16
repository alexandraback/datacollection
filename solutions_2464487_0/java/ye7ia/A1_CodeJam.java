import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A1_CodeJam
{
	public static void main(String[] args) throws FileNotFoundException
	{
Scanner in = new Scanner(new File("D:\\D\\A-small-attempt0 (1).in"));
	PrintWriter out = new PrintWriter(new File("D:\\D\\output.txt"));
//	Scanner in = new Scanner(System.in);
	//	PrintWriter out = new PrintWriter(System.out);
		int ttc = in.nextInt();
		for (int tc = 1; tc <= ttc; tc++)
		{
			long r = in.nextLong() , t = in.nextLong();
			long ans = 0l;
			while(t - (r + 1) * (r + 1 ) + r * r >= 0)
			{
				ans++;
				t = t - (r + 1) * (r + 1 ) + r * r;
				r += 2;
			}
			out.printf("Case #%d: ", tc);
			out.println(ans);
		}
		out.close();

	}
}
