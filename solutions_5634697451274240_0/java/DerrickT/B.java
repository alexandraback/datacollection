import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class B
{
	static String FILE_IN = "B-small-attempt0.in";
	static String FILE_OUT = "B.out";

	static String solve(BufferedReader in) throws IOException
	{
		char[] pancakes = in.readLine().toCharArray();
		int n = pancakes.length;
		
		int [] a = new int [n--];
	
		for(int i = 0; i <= n; i++)
			a[i] = (pancakes[i] == '+') ?  1 : -1;
		
		int flips = 0;
		while(n >= 0)
		{
			if(a[n] == -1)
			{
				for(int i = n; i >= 0; i--)
					a[i] *= -1; 
				
				flips++;
			}
			n--;
		}
		
		return String.format("%d", flips);
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
